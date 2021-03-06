#include "pnsimp.h"
#include "hype_pinit.h"

#include <HostLink.h>
#include <POLite.h>
#include <assert.h>
#include <sys/time.h>
#include <config.h>

#define XBOXES 1
#define YBOXES 1

#define DEFAULT_NUM_DEVS 100
#define DEFAULT_TIME_LIMIT 10000
#define TIME_LIMIT_TOTAL 2
#define SEED 12345L

int main(int argc, char**argv)
{
	if(strcmp(TMAP_NAME, PINIT_NAME)) {
		printf("TMAP_NAME!=PINIT_NAME");
		exit(1);
	}
	printf("net: %s\n", TMAP_NAME);
	
	uint32_t numDevs = DEFAULT_NUM_DEVS;
	if(argc>1) {
		numDevs = atoi(argv[1]);
	}
	printf("numDevs: %u (total places: %.2lfM)\n", numDevs, (double)(numDevs*(localPlaces+outPlaces/2))/1.0e6);
	
	#if (TIME_LIMIT_TOTAL==2)
		uint64_t timeLimitPerDev = DEFAULT_TIME_LIMIT;
		if(argc>2) {
			timeLimitPerDev = atol(argv[2]);
		}
		uint64_t timeLimit = timeLimitPerDev*numDevs;
		uint64_t timeLimitRemainder = 0;
	#elif (TIME_LIMIT_TOTAL==1)
		uint64_t timeLimit = DEFAULT_TIME_LIMIT;
		if(argc>2) {
			timeLimit = atol(argv[2]);
		}
		uint64_t timeLimitPerDev = timeLimit / numDevs;
		uint64_t timeLimitRemainder = timeLimit - timeLimitPerDev*numDevs;
	#else
		uint64_t timeLimitPerDev = DEFAULT_TIME_LIMIT;
		if(argc>2) {
			timeLimitPerDev = atol(argv[2]);
		}
		timeLimitPerDev *= (uint64_t)transitions;
		uint64_t timeLimit = timeLimitPerDev*numDevs;
		uint64_t timeLimitRemainder = 0;
	#endif
	#if TIME_TRANSITIONS
		printf("timeLimit: %lu (%lu/dev, %lu/tran)\n", timeLimit, timeLimitPerDev, timeLimitPerDev/(uint64_t)transitions);
	#else
		printf("timeLimit: %lu/dev\n", timeLimitPerDev);
	#endif

	printf("UNFOLD_FOR_INOUT=%d; RANDOM_MODE=%d; INTERLEAVING_SEMANTIC=%d\n", UNFOLD_FOR_INOUT, RANDOM_MODE, INTERLEAVING_SEMANTIC);

	struct timeval startAll, finishAll;
	gettimeofday(&startAll, NULL);

	printf("Creating graph...\n");
	PGraph<PNDevice, PNState, None, PNMessage> graph(XBOXES, YBOXES);
	for(uint32_t i=0; i<numDevs; i++) {
		PDeviceId id = graph.newDevice();
		assert(i == id);
	}
	
	for(uint32_t i=0; i<numDevs; i++) {
		graph.addEdge(i, 0, i>0 ? i-1 : numDevs-1);
		graph.addEdge(i, 0, i<numDevs-1 ? i+1 : 0);
	}

	printf("Creating host link (%dx%d)...\n", XBOXES, YBOXES);
	HostLink hostLink(XBOXES, YBOXES);

	// export POLITE_PLACER=direct
	printf("Placer: %s\n", getenv("POLITE_PLACER"));

	printf("Mapping...\n");
	graph.mapVerticesToDRAM = true;
	// graph.mapEdgesToDRAM = true;
	graph.map(); // TODO: manually

	uint64_t seed = SEED;
	for(uint32_t i=0; i<numDevs; i++) {
		PNState* dev = &graph.devices[i]->state;
		dev->dev = i;
		seed = (seed * 0x5DEECE66DLL + 0xBLL) & ((1LL << 48LL) - 1LL);
		dev->seed = seed + (i*23);
		dev->timeLimit = timeLimitPerDev + (i<timeLimitRemainder ? 1 : 0);
		for(uint16_t p=0; p<localPlaces+outPlaces; p++) {
			if(p<localPlaces)
				dev->places[p] = initPlaces[p%tileInitPlaces];
			else
				dev->places[p] = 0;
		}
		
		uint32_t prev = i>0 ? i-1 : numDevs-1;
		uint32_t next = i<numDevs-1 ? i+1 : 0;
		for(uint16_t p=0; p<outPlaces; p++) {
			dev->outMap[p].dev = tOutMap[p].dev==1 ? next : prev;
			dev->outMap[p].place = tOutMap[p].place;
		}
	}

	graph.write(&hostLink);

	hostLink.boot("code.v", "data.v");
	hostLink.go();

	printf("\nStarted\n");
	struct timeval startCompute, finishCompute;
	gettimeofday(&startCompute, NULL);

	politeSaveStats(&hostLink, "stats.txt");

	uint64_t countFired = 0;
	for(uint32_t i = 0; i < graph.numDevices; i++) {
		PMessage<PNMessage> msg;
		hostLink.recvMsg(&msg, sizeof(msg));
		if(i == 0)
			gettimeofday(&finishCompute, NULL);
		countFired += (uint64_t)msg.payload.dev + ((uint64_t)msg.payload.place << 32L);
	}
	printf("Total transitions fired: %lu\n", countFired);

	struct timeval diff;
	double duration;
	timersub(&finishCompute, &startCompute, &diff);
	duration = (double) diff.tv_sec + (double) diff.tv_usec / 1000000.0;
	printf("Time (compute) = %lf\n", duration);
	gettimeofday(&finishAll, NULL);
	timersub(&finishAll, &startAll, &diff);
	duration = (double) diff.tv_sec + (double) diff.tv_usec / 1000000.0;
	printf("Time (all) = %lf\n", duration);

	return 0;
}
