
#ifndef SCOUT_H
#define SCOUT_H

static float twosCounter = 0;
static bool twos;
static int scout_animation_cycle = 0;
static int head_x;
static int head_y;
static int torso_x;
static int torso_y;

void animate_scout() {
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