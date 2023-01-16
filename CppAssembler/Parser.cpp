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

  // print
  for (int i = 0; i < input_file.size(); i++) {
    cout << input_file[i] << endl;
  }
}

bool Parser::hasMoreCommands() {
  return idx < input_file.size();
}