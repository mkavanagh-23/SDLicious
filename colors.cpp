#include <string>
#include <string_view>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include "colors.h"

namespace Colors{
  std::ostream& operator<<(std::ostream& out, const RGB& color) {
    out << "RGB(" << static_cast<int>(color.r) << ", " << static_cast<int>(color.g) << ", " << static_cast<int>(color.b) << ')';
    return out;
  }

  const RGB hexToRGB(const std::string_view hex) {
    std::string hexColor{ hex };
    if(hexColor[0] == '#') {
      assert(hexColor.length() == 7 && "Provided string not a valid color hex code.");
      hexColor = hexColor.substr(1, 6);
    }
    else
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
};
