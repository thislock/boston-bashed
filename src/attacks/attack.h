
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

#endif // COLLIDE_H