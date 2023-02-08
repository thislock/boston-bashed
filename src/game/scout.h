
#ifndef SCOUT_H
#define SCOUT_H

#pragma once

#include "global_scout_vars.h"
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

// for initial variable setting.

static bool var_init = true;
// for the dodge animation, keeps track of what frame your on
static int dodge_animation_cycle = 0;
// for dodge animation, controls your velocity
static int dodge_animation_velocity = 4;

// all scout animation events
void animate_scout(int scout_dodge);

#endif // SCOUT_H