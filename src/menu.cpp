#include "menu.h"

// Init menu
menu::menu(){
  particle = tools::load_bitmap_ex("particle.png");
}

// Destory menu
menu::~menu(){

}
// Update animation and wait for input
void menu::update(){


  if(keyListener::key[ALLEGRO_KEY_A]){
   for(int i=0; i<30; i++){
      gamePixels.push_back(Pixel(mouseListener::mouse_x,mouseListener::mouse_y,((float)tools::random_int(-400,400)/100),((float)tools::random_int(-400,400)/100),particle));

    }
  }


  if(keyListener::key[ALLEGRO_KEY_G]){
   for(int i=0; i<10; i++){
      gamePixels.push_back(Pixel(mouseListener::mouse_x,mouseListener::mouse_y,((float)tools::random_int(-200,200)/100),((float)tools::random_int(-200,200)/100),particle));

    }
  }

  angle+=1;

  if(mouseListener::mouse_button & 1){
   for(int i=0; i<50; i++){
      gamePixels.push_back(Pixel(mouseListener::mouse_x,mouseListener::mouse_y,cos(i)*((float)tools::random_int(170,230)/100),sin(i)*((float)tools::random_int(170,230)/100),particle));

    }


  }
//
  if(mouseListener::mouse_button & 2){
  for(int i=0; i<75; i++){
      gamePixels.push_back(Pixel(mouseListener::mouse_x,mouseListener::mouse_y,cos(i)*((float)tools::random_int(170,230)/100),sin(i)*((float)tools::random_int(170,230)/100)));

   }


  }
  if(keyListener::keyPressed[ALLEGRO_KEY_F]){
          gameSpawners.push_back(Spawner());

    }









  for(int i=0; i<gameSpawners.size(); i++){
    gameSpawners.at(i).update();
    for(int j=0; j<10; j++)
      gamePixels.push_back(Pixel((int)gameSpawners.at(i).getX(),(int)gameSpawners.at(i).getY(),cos(j)*((float)tools::random_int(170,230)/100),sin(j)*((float)tools::random_int(170,230)/100),particle));


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




