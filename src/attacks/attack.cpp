#include "../../include.h"
#include "attack.h"
#include "attack_script.h"
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

// attack test init
makeimg_ test1_texture _makeimg

unique_ptr<ATTACK> test1(new ATTACK());

// for initilizing the attacks
static bool attack_init = true;

void attacks(SDL_Renderer * renderer, int heart_x, int heart_y) {

  if (attack_init) {
    test1_texture->setTexture(renderer, ASSETPATH "attacks/cleaver.bmp");
  }

  test1->x++;
  test1->y++;

  if (!touching_heart(heart_x, heart_y, test1->x, test1->y, 60, 60)) {
    test1_texture->renderScaledTexture(
      renderer,
      test1->x, test1->y,
      60, 60
    );
  }

}
