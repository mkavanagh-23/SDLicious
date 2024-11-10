#ifndef SETTINGS_H
#define SETTINGS_H

#include <SDL2/SDL.h>
#include <string>

namespace Settings {
  const std::string GAME_TITLE{ "Game Title" };
  const int SCREEN_WIDTH{ 800 };
  const int SCREEN_HEIGHT{ 600 };
  const Uint32 SDL_FLAGS{ SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN };
  const int FPS{ 30 };
  const std::string BG_MUSIC{ "path/to/audio.wav" };
};

#endif
