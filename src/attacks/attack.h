
#ifndef COLLIDE_H
#define COLLIDE_H


#pragma once

bool touching_heart(
  int heart_x, 
  int heart_y, 

  int checked_x,
  int checked_y, 
  int checked_width, 
  int checked_height
);

void attacks(SDL_Renderer * renderer, int heart_x, int heart_y);
class ATTACK {


  bool isTouchingHeart;

public:

  int x, y;

  void setTexture(SDL_Texture * text) {text = tex;}
  
  void setPos(int x, int y);

  bool touchingHeart();
  
  SDL_Texture * tex;

};

#endif // COLLIDE_H