#include "ppn.h"

#include <HostLink.h>
#include <POLite.h>
#include <assert.h>
#include <sys/time.h>
#include <config.h>

#define DEFAULT_NUM_DEVS 100
#define DEFAULT_TIME_LIMIT 10000
#define TIME_LIMIT_TOTAL 0

#define WATCH_PLACE 0
#define SHOW_RESULTS 0

const uint8_t initPlaces[MAX_PLACES] = {
	1, 1, 0, 0, 0, 1, 1, 0, 0
};
const uint16_t tileInitPlaces = 9;

int main(int argc, char**argv)
{
	uint32_t numDevs = DEFAULT_NUM_DEVS;
	if(argc>1) {
		numDevs = atoi(argv[1]);
	}
	printf("numDevs: %u (total places: %.2lfM)\n", numDevs, (double)(numDevs*(localPlaces+outPlaces/2))/1.0e6);
	
	#if TIME_LIMIT_TOTAL
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
	printf("timeLimit: %lu (%lu/dev, %lu/tran)\n", timeLimit, timeLimitPerDev, timeLimitPerDev/(uint64_t)transitions);

	struct timeval startAll, finishAll;
	gettimeofday(&startAll, NULL);

	printf("Creating graph...\n");
	PGraph<PPNDevice, PPNState, None, PPNMessage> graph;
	for(uint32_t i=0; i<numDevs; i++) {
		PDeviceId id = graph.newDevice();
		assert(i == id);
	}
	
	for(uint32_t i=0; i<numDevs; i++) {
		graph.addEdge(i, 0, i>0 ? i-1 : numDevs-1);
		graph.addEdge(i, 0, i<numDevs-1 ? i+1 : 0);
	}

	printf("Creating host link...\n");
	HostLink hostLink;

	printf("Mapping...\n");
	graph.mapVerticesToDRAM = true;
	// graph.mapEdgesToDRAM = true;
	graph.map(); // TODO: manually

	for(uint32_t i=0; i<numDevs; i++) {
		PPNState* dev = &graph.devices[i]->state;
		dev->dev = i;
		dev->timeLimit = timeLimitPerDev + (i<timeLimitRemainder ? 1 : 0);
		dev->watchPlace = WATCH_PLACE;
		//memcpy(dev->places, initPlaces, sizeof(initPlaces));
		for(uint16_t i=0; i<MAX_PLACES; i++) {
			if(i<localPlaces)
				dev->places[i] = initPlaces[i%tileInitPlaces];
			else
				dev->places[i] = 0;
		}
		
		dev->outMap[0].dev = i<numDevs-1 ? i+1 : 0;
		dev->outMap[0].place = localPlaces+2;
		dev->outMap[1].dev = i<numDevs-1 ? i+1 : 0;
		dev->outMap[1].place = localPlaces+3;
		dev->outMap[2].dev = i>0 ? i-1 : numDevs-1;
		dev->outMap[2].place = localPlaces+0;
		dev->outMap[2].dev = i>0 ? i-1 : numDevs-1;
		dev->outMap[2].place = localPlaces+1;
	}

	graph.write(&hostLink);

	hostLink.boot("code.v", "data.v");
	hostLink.go();

	printf("\nStarted\n");
	struct timeval startCompute, finishCompute;
	gettimeofday(&startCompute, NULL);

	politeSaveStats(&hostLink, "stats.txt");

	for(uint32_t i = 0; i < graph.numDevices; i++) {
		PMessage<PPNMessage> msg;
		hostLink.recvMsg(&msg, sizeof(msg));
		if(i == 0) {
			gettimeofday(&finishCompute, NULL);
			printf("%d steps, place[%d]=%d\n", msg.payload.dev, WATCH_PLACE, msg.payload.st);
		}
		#if SHOW_RESULTS
			printf("%d: %d\n", msg.payload.dev, msg.payload.st);
		#endif
	}

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
