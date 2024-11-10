#ifndef DEBUG_H
#define DEBUG_H

#include "SDL.h"

namespace Debug{
  void ColorRender(const SDL::Session& session);
  void Sprite();
  void AnimatedSprite();
};

#endif