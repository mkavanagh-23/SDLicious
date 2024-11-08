#ifndef COLORS_H
#define COLORS_H

#include <cstdint>
#include <ostream>
#include <string>
#include <string_view>
#include <cstdio>

namespace Colors{
  //A struct to hold RGB objects
  struct RGB {
    public:
      const std::uint8_t r{ 255 };
      const std::uint8_t g{ 255 };
      const std::uint8_t b{ 255 };

    public:
      RGB(std::uint8_t red, std::uint8_t green, std::uint8_t blue)
        : r{ red }, g{ green }, b{ blue }
      {}

    public:
      friend std::ostream& operator<<(std::ostream& out, const RGB& color) {
        out << "RGB(" << static_cast<int>(color.r) << ", " << static_cast<int>(color.g) << ", " << static_cast<int>(color.b) << ')';
        return out;
      }
    };

const RGB hexToRGB(const std::string_view hex);
const std::string RGBtoHex(const RGB& color);

} //END NAMESPACE

#endif