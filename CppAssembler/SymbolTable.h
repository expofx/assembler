#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
#include <map>

class SymbolTable {
  public:
    SymbolTable();
    bool contains(std::string symbol);
    int getAddress(std::string symbol);
    void addEntry(std::string symbol, int address);
    int rom;
    int ram;
  private:
    std::map<std::string, int> table;
};

#endif