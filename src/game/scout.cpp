
#include "scout.h"

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

void SCOUT::render_scout(
	// rendering surface
	SDL_Renderer * renderer,
	// head texture 
	SDL_Texture * scout_h, 
	// torso texture
	SDL_Texture * scout_torso,
	// legs texture
	SDL_Texture * scout_l
) {

	// draws the legs
	renderInputedTexture(
    renderer,
		scout_l,
    legs_x, legs_y,
    SCOUT_LEGS_SIZE
  );

	// draws the torso
	renderInputedTexture(
    renderer,
		scout_torso,
    torso_x, torso_y,
    SCOUT_TORSO_SIZE
  );
  
	// draws the head
	renderInputedTexture(
    renderer,
		scout_h,
    head_x, head_y,
    SCOUT_HEAD_SIZE
  );

}


void SCOUT::animate_scout() {

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
		switch (dodge_animation_cycle) {
		case 5:
			dodge_animation_velocity += 2;
			break;	
		case 10:
			dodge_animation_velocity += 2;
			break;
		case 15:
			dodge_animation_velocity += 2;
			break;
		case 25:
			dodge_animation_velocity -= 2;
			break;
		case 30:
			dodge_animation_velocity -= 2;
			break;
		case 35:
			dodge_animation_velocity -= 2;
			break;
		default:
			break;
		}
	
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
