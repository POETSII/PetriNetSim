#ifndef _DHIL_H_
#define _DHIL_H_

#define POLITE_DUMP_STATS
#define POLITE_COUNT_MSGS

#include <POLite.h>

#define UNFOLD_FOR_INOUT 1
#define NO_RANDOM 0
#define TIME_TRANSITIONS 0

struct Transition {
	uint8_t type;
	uint16_t p[4];
};

struct OutMap {
	int32_t dev;
	uint16_t place;
};

#include "dphil_tmap.h"

struct DPhilMessage {
	uint32_t dev;
	uint16_t place;
};

struct DPhilState {
	uint32_t dev;
	uint32_t time;
	uint32_t timeLimit;
	uint8_t live;
	int32_t countChanges;
	uint64_t seed;
	uint64_t countFired;
	
	uint8_t places[localPlaces+outPlaces];
	uint8_t changed[localPlaces+outPlaces];
	
	OutMap outMap[outPlaces];
};

struct DPhilDevice : PDevice<DPhilState, None, DPhilMessage> {

	inline void init() {
		s->time = 0;
		s->live = 1;
		s->countFired = 0;
		for(uint16_t p = 0; p<localPlaces+outPlaces; p++)
			s->changed[p] = 0;
		s->countChanges = 0;
		*readyToSend = No;
	}

	inline void recv(DPhilMessage* msg, None* edge) {
		if(msg->dev==s->dev) {
			s->places[msg->place] = 1;
			s->live = 1;
		}
	}

	inline void send(volatile DPhilMessage* msg) {
		*readyToSend = No;
		if(s->countChanges>0) {
			for(uint16_t p = localPlaces, op = 0; op<outPlaces; p++, op++) {
				if(s->changed[p]) {
					msg->dev = s->outMap[op].dev;
					msg->place = s->outMap[op].place;
					s->changed[p] = 0;
					s->countChanges--;
					break;
				}
			}
			if(s->countChanges>0)
				*readyToSend = Pin(0);
		}
	}

	inline bool step() {
		if(!s->live || s->time>=s->timeLimit)
			return false;
		
		uint64_t rand = 0;
		uint8_t sh = 0;
		for(uint16_t ti = 0; ti<transitions; ti++) {
			#if NO_RANDOM
				const Transition* t = &tmap[ti];
			#else
				if(!(ti&3)) {
					rand >>= 2;
					if(!rand) {
						s->seed = (s->seed * 0x5DEECE66DLL + 0xBLL) & ((1LL << 48LL) - 1LL);
						rand = s->seed>>4;
					}
					sh = (uint8_t)(rand&0x3);
				}
				const Transition* t = &tmap[ti^sh];
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
						uint16_t p = t->p[pi];
						s->places[p] = 0;
					}
					uint8_t outs = (t->type>>4)&0x0f;
					for(uint8_t out=0; out<outs; out++, pi++) {
						uint16_t p = t->p[pi];
						s->changed[p] = 1;
					}
				#endif
				
				s->countFired++;
				
				#if TIME_TRANSITIONS
					s->time++;
					if(s->time>=s->timeLimit)
						break;
				#endif
			}
		}

		s->countChanges = 0;
		for(uint16_t p = 0; p<localPlaces+outPlaces; p++)
			if(s->changed[p]) s->countChanges++;
		s->live = 0;
		
		for(uint16_t p = 0; p<localPlaces; p++) {
			if(s->changed[p]) {
				s->places[p] = 1;
				s->changed[p] = 0;
				s->countChanges--;
				s->live = 1;
			}
		}
		
		#if !TIME_TRANSITIONS
			s->time++;
		#endif
		if(s->time>=s->timeLimit)
			return false;

		if(s->live || s->countChanges>0) {
			if(s->countChanges>0)
				*readyToSend = Pin(0);
			return true;
		}
		else
			return false;
	}

	inline bool finish(volatile DPhilMessage* msg) {
		msg->dev = (uint32_t)(s->countFired & 0xffffffffL);
		msg->place = (uint16_t)(s->countFired>>32L);
		return true;
	}

};

#endif
