#ifndef SDL_H
#define SDL_H

#include <SDL2/SDL.h>
#include <string_view>
#include "colors.h"

//Use this namespace for all SDL-related functionality
//Wrap all SDL functions to ensure memory-safety and RAII
namespace SDL{
  class Session{
    private:
      SDL_Window *m_window{ NULL };
      SDL_Renderer *m_renderer;
      SDL_Surface *m_surface{ NULL };
    public:
      Session();
      ~Session();
    public:
      void drawColor(std::string_view hexColor, const int alphaPercent) const; 
      void copyToRender() const;
      void displayRender() const;
  };
  
};

#endif
