
#ifndef MACROS_H
#define MACROS_H

// the thickness of the white box
#define BOX_THICCNESS 5

// window dimentions
#define WIN_WIDTH 600
#define WIN_HEIGHT 600

// title of the window
#define TITLE "undertale base"

// scale of the undertale heart
#define HEART_SIZE 17

// scale of the scout body parts
#define  SCOUT_HEAD_SIZE WIN_WIDTH / 8, WIN_HEIGHT / 9
#define SCOUT_TORSO_SIZE WIN_WIDTH / 6, WIN_HEIGHT / 7
#define  SCOUT_LEGS_SIZE WIN_WIDTH / 7, WIN_HEIGHT / 8

// default positions of the scout body parts
// head pos's
#define DEFAULT_HEAD_X (WIN_WIDTH / 2) - box->boxSize / 6
#define DEFAULT_HEAD_Y (WIN_HEIGHT / 2) - box->boxSize
// torso pos's
#define DEFAULT_TORSO_X (WIN_WIDTH / 2) - (box->boxSize / 6) - 4
#define DEFAULT_TORSO_Y (WIN_HEIGHT / 3) - (box->boxSize / 11) + BOX_THICCNESS
// leg pos's
#define DEFAULT_LEGS_X (WIN_WIDTH / 2) - (box->boxSize / 6) - 2
#define DEFAULT_LEGS_Y (WIN_HEIGHT - (WIN_HEIGHT / 2) + 5) - (box->boxSize / 4)

#endif // MACROS_H