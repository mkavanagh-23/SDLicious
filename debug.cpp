#include <iostream>
#include "SDL.h"
#include "colors.h"

namespace Debug{
  //Render a solid color to the game window
  void ColorRender(const SDL::Session& session) {
    std::cout << "Debugging Color Rendering: \n";
    std::string hexValue{};
    std::cout << "Enter a hex value: ";
    std::cin >> hexValue;

    int transparency{};
    do{
      std::cout << "Enter a transparency percentage: ";
      std::cin >> transparency;
    }while(transparency < 0 || transparency > 100);

    std::cout << "Hex Value: " << hexValue << '\n';
    std::cout << Colors::hexToRGB(hexValue) << '\n';
    std::cout << "Transparency: " << transparency << "% / alpha: " << static_cast<int>(Colors::percentTo8bit(transparency)) << std::endl;

    session.drawColor(hexValue, transparency);
    session.displayRender();
  }

  void Sprite();
  void AnimatedSprite();
};
