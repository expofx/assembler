#ifndef CODE_H
#define CODE_H

#include <string>
#include <unordered_map>

class Code {
  // private:
  //   static std::unordered_map<std::string, std::string> dest_map;
  //   static std::unordered_map<std::string, std::string> comp_map;
  //   static std::unordered_map<std::string, std::string> jump_map;
  
  public:
    static std::string dest(std::string m);
    static std::string comp(std::string m);
    static std::string jump(std::string m);
};

#endif