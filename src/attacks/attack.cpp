#include "../../include.h"
#include "attack.h"
#include <memory>

using std::unique_ptr;

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

#include "attack_script.h"

// attack test init
// for initilizing the attacks
makeimg_ test1_texture _makeimg
makeattack_ test1 _makeattack

DONTREMOVE
attack_script {

  init
    test1_texture setSprite
      "attacks/cleaver.bmp"
    endSetSprite
    test1 GET x = WIN_WIDTH;
    test1 GET y = WIN_HEIGHT;
  endinit

  test1->x -= heart_x / 100;
  test1->y += heart_y / 100;
  

  if (!touching_heart(heart_x, heart_y, test1->x, test1->y, 60, 60)) {
    test1_texture DRAW
      test1->x, test1->y,
      60, 60
    END_DRAW
  }

}
