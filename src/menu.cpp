#include "menu.h"

// Init menu
menu::menu(){

}

// Destory menu
menu::~menu(){

}
// Update animation and wait for input
void menu::update(){


  angle+=1;

  if(mouseListener::mouse_button & 1){
   for(int i=0; i<75; i++){
      gamePixels.push_back(Pixel(mouseListener::mouse_x,mouseListener::mouse_y,cos(i)*((float)tools::random_int(170,230)/100),sin(i)*((float)tools::random_int(170,230)/100)));

    }


  }
  if(keyListener::anyKeyPressed){

    float newX;
    float newY;
    float newRadius=300;

    newX=512+(float)newRadius*cos(angle);
    newY=384+(float)newRadius*sin(angle);

    for(int i=0; i<75; i++){
      gamePixels.push_back(Pixel(newX,newY,cos(i)*((float)tools::random_int(170,230)/100),sin(i)*((float)tools::random_int(170,230)/100)));

    }




  }


  for(int i=0; i<gamePixels.size(); i++){
    if(!gamePixels.at(i).update())
      gamePixels.erase(gamePixels.begin()+i);
  }

}

// Draw images to screen
void menu::draw(){



  // Background
  al_clear_to_color( al_map_rgb(20,20,20));

  for(int i=0; i<gamePixels.size(); i++){
    gamePixels.at(i).draw();
  }



}




