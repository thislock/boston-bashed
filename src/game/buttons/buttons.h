#ifndef BUTTONS_H
#define BUTTONS_H

#pragma once

#include <SDL.h>
#include "../../rendering/rendering.h"
#include "../scout.h"
#include "../../superfile.h"



void draw_buttons(SDL_Renderer * renderer, int button_selected, bool scout_turn);

#endif // BUTTONS_H