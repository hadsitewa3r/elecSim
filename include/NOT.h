#pragma once

#include "node.h"
//#include <glm/fwd.hpp>


// temporary values
#define someamount 5
#define someotherammount 15

struct not_gate{

	// the position of the gate
	#ifdef IWANNAUSEGLM
	glm::vec2 pos;
	#else
	float pos[2];
	#endif

	// the input for the gate
	node IN;

	// the output of the gate
	node OUT;
};

inline const not_gate* gate_create(float x_pos, float y_pos){

	// allocate a not_gate on the heap
	not_gate* NOT = (not_gate*) malloc(sizeof(not_gate));

	// config the nodes and the gate postion using glm or float[2] 
	#ifdef IWANNAUSEGLM
	NOT->pos     = glm::vec2(x_pos, y_pos);
	NOT->IN.pos  = glm::vec2(x_pos - someamount, y_pos);
	NOT->OUT.pos = glm::vec2(x_pos - someamount, y_pos + someotherammount);
	#else
	NOT->pos[0]     = x_pos;
	NOT->pos[1]     = y_pos;
	NOT->IN.pos[0]  = x_pos - someamount;
	NOT->IN.pos[1]  = y_pos;
	NOT->OUT.pos[0] = x_pos - someamount;
	NOT->OUT.pos[1] = y_pos + someotherammount;
	#endif

	// config the nodes I/O
	NOT->IN.type  = INPUT;
	NOT->OUT.type = OUTPUT;

	return NOT;
}

inline const void not_gate_update(not_gate* thagate){
	thagate->IN.app_logic  = thagate->IN.connected_with->app_logic;
	thagate->OUT.app_logic = !thagate->IN.app_logic;
}

inline const  void gate_delete(const not_gate* thagate){
	free((void*)thagate);
}