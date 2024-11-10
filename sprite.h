#ifndef SPRITE_H
#define SPRITE_H

#include "point.h"
#include "colors.h"
#include <ostream>

class Sprite {
  private:
    //Sprite Attributes
    std::string m_texturePath{ "path/to/texture.bmp" };
    int m_width{ 0 }, m_height{ 0 };
    Point2d m_location{ 0, 0 };
    Colors::RGB m_transparency{ 255, 255, 255 };

  public:
    //Getters
    const int getWidth() { return m_width; }
    const int getHeight() { return m_height; }
    const Point2d getLocation() { return m_location; }
    const std::string getTransparency() { return RGBtoHex(m_transparency); }
    const std::string getTexturePath() { return m_texturePath; }

    //Print the object to the console
    friend std::ostream& operator<<(std::ostream& out, Sprite& sprite) {
      out << "Sprite Object:\n";
      out << " -Texture Path: '" << sprite.getTexturePath() << "'\n";
      out << " -Dimensions: " << sprite.getWidth() << "w x " << sprite.getHeight() << "h\n";
      out << " -Location: " << sprite.getLocation() << '\n';
      out << " -Transparency: " << sprite.getTransparency() << " | " << Colors::hexToRGB(sprite.getTransparency());
      return out;
    }
};

class AnimatedSprite : public Sprite {

};

#endif
