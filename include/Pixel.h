#ifndef PIXEL_H
#define PIXEL_H

#include "allegro5/allegro_primitives.h"

#include "tools.h"

class Pixel
{
  public:
    Pixel(int,int,int);
    Pixel(int,int,float,float);

    virtual ~Pixel();

    void draw();
    bool update();

  protected:

  private:

    int r;
    int g;
    int b;
    int alpha;

    float x;
    float y;

    float vel_x;
    float vel_y;

};

#endif // PIXEL_H
