// Handles symbols

#include "SymbolTable.h"

using namespace std;

SymbolTable::SymbolTable():
  table({
    {"SP", 0}, {"LCL", 1}, {"ARG", 2}, {"THIS", 3}, {"THAT", 4}, {"SCREEN", 16384}, {"KBD", 24576}
  })
  {
    for (int i = 0; i < 16; i++) {
      table["R" + to_string(i)] = i;
    }
    rom = 0;
    ram = 16;
  }

void SymbolTable::addEntry(string symbol, int address) {
  table[symbol] = address;
}

bool SymbolTable::contains(string symbol) {
  return table.find(symbol) != table.end();
}

int SymbolTable::getAddress(string symbol) {
  return table[symbol];
}