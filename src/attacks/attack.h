
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

class MOVE_TWORDS {
  

public:

  // initailizer, runs when class type created
  MOVE_TWORDS(int x, int y, int heart_x, int heart_y);
  // or can be done in a seperate case
  void init(int x, int y, int heart_x, int heart_y);
  MOVE_TWORDS();

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

#endif // COLLIDE_H