#include <SDL2/SDL.h>
#include <cassert>
#include <cstdint>
#include <string_view>
#include "SDL.h"
#include "colors.h"
#include "settings.h"

namespace SDL {
  Session::Session() {
    //Initialize SDL libraries
    SDL_Init(SDL_INIT_EVERYTHING);
    //Create the window and renderer
    SDL_CreateWindowAndRenderer(Settings::SCREEN_WIDTH, Settings::SCREEN_HEIGHT, Settings::SDL_FLAGS, &m_window, &m_renderer);
    SDL_SetWindowTitle(m_window, Settings::GAME_TITLE.c_str()); 
  }

  Session::~Session() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();  
  }

  void Session::drawColor(std::string_view hexColor, const int alphaPercent) const {
    auto color = Colors::hexToRGB(hexColor);
    auto transparency = static_cast<std::uint8_t>((alphaPercent * 255) / 100);  //Scale transparency percentage into 8-bit int
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, transparency);
    SDL_RenderClear(m_renderer);
  }

  void Session::copyToRender() const{
  }

  void Session::displayRender() const{
    SDL_RenderPresent(m_renderer);
    SDL_Delay(1000);
  }
};
