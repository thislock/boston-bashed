
#include "../../include.h"
#include "attack.h"


void MOVE_TOWRDS::move() {

  occor_rate += unfavored_pos;

  if (occor_rate > favored_pos) {
    if (type_fav)
      x += x_dir;
    else
      y += y_dir;
  } else {
    if (type_fav)
      y += y_dir;
    else
      x += x_dir;
  }

}


bool touching_heart(
  int heart_x, 
  int heart_y, 

  int your_x,
  int your_y, 
  int your_width, 
  int your_height
) {
  bool final_num = false;

  if (
    // pos of the heart x is greater than your objects x
    heart_x > your_x && 
    // pos of heart x and your object's, is less than both with their widths added
    heart_x + HEART_SIZE < your_x + your_width &&

    // pos of the heart y is greater than your objects y
    heart_y > your_y && 
    // pos of heart x and your object's, is less than both with their heights added
    heart_y + HEART_SIZE < your_y + your_height
  ) {
    final_num = true;
  }

  return final_num;
}

void MOVE_TOWRDS::start(int x, int y, int h_x, int h_y) {

  // see's how far away the heart pos and defined pos is
  int steps_x = h_x - x;
  int steps_y = h_y - y;


  // checks to see wich direction to go in for x
  if (steps_x < 0)
    // the direction the x value will move in
    x_dir = 1;
  else
    x_dir = -1;

  // checks to see wich direction to go in for y
  if (steps_y < 0)
    // the direction the x value will move in
    y_dir = 1;
  else
    y_dir = -1;

  // loops through the x to see the number of times it can be added too
  int steps_needed_x = 0;
  for (int i = x; i != h_x; i += x_dir) {steps_needed_x++;}
  
  // loops through the x to see the number of times it can be added too
  int steps_needed_y = 0;
  for (int i = y; i != h_y; i += y_dir) {steps_needed_y++;}

  // determines the favored and unfavored pos
  if (steps_needed_x < steps_needed_y) {
    favored_pos = steps_needed_y;
    type_fav = true;
    unfavored_pos = favored_pos / steps_needed_x;
  } else {
    favored_pos = steps_needed_x;
    type_fav = false;
    unfavored_pos = favored_pos / steps_needed_y;
  }
}