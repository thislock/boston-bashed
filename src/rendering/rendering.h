
#ifndef RENDERING_H
#define RENDERING_H

#pragma once

#include <SDL.h>
#include <iostream>

using std::cout;

class IMAGE {

public:

	IMAGE(
    SDL_Renderer * renderer, 
    const std::string &file
  );

  SDL_Texture * tex;

  void renderTexture(
    SDL_Renderer *ren, 
    int x, int y
  );

  void renderScaledTexture(
    SDL_Renderer *ren, 
    int x, int y, 
    int w, int h
  );

  SDL_Texture * returnTexture() {return tex;}

};


#endif // RENDERING_H