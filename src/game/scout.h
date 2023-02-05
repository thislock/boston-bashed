
#ifndef SCOUT_H
#define SCOUT_H

#pragma once

#include "global_scout_vars.h"
#include <SDL.h>
#include "../macros.h"
#include <iostream>


void renderInputedTexture(
	SDL_Renderer * ren, 
	SDL_Texture * tex, 
	int x, int y, 
	int w, int h
) {
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void render_scout(
	SDL_Renderer * renderer, 
	SDL_Texture * scout_h, 
	SDL_Texture * scout_torso,
	SDL_Texture * scout_l
) {

	renderInputedTexture(
    renderer,
		scout_l,
    legs_x, legs_y,
    SCOUT_LEGS_SIZE
  );

	renderInputedTexture(
    renderer,
		scout_torso,
    torso_x, torso_y,
    SCOUT_TORSO_SIZE
  );
  
	renderInputedTexture(
    renderer,
		scout_h,
    head_x, head_y,
    SCOUT_HEAD_SIZE
  );

}

// for initial variable setting.

static bool var_init = true;
// for the dodge animation, keeps track of what frame your on
static int dodge_animation_cycle = 0;
// for dodge animation, controls your velocity
static int dodge_animation_velocity = 1;

// all scout animation events
void animate_scout() {

	if (var_init) {
		
		head_y = DEFAULT_HEAD_Y;
		torso_y = DEFAULT_TORSO_Y;
		legs_y = DEFAULT_LEGS_Y;

		head_x = DEFAULT_HEAD_X;
		torso_x = DEFAULT_TORSO_X;
		legs_x = DEFAULT_LEGS_X;
		
		var_init = false;
	}

	// for dodge animation
	if (scout_dodge) {

		dodge_animation_cycle++;

		// general movment code
		if (dodge_animation_cycle <= 20) {
			head_x  -= dodge_animation_velocity;
			torso_x -= dodge_animation_velocity;
			legs_x  -= dodge_animation_velocity;
		} else {
			head_x  += dodge_animation_velocity;
			torso_x += dodge_animation_velocity;
			legs_x  += dodge_animation_velocity;
		}

		// velocity changes
		if (dodge_animation_cycle == 5)
			dodge_animation_velocity++;
		if (dodge_animation_cycle == 10)
			dodge_animation_velocity++;
		if (dodge_animation_cycle == 15)
			dodge_animation_velocity++;

		if (dodge_animation_cycle == 25)
			dodge_animation_velocity--;
		if (dodge_animation_cycle == 30)
			dodge_animation_velocity--;
		if (dodge_animation_cycle == 35)
			dodge_animation_velocity--;


		// ending code
		if (dodge_animation_cycle >= 40) {
			legs_x = DEFAULT_LEGS_X;
			scout_dodge = false;
		}
	} else {
		dodge_animation_cycle = 0;
	}
	// for idle animation
  twosCounter += 0.5;
	if (twosCounter > .5f) {
		twos = true;
		twosCounter = 0.f;
	}
	if (twos) {
		
		scout_animation_cycle++;
		switch (scout_animation_cycle)	{
			case 1:
				head_x++;
				torso_x++;
				break;
	
			case 2:
				head_x++;
				torso_x++;
				torso_y--;
				break;
	
			case 3:
				head_y--;
				torso_y--;
				break;
			
			case 4:
				head_y--;
				torso_y--;
				break;
			
			case 5:
				head_y--;					
				torso_y++;
				break;
	
			case 6:
				head_y++;
				torso_y++;
				break;
	
			case 7:
				head_y++;
				torso_y++;
				break;
	
			case 8:
				head_y++;
				break;
	
			case 9:
				head_x--;
				torso_x--;
				break;
	
			case 10:
				head_x--;
				torso_x--;						
				torso_y--;
				break;
	
			case 11:
				head_y--;
				torso_y--;
				break;
	
			case 12:
				head_y--;
				torso_y--;
				break;
	
			case 13:
				head_y++;
				torso_y++;
				break;
	
			case 14:
				head_y++;
				torso_y++;
				break;
	
			case 15:
				head_y++;
				torso_y++;
				break;
	
			default:
				head_y--;
				scout_animation_cycle = 0;
				break;
		}

		twos = false;
	}
}

#endif // SCOUT_H