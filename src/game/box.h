
#ifndef BOX_H
#define BOX_H

class BOX {

public:

  // ajuster for the box width, height and xy values
  int box_x = WIN_WIDTH / 5;
  int box_y = (WIN_HEIGHT / 2) + (WIN_HEIGHT / 11);
	int box_width = (WIN_WIDTH) - (box_x * 2);
  int box_height = (WIN_HEIGHT / 2) - (box_y / 2);

  void drawBox(SDL_Renderer * renderer);

};


#endif // BOX_H