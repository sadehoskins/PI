#ifndef TASK2_SPRITE_H
#define TASK2_SPRITE_H

#include <vector>

#include "frame.h"
#include "vector3.h"
#include "sprite_type.h"

struct Sprite {
	Vector3 position;		// x, y, z coordinates
	bool drawable;
	unsigned int animation_frames;	// total frame count
	unsigned int width;		
	unsigned int height;	
	unsigned int current_frame;
	std::vector<Frame>* frames; // pointer to frame container
	SpriteType type;
};

#endif // TASK2_SPRITE_H
