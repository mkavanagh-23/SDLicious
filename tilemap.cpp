#include "tilemap.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

void Tilemap::loadMap() {
  //Initialize the map layers
  m_layer1 = m_layer2 = NULL;
  
  //Load the map file
  std::ifstream in{m_path};
  //Check for successful loading
  if(!in.good()){
    std::cout << "Tilemap at \'" << m_path << "\' did not load correctly.\n";
    return;
  }
  std::string inputBuffer;

  //Get the sheet dimensions
  //Width
  std::getline(in, inputBuffer, ' ');   //Ignore the label
  std::getline(in, inputBuffer, '\n');
  m_sheetWidth = std::atoi(inputBuffer.c_str());
  //Height
  std::getline(in, inputBuffer, ' ');   //Ignore the label
  std::getline(in, inputBuffer, '\n');
  m_sheetHeight = std::atoi(inputBuffer.c_str());
  //Cols
  std::getline(in, inputBuffer, ' ');   //Ignore the label
  std::getline(in, inputBuffer, '\n');
  m_mapCol = std::atoi(inputBuffer.c_str());
  //Rows
  std::getline(in, inputBuffer, ' ');   //Ignore the label
  std::getline(in, inputBuffer, '\n');
  m_mapRow = std::atoi(inputBuffer.c_str());

  //Tile dimensionstring
  //Width
  std::getline(in, inputBuffer, ' ');   //Ignore the label
  std::getline(in, inputBuffer, '\n');
  m_width = std::atoi(inputBuffer.c_str());
  //Height
  std::getline(in, inputBuffer, ' ');   //Ignore the label
  std::getline(in, inputBuffer, '\n');
  m_height = std::atoi(inputBuffer.c_str());

  //Solid tiles
  std::getline(in, inputBuffer, '\n'); //Ignore the label
  std::getline(in, inputBuffer, '\n');
  //Store the buffer in a temporary string object for processing
  char *tempString = new char[inputBuffer.size() + 1];
  std::strcpy(tempString, inputBuffer.c_str());
  char *token = std::strtok(tempString, " ,");   //Load the first value into *token
  //Loop until end of the row
  while(token != NULL) {
    m_solidTiles.push_back(std::atoi(token)); //Add the tile to the solid tiles vector
    token = std::strtok(NULL, " ,");    //Point token at the next element
  }
  //Delete the temp string
  delete[] tempString;

  //Initialize layers before filling
  m_layer1 = new int[m_mapCol * m_mapRow];
  m_layer2 = new int[m_mapCol * m_mapRow];

  //Get each layer
  loadMapLayer(in, inputBuffer, m_layer1);
  loadMapLayer(in, inputBuffer, m_layer2);

  //Close the input file stream
  in.close();
};

void Tilemap::loadMapLayer(std::ifstream& inStream, std::string& buffer, int *layer) {
  std::getline(inStream, buffer, '\n'); //Ignore the label

  //Fill the array
  int i{ 0 }; // Array index for below for loops
  for (int row{ 0 }; row < m_mapRow; row++) { //Increment over each row
    for(int col{ 0 }; col < m_mapCol; col++) {    //Increment over each column
      char delim{ ',' };    //Set the comma delimeter
      //Check if we've reached the end of the row
      if(col == m_mapCol - 1)
        delim = '\n';
      //Get the FrameID for the current tile
      std::getline(inStream, buffer, '\n');
      layer[i] = std::atoi(buffer.c_str()); //Convert to an int and store in the array
      i++;
    }//End of row
  }//end of map
}
