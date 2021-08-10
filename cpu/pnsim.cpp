#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "pnsim.h"

/*
#define TMAP_NAME "DPHIL"

#if (MAX_TRANS_CONNECTS<4)
#error "not enough connectivity in Transition"
#endif

const uint16_t tileInitPlaces = 20;
const uint8_t initPlaces[tileInitPlaces] = {0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0};

void generateTMap(uint32_t steps) {
	numPlaces = steps*20;
	transitions = steps*12;
	tmap = new Transition[transitions];

	uint32_t offs = 0;
	uint32_t p = 0;
	for(uint32_t s = 0; s<steps; s++) {
		tmap[offs++] = {0x22, p+4, p+1, (s>0 ? p-20 : (steps-1)*20) + 15, (s>0 ? p-20 : (steps-1)*20) + 17}; // 0: ccw_take_left_fork *choice
		tmap[offs++] = {0x22, p+4, p+12, p+9, p+5}; // 1: take_right_fork *choice
		tmap[offs++] = {0x21, p+0, p+1, p+4}; // 2: ccw_put_left_fork
		tmap[offs++] = {0x21, p+10, p+11, p+3}; // 3: put_left_fork

		tmap[offs++] = {0x31, p+7, p+10, p+2, p+8}; // 4: start_thinking
		tmap[offs++] = {0x13, p+9, p+6, p+8, p+7}; // 5: start_eating
		tmap[offs++] = {0x21, p+2, p+4, p+12}; // 6: put_right_fork
		tmap[offs++] = {0x31, p+13, (s<steps-1 ? p+20 : 0) + 0, p+18, p+14}; // 7: cw_start_thinking

		tmap[offs++] = {0x13, p+11, p+3, p+5, p+6}; // 8: take_left_fork *choice
		tmap[offs++] = {0x13, p+11, p+16, p+17, p+19}; // 9: cw_take_right_fork *choice
		tmap[offs++] = {0x21, p+18, p+16, p+11}; // 10: cw_put_right_fork
		tmap[offs++] = {0x13, p+14, p+19, p+15, p+13}; // 11: cw_start_eating

		p += 20;
	}
}
*/

#define TMAP_NAME "PIPE"

#if (MAX_TRANS_CONNECTS<6)
#error "not enough connectivity in Transition"
#endif

const uint16_t tileInitPlaces = 22;
const uint8_t initPlaces[tileInitPlaces] = {1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0};

void generateTMap(uint32_t steps) {
	numPlaces = steps*22;
	transitions = steps*10;
	tmap = new Transition[transitions];

	uint32_t offs = 0;
	uint32_t p = 0;
	for(uint32_t s = 0; s<steps; s++) {
		tmap[offs++] = {0x33, p+8, p+10, p+14, p+12, p+11, p+9}; // 0: t4
		tmap[offs++] = {0x33, p+11, p+16, p+18, p+14, p+13, p+15}; // 1: t5
		tmap[offs++] = {0x22, p+13, p+19, p+16, p+17}; // 2: t6
		tmap[offs++] = {0x22, p+17, p+1, (s<steps-1 ? p+22 : 0) + 0, p+19}; // 3: t7
		tmap[offs++] = {0x22, p+15, p+20, p+18, p+21}; // 4: t8
		tmap[offs++] = {0x22, p+21, p+3, (s<steps-1 ? p+22 : 0) + 2, p+20}; // 5: t9
		tmap[offs++] = {0x22, p+0, p+5, p+4, (s>0 ? p-22 : (steps-1)*22) + 1}; // 6: t0
		tmap[offs++] = {0x22, p+4, p+9, p+5, p+8}; // 7: t1
		tmap[offs++] = {0x22, p+2, p+7, p+6, (s>0 ? p-22 : (steps-1)*22) + 3}; // 8: t2
		tmap[offs++] = {0x22, p+6, p+12, p+10, p+7}; // 9: t3
		p += 22;
	}
}

void printTMap() {
	for(uint32_t ti=0; ti<transitions; ti++) {
		const Transition* t = &tmap[ti];
		printf("{0x%02x, %d, %d, %d, %d},\n", t->type, t->p[0], t->p[1], t->p[2], t->p[3]);
	}
}

void printState(PNSimState* s, uint64_t n) {
	//printf("\r");
	for(uint32_t p=0; p<n; p++) {
		printf("%hhd", s->places[p]);
	}
	printf("\n");
}

#define SEED 12345L

int main(int argc, char**argv)
{
	printf("net: %s\n", TMAP_NAME);
	printf("UNFOLD_FOR_INOUT=%d; RANDOM_MODE=%d; INTERLEAVING_SEMANTIC=%d\n", UNFOLD_FOR_INOUT, RANDOM_MODE, INTERLEAVING_SEMANTIC);
	
	uint32_t steps = argc>1 ? atoi(argv[1]) : 2;
	uint32_t timeLimit = argc>2 ? atoi(argv[2]) : 100;
	generateTMap(steps);
	//printTMap();
	printf("%d tiles: %d places, %d transitions\n", steps, numPlaces, transitions);
	
	PNSimState pn;
	init(&pn);
	pn.seed = (SEED * 0x5DEECE66DLL + 0xBLL) & ((1LL << 48LL) - 1LL);
	for(uint32_t p = 0; p<numPlaces; p++)
		pn.places[p] = initPlaces[p % tileInitPlaces];
	
	struct timeval startCompute, finishCompute;
	gettimeofday(&startCompute, NULL);
	
	//printState(&pn, numPlaces);
	uint32_t t;
	for(t = 0; t<timeLimit; t++) {
		if(!step(&pn)) break;
		//printState(&pn, numPlaces);
	}
	gettimeofday(&finishCompute, NULL);
	
	printf("Finished. Time steps: %d / %d\n", t, timeLimit);
	printf("Transitions fired: %ld\n", pn.countFired);
	
	struct timeval diff;
	double duration;
	timersub(&finishCompute, &startCompute, &diff);
	duration = (double) diff.tv_sec + (double) diff.tv_usec / 1000000.0;
	printf("Time (compute) = %lf\n", duration);
}