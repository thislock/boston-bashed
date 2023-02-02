
#ifndef HEART_H
#define HEART_H

class PLAYER : public BOX {

public:

  // come on, do i even need to explain this?
  int heart_velocity = 6;

  // turned off and on when corresponding button is pressed, 
	// prevents the heart from continuing movment when key is relesed
	bool h_move_up    = false;
	bool h_move_down  = false;
	bool h_move_left  = false;
	bool h_move_right = false;

  // saves some proccessing power, along with some code mass
	bool syntax_compressor;


  // pretty self explanitory, math is for placing the heart in the middle of the box
	int heart_x = WIN_WIDTH / 2;
	int heart_y = (WIN_HEIGHT / 2) + boxSize / 3;

  void heartKeyHandler();

  void drawHeart(SDL_Renderer * renderer);

};

#endif // HEART_H