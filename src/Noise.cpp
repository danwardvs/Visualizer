#include "Noise.h"

// Init Noise
Noise::Noise(){
  for(int i=0;i<width;i++){
    for(int j=0; j<height;j++){
      white_noise[i][j]=((float)tools::random_int(2,1000))/1000;
      std::cout<<white_noise[i][j];
    }
  }
}

// Destory Noise
Noise::~Noise(){

}
// Update animation and wait for input
void Noise::update(){



}

// Draw images to screen
void Noise::draw(){



  // Background
  al_clear_to_color( al_map_rgb(20,20,20));


  for(int i=0;i<width;i++){
    for(int j=0; j<height;j++){
      al_put_blended_pixel(i,j,al_map_rgba_f(white_noise[i][j],white_noise[i][j],white_noise[i][j],white_noise[i][j]));

    }
  }

}




