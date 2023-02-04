
#include "../../include.h"
#include "attack.h"

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