
#ifndef MACROS_H
#define MACROS_H

// the thickness of the white box
#define BOX_THICCNESS 5

// window dimentions
const int WIN_WIDTH = 900;
const int WIN_HEIGHT = 900;

// title of the window
#define TITLE "boston bashed"

// scale of the undertale heart
#define HEART_SIZE (WIN_HEIGHT / 55)

// scale of the scout body parts
#define  SCOUT_HEAD_WIDTH (WIN_WIDTH / 8) - (WIN_WIDTH / 150)
#define SCOUT_TORSO_WIDTH (WIN_WIDTH / 7) + (WIN_WIDTH / 35)
#define  SCOUT_LEGS_WIDTH ((WIN_WIDTH / 5) - (WIN_WIDTH / 15))

#define  SCOUT_HEAD_HEIGHT (WIN_HEIGHT / 9) - (WIN_HEIGHT / 150)
#define SCOUT_TORSO_HEIGHT (WIN_HEIGHT / 7) + (WIN_HEIGHT / 150)
#define  SCOUT_LEGS_HEIGHT (WIN_HEIGHT / 7) + (WIN_HEIGHT / 50)

#define  SCOUT_HEAD_SIZE SCOUT_HEAD_WIDTH,  SCOUT_HEAD_HEIGHT
#define SCOUT_TORSO_SIZE SCOUT_TORSO_WIDTH, SCOUT_TORSO_HEIGHT
#define  SCOUT_LEGS_SIZE SCOUT_LEGS_WIDTH,  SCOUT_LEGS_HEIGHT

// all of the default pos's but for scout.h
// default positions of the scout body parts
// head pos's
#define DEFAULT_HEAD_X ((WIN_WIDTH / 2) - (WIN_WIDTH / 16) - 3)
#define DEFAULT_HEAD_Y (WIN_HEIGHT / 6) + (WIN_HEIGHT / 30) + 3
// torso pos's
#define DEFAULT_TORSO_X ((WIN_WIDTH / 2) - (WIN_WIDTH / 14) - 3)
#define DEFAULT_TORSO_Y (WIN_HEIGHT / 5) + (WIN_HEIGHT / 9)
// leg pos's
#define DEFAULT_LEGS_X ((WIN_WIDTH / 2) - (WIN_WIDTH / 15))
#define DEFAULT_LEGS_Y (WIN_HEIGHT / 2) - (WIN_HEIGHT / 12)

#endif // MACROS_H