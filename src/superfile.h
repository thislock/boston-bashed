
#ifndef SUPERFILE_H
#define SUPERFILE_H

#pragma once

#include "rendering/rendering.h"

#include <SDL.h>
#include <iostream>

using std::cout;
using std::string;

// filepath for the assets (so i dont forget)
#define ASSETPATH "../assets/"

// keeps a variable to crash (return 1;) on the main function.
static bool crashMain = false;
// makes the code simpler
#define EXIT crashMain = true;

class MASTER {

public:

  // the window and surface to draw on
  SDL_Window * window;
  SDL_Renderer * renderer;

  // runs when the class is created and destoryed
  MASTER();
  ~MASTER();


};


#endif // SUPERFILE_H