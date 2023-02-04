
#ifndef MACROS_H
#define MACROS_H

// the thickness of the white box
#define BOX_THICCNESS 5

// window dimentions
static int WIN_WIDTH = 700;
static int WIN_HEIGHT = 700;

// title of the window
#define TITLE "boston bashed"

// scale of the undertale heart
#define HEART_SIZE (WIN_HEIGHT / 50)

// scale of the scout body parts
#define  SCOUT_HEAD_SIZE (WIN_WIDTH / 8) - (WIN_WIDTH / 150), (WIN_HEIGHT / 9) - (WIN_HEIGHT / 150)
#define SCOUT_TORSO_SIZE (WIN_WIDTH / 7) + (WIN_WIDTH / 35), (WIN_HEIGHT / 7) + (WIN_HEIGHT / 150)
#define  SCOUT_LEGS_SIZE ((WIN_WIDTH / 5) - (WIN_WIDTH / 15)), (WIN_HEIGHT / 7) + (WIN_HEIGHT / 50)

// all of the default pos's but for scout.h
// default positions of the scout body parts
// head pos's
#define DEFAULT_HEAD_X ((WIN_WIDTH / 2) - (WIN_WIDTH / 10)) + 5
#define DEFAULT_HEAD_Y (WIN_HEIGHT / 6) + (WIN_HEIGHT / 30)
// torso pos's
#define DEFAULT_TORSO_X (WIN_WIDTH / 2) - (WIN_WIDTH / 10) - 4
#define DEFAULT_TORSO_Y (WIN_HEIGHT / 5) + (WIN_HEIGHT / 9)
// leg pos's
#define DEFAULT_LEGS_X ((WIN_WIDTH / 2) - (WIN_WIDTH / 9)) + 6
#define DEFAULT_LEGS_Y (WIN_HEIGHT / 2) - (WIN_HEIGHT / 12)

#endif // MACROS_H