#ifndef _PNSIM_H_
#define _PNSIM_H_

#include <stdint.h>

#define UNFOLD_FOR_INOUT 1
#define RANDOM_MODE 0
#define INTERLEAVING_SEMANTIC 0

#define MAX_TRANS_CONNECTS 6
#define RANDOM_BITS 2
#define RANDOM_MASK ((1<<RANDOM_BITS)-1)

struct Transition {
	uint8_t type;
	uint32_t p[MAX_TRANS_CONNECTS];
};

uint32_t numPlaces;
uint32_t transitions;
Transition* tmap;

struct PNSimState {
	uint64_t seed;
	uint64_t countFired;
	uint8_t* places;
	uint8_t* changed;
	uint32_t* sh;
};

void init(PNSimState* s) {
	s->places = new uint8_t[numPlaces];
	s->changed = new uint8_t[numPlaces];
	for(uint32_t p = 0; p<numPlaces; p++)
		s->changed[p] = 0;
	s->countFired = 0;
	#if (RANDOM_MODE==1)
		s->sh = new uint32_t[transitions];
		for(uint32_t i=0; i<transitions; i++)
			s->sh[i] = i;
	#endif
}

bool step(PNSimState* s) {
	#if (RANDOM_MODE==2)
		uint64_t rand = 0;
		uint8_t sh = 0;
	#elif (RANDOM_MODE==1)
		uint32_t idx;
	#endif
		
	for(uint32_t ti = 0; ti<transitions; ti++) {
		#if (RANDOM_MODE==2)
			if(!(ti&RANDOM_MASK)) {
				rand >>= RANDOM_BITS;
				if(!rand) {
					s->seed = (s->seed * 0x5DEECE66DL + 0xBL) & ((1L << 48L) - 1L);
					rand = s->seed>>4;
				}
				sh = (uint8_t)(rand&RANDOM_MASK);
			}
			if((ti^sh)>=transitions)
				continue;
			const Transition* t = &tmap[ti^sh];
		#elif (RANDOM_MODE==1)
			s->seed = (s->seed * 0x5DEECE66DL + 0xBL) & ((1L << 48L) - 1L);
			uint32_t x = (uint32_t)(s->seed>>16L) % (transitions-ti);
			idx = s->sh[ti+x];
			const Transition* t = &tmap[idx];
			s->sh[ti+x] = s->sh[ti];
			s->sh[ti] = idx;
		#else
			const Transition* t = &tmap[ti];
		#endif
			
		if(t->type==0)
			continue;
		
		uint8_t ins = t->type&0x0f;
		uint8_t enabled = 1;
		#if UNFOLD_FOR_INOUT
			switch(ins) {
				case 1:
					if(!s->places[t->p[0]])
						enabled = false;
					break;
				case 2:
					if(!(s->places[t->p[0]] && s->places[t->p[1]]))
						enabled = false;
					break;
				case 3:
					if(!(s->places[t->p[0]] && s->places[t->p[1]] && s->places[t->p[2]]))
						enabled = false;
					break;
			}
		#else
			for(uint8_t in=0; in<ins; in++) {
				if(!s->places[t->p[in]]) {
					enabled = 0;
					break;
				}
			}
		#endif

		
		if(enabled) {
			#if UNFOLD_FOR_INOUT
				switch(ins) {
					case 1:
						s->places[t->p[0]] = 0;
						break;
					case 2:
						s->places[t->p[0]] = 0;
						s->places[t->p[1]] = 0;
						break;
					case 3:
						s->places[t->p[0]] = 0;
						s->places[t->p[1]] = 0;
						s->places[t->p[2]] = 0;
						break;
				}
				switch((t->type>>4)&0x0f) {
					case 1:
						s->changed[t->p[ins+0]] = 1;
						break;
					case 2:
						s->changed[t->p[ins+0]] = 1;
						s->changed[t->p[ins+1]] = 1;
						break;
					case 3:
						s->changed[t->p[ins+0]] = 1;
						s->changed[t->p[ins+1]] = 1;
						s->changed[t->p[ins+2]] = 1;
						break;
				}
			#else
				uint8_t pi = 0;
				for(uint8_t in=0; in<ins; in++, pi++) {
					uint32_t p = t->p[pi];
					s->places[p] = 0;
				}
				uint8_t outs = (t->type>>4)&0x0f;
				for(uint8_t out=0; out<outs; out++, pi++) {
					uint32_t p = t->p[pi];
					s->changed[p] = 1;
				}
			#endif
			
			s->countFired++;
			
			#if INTERLEAVING_SEMANTIC
				break;
			#endif
		}
	}

	bool live = false;
	for(uint32_t p = 0; p<numPlaces; p++) {
		if(s->changed[p]) {
			s->places[p] = 1;
			s->changed[p] = 0;
			live = true;
		}
	}
	return live;
}

#endif
