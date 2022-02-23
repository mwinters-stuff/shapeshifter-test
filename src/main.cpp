// main for the robot game
// replxx is used for input handling
// the input string is passed to the game.

// #include <fstream>
// #include <iomanip>
#include <iostream>
// #include <memory>

#include <lyra/lyra.hpp>
#include "worker.h"


std::string file;
auto cli = lyra::cli()
    | lyra::arg( file, "file" )
        ("File to read?").required();

int main(int argc_, char **argv_) {

  auto result = cli.parse( { argc_, argv_ } );
  if ( !result )
  {
    std::cerr << "Error in command line: " << result.message() << std::endl;
    exit(1);
  }

  std::cout << "Reading " << file << std::endl;

  ShapeShifterTest::Worker().work(file);

  return 0;
}

