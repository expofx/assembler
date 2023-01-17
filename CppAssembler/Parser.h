#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

class Parser {
  private:
    int idx;
    std::vector<std::string> input_file;

  public:
    std::string command; // move to private later, for testing purposes
    Parser(std::string filename);
    bool hasMoreCommands();
    void advance();
    std::string commandType();
    std::string symbol();
    std::string dest();
    std::string comp();
    std::string jump();
};

#endif