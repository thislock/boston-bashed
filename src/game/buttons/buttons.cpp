
#include "buttons.h"

#include <iostream>

// buttons

// fight
// unselected
unique_ptr<IMAGE> attack_button(new IMAGE());
// selected
unique_ptr<IMAGE> attack_button_selceted(new IMAGE());
// act
// unselected
unique_ptr<IMAGE> act_button(new IMAGE());
// selected
unique_ptr<IMAGE> act_button_selected(new IMAGE());
// item
// unselected
unique_ptr<IMAGE> item_button(new IMAGE());
// selected
unique_ptr<IMAGE> item_button_selected(new IMAGE());
// mercy
// unselected
unique_ptr<IMAGE> mercy_button(new IMAGE());
// selected
unique_ptr<IMAGE> mercy_button_selected(new IMAGE());


const int fight_x = WIN_WIDTH / 10;

const int act_x = WIN_WIDTH / 3 - (WIN_WIDTH / 30);

const int item_x = WIN_WIDTH - (WIN_WIDTH / 2) - 5;

const int mercy_x = (WIN_WIDTH / 3 + (WIN_WIDTH / 3)) + WIN_WIDTH / 40;

const int button_y = WIN_HEIGHT - (WIN_HEIGHT / 6);

const int button_width = WIN_WIDTH / 5;
const int button_height = WIN_HEIGHT / 10;

// for adding the assetpaths and stuff to the images
static bool button_init = true;

void draw_buttons(SDL_Renderer * renderer, int selected, bool turn) {

  if (button_init) {
    
    attack_button->setTexture(renderer, ASSETPATH "interactable/buttons/fight/fight.bmp");
    attack_button_selceted->setTexture(renderer, ASSETPATH "interactable/buttons/fight/selected_fight.bmp");
    
    act_button->setTexture(renderer, ASSETPATH "interactable/buttons/act/act.bmp");
    act_button_selected->setTexture(renderer, ASSETPATH "interactable/buttons/act/selected_act.bmp");
    
    item_button->setTexture(renderer, ASSETPATH "interactable/buttons/item/item.bmp");
    item_button_selected->setTexture(renderer, ASSETPATH "interactable/buttons/item/selected_item.bmp");
    
    mercy_button->setTexture(renderer, ASSETPATH "interactable/buttons/mercy/mercy.bmp");
    mercy_button_selected->setTexture(renderer, ASSETPATH "interactable/buttons/mercy/selected_mercy.bmp");
  
    button_init = false;
  }

  if (selected == 1) {
    renderInputedTexture(
      renderer,
      attack_button_selceted->tex,
      fight_x, button_y,
      button_width, button_height
    );
  } else {
    renderInputedTexture(
      renderer,
      attack_button->tex,
      fight_x, button_y,
      button_width, button_height
    );
  }

  if (selected == 2) {
    renderInputedTexture(
      renderer,
      act_button_selected->tex,
      act_x, button_y + 3,
      button_width, button_height
    );
  } else {
    renderInputedTexture(
      renderer,
      act_button->tex,
      act_x, button_y + 3,
      button_width, button_height
    );
  }

  if (selected == 3) {
    renderInputedTexture(
      renderer,
      item_button_selected->tex,
      item_x, button_y + 2,
      button_width, button_height
    );
  } else {
    renderInputedTexture(
      renderer,
      item_button->tex,
      item_x, button_y + 2,
      button_width, button_height
    );
  }

  if (selected == 4) {
    renderInputedTexture(
      renderer,
      mercy_button_selected->tex,
      mercy_x, button_y - 1,
      button_width, button_height
    );
  } else {
    renderInputedTexture(
      renderer,
      mercy_button->tex,
      mercy_x, button_y - 1,
      button_width, button_height
    );
  }
  
}





