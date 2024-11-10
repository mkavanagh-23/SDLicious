//Include Libraries
#include <cstdlib>

//Include Header files
#include "SDL.h"
#include "debug.h"

//Global Variables

//Function Prototypes

int main(int argc, char *argv[]) {

  SDL::Session gameSession{};

  Debug::ColorRender(gameSession);

  return EXIT_SUCCESS;
}
