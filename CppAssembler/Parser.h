#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

class Parser {
  private:
    std::string command;
    int idx;
    std::vector<std::string> input_file;

  public:
    Parser(std::string filename);
    bool hasMoreCommands();
};

#endif