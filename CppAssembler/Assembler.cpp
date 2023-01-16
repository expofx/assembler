// Reads assembly program and produces machine code
// Usage: ./Assembler.exe [program].asm
// Output: [program].hack

#include "Parser.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {

  // check for correct number of arguments
  if (argc != 2) {
    cerr << "Usage: ./Assembler.exe [program].asm";
    return 1;
  }

  Parser parser(argv[1]);
  
  return 0;
}