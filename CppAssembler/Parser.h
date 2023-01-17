#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

class Parser {
  private:
    std::vector<std::string> input_file;
    std::string command;

  public:
    Parser(std::string filename);
    bool hasMoreCommands();
    void advance();
    std::string commandType();
    std::string symbol();
    std::string dest();
    std::string comp();
    std::string jump();
    int idx;
};

#endif