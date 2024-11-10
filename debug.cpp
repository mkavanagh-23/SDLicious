#include <iostream>
#include "SDL.h"

namespace Debug{
  void ColorRender(const SDL::Session& session) {
    std::string hexValue{};
    std::cout << "Enter a hex value: ";
    std::cin >> hexValue;

    std::cout << "Hex Value: " << hexValue << '\n';
    std::cout << Colors::hexToRGB(hexValue) << std::endl;

    session.drawColor(hexValue, 255);
    session.displayRender();
  }

  void Sprite();
  void AnimatedSprite();
};