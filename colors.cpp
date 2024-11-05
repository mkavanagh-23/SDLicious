#include <string>
#include <string_view>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include "colors.h"

const RGB hexToRGB(const std::string_view hex) {
  std::string hexColor{ hex };
  if(hexColor[0] == '#')
    hexColor = hexColor.substr(1, 6);
  assert(hexColor.length() == 6 && "Provided string not a valid color hex code.");

  return RGB{
    static_cast<std::uint8_t>(std::stoi(hexColor.substr(0, 2), nullptr, 16)),
    static_cast<std::uint8_t>(std::stoi(hexColor.substr(2, 2), nullptr, 16)),
    static_cast<std::uint8_t>(std::stoi(hexColor.substr(4, 2), nullptr, 16))
  };
}

const std::string RGBtoHex(const RGB& color) {
  char hex[8];
  std::sprintf(hex, "#%02x%02x%02x", static_cast<int>(color.r), static_cast<int>(color.g), static_cast<int>(color.b));
  return std::string(hex);
}