#ifndef TILEMAP_H
#define TILEMAP_H

#include <fstream>
#include <string>
#include <string_view>
#include <vector>
#include "point.h"

struct SolidTile{
  Point2d position{};
  bool isSolid{};
  int frameID{};
};

class Tilemap {
  private:
    //Relative path to .map file
    const std::string m_path{};
    //Single tile dimensions
    int m_width{};
    int m_height{};
    //Texture sheet dimensions
    int m_sheetWidth{};
    int m_sheetHeight{};
    //Tile arrangement on texture sheet
    int m_mapRow{};
    int m_mapCol{};
    //Number of solid tiles on the sheet
    int m_numSolid{};

    //Hold the layers
    int *m_layer1;
    int *m_layer2;

    std::vector<int> m_solidTiles;
    SolidTile tiles[1000];

    void loadMap();
    void loadMapLayer(std::ifstream& inStream, std::string& buffer, int *layer);
    void buildSolidLayer();
    bool isSolid(int tile);
    void drawLayer(int layer[]);
  
  public:
    Tilemap(const std::string_view path);
    ~Tilemap();
};


#endif
