
#ifndef RENDERING_H
#define RENDERING_H

#pragma once

#include <SDL.h>
#include <iostream>

#include<string>

using std::string;

using std::cout;

class IMAGE {

  string filename;

  SDL_Rect clip;


public:

  IMAGE();
	
  IMAGE(
    SDL_Renderer * renderer, 
    const std::string &file
  );

  ~IMAGE();
  SDL_Texture * tex;
  

  void setTexture(
    SDL_Renderer * renderer, 
    const std::string &file
  );

  void renderTexture(
    SDL_Renderer *ren, 
    int x, int y
  );

  void renderScaledTexture(
    SDL_Renderer * renderer, 
    int x, int y, 
    int w, int h
  );

  void renderCutTexture(
    SDL_Renderer *renderer, 
    int x, int y,
    int width, int height,
    int clippings[4]
  );
	

  SDL_Texture * returnTexture() {return tex;}

};


#endif // RENDERING_H