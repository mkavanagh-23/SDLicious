#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

namespace Settings {
  const std::string GAME_TITLE{ "Game Title" };
  const int SCREEN_WIDTH{ 1920 };
  const int SCREEN_HEIGHT{ 1080 };
  const int FPS{ 30 };
  const std::string BG_MUSIC{ "path/to/audio.wav" };
};

#endif