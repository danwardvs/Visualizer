#include "Pixel.h"

Pixel::Pixel(int newX, int newY, int newVelRange)
{
  x=newX;
  y=newY;
  r=255;
  b=255;
  g=255;
  vel_x=(float)tools::random_int(-newVelRange,newVelRange)/1000;
  vel_y=(float)tools::random_int(-newVelRange,newVelRange)/1000;

}

Pixel::Pixel(int newX, int newY, float newVelX,float newVelY)
{
  x=newX;
  y=newY;
  r=255;
  b=255;
  g=255;
  vel_x=newVelX;
  vel_y=newVelY;

}



Pixel::~Pixel()
{
  //dtor
}

void Pixel::draw(){



  al_draw_pixel(x,y,al_map_rgba(r,g,b,alpha));


}

bool Pixel::update(){

  bool result=true;

  r=r-tools::random_int(-1,7);
  g=g-tools::random_int(-1,7);
  b=b-tools::random_int(-1,7);

  if(r<0)
    r=0;
  if(g<0)
    g=0;
  if(b<0)
    b=0;



  if(r<=0 && b<=0 && g<=0)
    result=false;

  x+=vel_x;
  y+=vel_y;

  return result;


}
