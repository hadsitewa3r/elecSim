#pragma once

#define  INPUT 1
#define OUTPUT 0

#if __cplusplus
	#include <glm/glm.hpp>
	#define IWANNAUSEGLM
#endif

struct node{
	// store the node position (in glm vec2 if IWANNAUSEGLM or a float array)
	#ifdef IWANNAUSEGLM
	glm::vec2 pos;
	#else
	float pos[2];
	#endif
	// store wether the node is an inuput or output
	bool type;
	// store logic applied on the node if its an input or applied from it if its an output
	bool app_logic;


	/*
	 * THERE IS 6 BYTES WASTED HERE I SHOULD USE IT BUT ITS KINDA FINE FOR NOW
	 */


	// a pointer to the other node its connected with
	node* connected_with;
};