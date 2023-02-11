
#ifndef ATTACK_H
#define ATTACK_H


#pragma once

bool touching_heart(
  int heart_x, 
  int heart_y, 

  int checked_x,
  int checked_y, 
  int checked_width, 
  int checked_height
);

class MOVE_TOWRDS {
  

public:

  // or can be done in a seperate case
  void start(int x, int y, int heart_x, int heart_y);

  // move in determined direction
  void move();

private:

  // the occorance of the position updates 
  int occor_tracker = 0;
  int occor_rate = 0;

  // the direction to move in
  int x_dir, y_dir;

  // required positions
  int heart_x, heart_y;
  int x, y;

  // favored is the larger pos
  int favored_pos;
  int unfavored_pos;
  // keeps track of what the favored pos type is, y = true, and x = false
  bool type_fav;

  // how fast the object is moving
  int velocity = 5;

};

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

#endif // ATTACK_H