
#ifndef SCOUT_H
#define SCOUT_H

#pragma once

#include "global_scout_vars.h"
#include <SDL.h>
#include "../macros.h"


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

static bool var_init = true;
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

  twosCounter += 0.5;
	if (twosCounter > .5f) {
		twos = true;
		twosCounter = 0.f;
	}
	if (twos) {

		scout_animation_cycle++;
		if (scout_animation_cycle > 15) {
			head_y--;
			scout_animation_cycle = 0;
		}
		if (scout_animation_cycle == 1) {
			head_x++;
			torso_x++;
		} else if (scout_animation_cycle == 2) {
			head_x++;
			torso_x++;
			torso_y--;
		} else if (scout_animation_cycle == 3) {
			head_y--;
			torso_y--;
		} else if (scout_animation_cycle == 4) {
			head_y--;
			torso_y--;
		} else if (scout_animation_cycle == 5) {
			head_y--;					
			torso_y++;
		} else if (scout_animation_cycle == 6) {
			head_y++;
			torso_y++;
		} else if (scout_animation_cycle == 7) {
			head_y++;
			torso_y++;
		} else if (scout_animation_cycle == 8) {
			head_y++;
			head_x = DEFAULT_HEAD_X;
			torso_x = DEFAULT_TORSO_X;
		} else if (scout_animation_cycle == 9) {
			head_x--;
			torso_x--;
		} else if (scout_animation_cycle == 10) {
			head_x--;
			torso_x--;						
			torso_y--;
		} else if (scout_animation_cycle == 11) {
			head_y--;
			torso_y--;
		} else if (scout_animation_cycle == 12) {
			head_y--;
			torso_y--;
		} else if (scout_animation_cycle == 13) {
			head_y++;
			torso_y++;
		} else if (scout_animation_cycle == 14) {
			head_y++;
			torso_y++;
		} else if (scout_animation_cycle == 15) {
			head_y++;
			torso_y++;
		}
		twos = false;
	}
}

#endif // SCOUT_H