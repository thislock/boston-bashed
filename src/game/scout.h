
#ifndef SCOUT_H
#define SCOUT_H

#pragma once

#include <SDL.h>
#include "../macros.h"
#include <iostream>
#include "sounds/sounds.h"
#include <memory>

using std::unique_ptr;

void renderInputedTexture(
	SDL_Renderer * ren, 
	SDL_Texture * tex, 
	int x, int y, 
	int w, int h
);


class SCOUT {

	// for animating scout at 15 fps instead of 30
	float twosCounter = 0;
	bool twos = false;
	int scout_animation_cycle = 0;

	// head pos
	int head_x = DEFAULT_HEAD_X;
	int head_y = DEFAULT_HEAD_Y;

	// torso pos
	int torso_x = DEFAULT_TORSO_X;
	int torso_y = DEFAULT_TORSO_Y;

	// legs pos
	int legs_x = DEFAULT_LEGS_X;
	int legs_y = DEFAULT_LEGS_Y;


	// for the dodge animation, keeps track of what frame your on
	int dodge_animation_cycle = 0;
	// for dodge animation, controls your velocity
	int dodge_animation_velocity = 2;

public:

	bool scout_dodge = false;
	
	void render_scout(
		// rendering surface
		SDL_Renderer * renderer,
		// head texture 
		SDL_Texture * scout_h, 
		// torso texture
		SDL_Texture * scout_torso,
		// legs texture
		SDL_Texture * scout_l
	);

	// all scout animation events
	void animate_scout();

};

#endif // SCOUT_H