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

// Noise
class Noise : public state{
  public:
    Noise();
    virtual ~Noise();

    void update();
    void draw();

  private:
    static const int width=200;
    static const int height=200;
    float white_noise [width][height];




};

#endif // Noise_H
