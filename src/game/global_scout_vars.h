
#ifndef GLOBAL_SCOUT_VARS_H
#define GLOBAL_SCOUT_VARS_H

#pragma once

// for animating scout at 15 fps instead of 30
static float twosCounter = 0;
static bool twos;
static int scout_animation_cycle = 0;

// for when scout dodges your attacks
static bool scout_dodge = false;

// head pos
static int head_x;
static int head_y;

// torso pos
static int torso_x;
static int torso_y;

// legs pos
static int legs_x;
static int legs_y;

#endif // GLOBAL_SCOUT_VARS_H