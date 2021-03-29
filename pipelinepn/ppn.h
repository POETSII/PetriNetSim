#ifndef _PPN_H_
#define _PPN_H_

// #define POLITE_MAX_FANOUT 64

#define POLITE_DUMP_STATS
#define POLITE_COUNT_MSGS

#include <POLite.h>

struct Transition {
	uint8_t type;
	uint16_t p, p1, p2;
};

struct OutMap {
	uint32_t dev;
	uint16_t place;
};

#include "ppn_tmap.h"

struct PPNMessage {
	uint32_t dev;
	uint16_t place;
	uint8_t st;
};

struct PPNState {
	uint32_t dev;
	uint32_t time;
	uint32_t timeLimit;
	// uint16_t localPlaces;
	// uint8_t  outPlaces;
	uint8_t live;
	int32_t countChanges;
	uint16_t watchPlace;
	
	uint8_t places[MAX_PLACES];
	uint8_t placesUpd[MAX_PLACES];
	uint8_t changed[MAX_PLACES];
	
	// Transition tmap[MAX_TRANSITIONS];
	OutMap outMap[MAX_OUTMAP];
};

struct PPNDevice : PDevice<PPNState, None, PPNMessage> {

	inline void init() {
		s->time = 0;
		s->live = 1;
		for(uint16_t p = 0; p<MAX_PLACES; p++)
			s->changed[p] = 0;
		s->countChanges = 0;
		*readyToSend = No;
	}

	inline void recv(PPNMessage* msg, None* edge) {
		if(msg->dev==s->dev) {
			s->places[msg->place] = msg->st;
			s->live = 1;
		}
	}

	inline void send(volatile PPNMessage* msg) {
		*readyToSend = No;
		if(s->countChanges>0) {
			for(uint16_t p = localPlaces, op = 0; op<outPlaces; p++, op++) {
				if(s->changed[p]) {
					msg->dev = s->outMap[op].dev;
					msg->place = s->outMap[op].place;
					msg->st = s->placesUpd[p];
					s->changed[p] = 0;
					s->countChanges--;
					break;
				}
			}
			if(s->countChanges>0)
				*readyToSend = Pin(0);
		}
	}

	inline void updPlace(uint16_t p, uint8_t st) {
		s->placesUpd[p] = st;
		s->changed[p] = st;
	}

	inline bool step() {
		if(!s->live || s->time>=s->timeLimit)
			return false;
		
		for(uint16_t ti = 0; ti<MAX_TRANSITIONS; ti++) {
			const Transition* t = &tmap[ti];
			if(t->type==1) {
				if(s->places[t->p]==0 && s->places[t->p1]==1) {
					updPlace(t->p, 1);
					updPlace(t->p1, 0);
				}
			}
			else if(t->type==2) {
				if(s->places[t->p]==0 && s->places[t->p1]==1 && s->places[t->p2]==1) {
					updPlace(t->p, 1);
					updPlace(t->p1, 0);
					updPlace(t->p2, 0);
				}
			}
			else if(t->type==3) {
				if(s->places[t->p]==1 && s->places[t->p1]==0 && s->places[t->p2]==0) {
					updPlace(t->p, 0);
					updPlace(t->p1, 1);
					updPlace(t->p2, 1);
				}
			}
			else {
				break;
			}
			s->time++;
			if(s->time>=s->timeLimit)
				break;
		}

		s->countChanges = 0;
		for(uint16_t p = 0; p<MAX_PLACES; p++)
			if(s->changed[p]) s->countChanges++;
		s->live = 0;
		
		for(uint16_t p = 0; p<localPlaces; p++) {
			if(s->changed[p]) {
				s->places[p] = s->placesUpd[p];
				s->changed[p] = 0;
				s->countChanges--;
				s->live = 1;
			}
		}
		
		if(s->time>=s->timeLimit)
			return false;

		if(s->live || s->countChanges>0) {
			*readyToSend = Pin(0);
			return true;
		}
		else
			return false;
	}

	inline bool finish(volatile PPNMessage* msg) {
		msg->dev = s->time;
		msg->st = s->places[s->watchPlace];
		return true;
	}

};

#endif
