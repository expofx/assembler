// Parses assembly language commands and strips all white spaces/comments

#include "Parser.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Parser::Parser(string filename) {

  command = "";
  idx = 0;

  // open file
  ifstream file;
  file.exceptions(ifstream::badbit); 
  try {
    file.open(filename); 
    string line;
    while (getline(file, line)) {
      // remove comments
      int c_idx = line.find("//");
      if (c_idx != string::npos) {
        line = line.substr(0, c_idx);
      }
      // remove white spaces
      line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
 
      if (line != "") {
        input_file.push_back(line);
      }
    }  
  } catch (const ifstream::failure& e) {
    cerr << "Error reading file";
  }
  file.close();

  // print file
  for (int i = 0; i < input_file.size(); i++) {
    cout << input_file[i] << endl;
  }
}

bool Parser::hasMoreCommands() {
  return idx < input_file.size();
}

void Parser::advance() {
  command = input_file[idx];
  idx++;
}

string Parser::commandType() {
  if (command[0] == '@') {
    return "A";
  } else if (command[0] == '(') {
    return "L";
  } else {
    return "C";
  }
}

string Parser::symbol() {
  if (commandType() == "A") {
    return command.substr(1);
  } else if (commandType() == "L") {
    return command.substr(1, command.size() - 2);
  } else {
    return "";
  }
}

string Parser::dest() {
  int eq_idx = command.find("=");
  if (eq_idx != string::npos) {
    return command.substr(0, eq_idx);
  } else {
    return "";
  }
}

string Parser::comp() {
  int eq_idx = command.find("=");
  int sc_idx = command.find(";");
  if (eq_idx != string::npos) {
    return command.substr(eq_idx + 1);
  } else if (sc_idx != string::npos) {
    return command.substr(0, sc_idx);
  } else {
    return "";
  }
}

string Parser::jump() {
  int sc_idx = command.find(";");
  if (sc_idx != string::npos) {
    return command.substr(sc_idx + 1);
  } else {
    return "";
  }
}