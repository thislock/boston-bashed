#include "../../include.h"
#include "attack.h"
#include <memory>
#include <iostream>
using std::unique_ptr;

#include "attack_script.h"

// attack test init
// for initilizing the attacks
makeimg_ test1_texture _makeimg
makeattack_ test1 _makeattack

// unique_ptr<MOVE_TOWRDS> test2(new MOVE_TOWRDS());

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
