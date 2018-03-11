#include "Noise.h"

// Init Noise
Noise::Noise(){

 generate_smooth_noise(1,1,1);

}

// Destory Noise
Noise::~Noise(){

}
// Update animation and wait for input
void Noise::update(){



}

float * Noise::generate_smooth_noise(int x,int y,int wavelength){
  float newNoise [width][height];

  for(int i=0;i<width;i++){
    for(int j=0; j<height;j++){
      white_noise[i][j]=((float)tools::random_int(2,1000))/1000;
    }
  }

  int samplePeriod = 4;
  float sampleFrequency = 1.0f/((float)samplePeriod);


  for(int i=0;i<width;i++){

    int sample_i0 = (i/samplePeriod) * samplePeriod;
    int sample_i1 = (sample_i0 + samplePeriod) % width;
    float horizontal_blend = (float)(i - sample_i0) * sampleFrequency;

    for(int j=0; j<height;j++){

      int sample_j0 = (j/samplePeriod) * samplePeriod;
      int sample_j1 = (sample_j0 + samplePeriod) % height;
      float vertical_blend = (float)(j - sample_j0) * sampleFrequency;


      float top = tools::interpolate(white_noise[sample_i0][sample_j0],white_noise[sample_i1][sample_j0],
      horizontal_blend);

      float bottom = tools::interpolate(white_noise[sample_i0][sample_j1],white_noise[sample_i1][sample_j1],
      horizontal_blend);


      smooth_noise[i][j] = tools::interpolate(top,bottom,vertical_blend);



    }
  }


  int *newNoiseInt = fillarr(newNoise);
  return &newNoiseInt;

}

// Draw images to screen
void Noise::draw(){



  // Background
  al_clear_to_color( al_map_rgb(0,100,0));


  for(int i=0;i<width;i++){
    for(int j=0; j<height;j++){
      al_put_blended_pixel(i,j,al_map_rgba_f(smooth_noise[i][j],smooth_noise[i][j],smooth_noise[i][j],smooth_noise[i][j]));

    }
  }

}




