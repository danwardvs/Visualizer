/**
 * Noise
 * A.D.S. Games
 * 06/05/2017
**/
#ifndef Noise_H
#define Noise_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>

#include "keyListener.h"
#include "mouseListener.h"
#include "joystickListener.h"
#include "tools.h"
#include "state.h"
#include "Pixel.h"
#include "Spawner.h"
#include "vector"

// Noise
class Noise : public state{
  public:
    Noise();
    virtual ~Noise();

    void update();
    void draw();

  private:

    std::vector<std::vector<float>>  generate_white_noise(int,int);


    std::vector<std::vector<float>> perlin_noise;
    //float white_noise [width][height];
    std::vector<std::vector<std::vector<float>>> smooth_noise;
    std::vector<std::vector<float>> generate_smooth_noise(int,int,int);





};

#endif // Noise_H
