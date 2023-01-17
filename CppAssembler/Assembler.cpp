// Reads assembly program and produces machine code
// Usage: ./Assembler.exe [program].asm
// Output: [program].hack

#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <ctype.h>

using namespace std;

int main(int argc, char *argv[]) {

  // check for correct number of arguments
  if (argc != 2) {
    cerr << "Usage: ./Assembler.exe [program].asm";
    return 1;
  }

  cout << "Assembling " << argv[1] << '\n';
  string temp = argv[1];
  ofstream output_file;
  output_file.open(temp.replace(temp.end()-3, temp.end(), "hack"));
  
  Parser parser(argv[1]);
  SymbolTable symboltable;

  // first pass
  while (parser.hasMoreCommands()) {
    parser.advance();

    if (parser.commandType() == "L") {
      symboltable.addEntry(parser.symbol(), symboltable.rom);
    }
    else {
      symboltable.rom++;
    }
  }

  // second pass
  parser.idx = 0;

  while (parser.hasMoreCommands()) {
    parser.advance();

    // cout << parser.command << '\n';
    // cout << parser.commandType() << '\n';
    // cout << parser.symbol() << '\n';

    if (parser.commandType() == "A") {
      if (isdigit(parser.symbol()[0])) {
        output_file << "0" << bitset<15>(stoi(parser.symbol())) << '\n';
      }
      else if (symboltable.contains(parser.symbol())) {
        output_file << "0" << bitset<15>(symboltable.getAddress(parser.symbol())) << '\n';
      }
      else { // variable
        symboltable.addEntry(parser.symbol(), symboltable.ram);
        output_file << "0" << bitset<15>(symboltable.ram) << '\n';
        symboltable.ram++;
      }
    }
    else if (parser.commandType() == "C") {
      string dest = parser.dest();
      string comp = parser.comp();
      string jump = parser.jump();
      output_file << "111" << Code::comp(comp) << Code::dest(dest) << Code::jump(jump) << '\n';
      symboltable.rom++;
    }
  }

  cout << "Finished assembling" << '\n';
  output_file.close();
  
  return 0;
}