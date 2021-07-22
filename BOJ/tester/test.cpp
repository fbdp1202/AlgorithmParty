#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_L=10000;

char buffer[MAX_L];
vector<std::string> colTitle;
vector<std::string> rowTitle;
vector<vector<int>> data;
int nRows, nCols;

void parserHeader(string &line) {
  bool prev_space = true;
  string tmp;

  for (const auto &i : line) {
    if (i == ' ' || i == '\n') {
      if (!prev_space) {
        colTitle.push_back(tmp);
        tmp="";
      }
      prev_space = true;
      continue;
    }
    else {
      tmp += i;
      prev_space = false;
    }
  }
  if (tmp != "") {
    colTitle.push_back(tmp);
    tmp="";
  }
}

void parserData() {
  string line;
  int count = 0;
  while (std::getline(std::cin, line)) {
     bool prev_space = true;
     vector<int> tmp_data;
     string tmp;
     count = 0;
     for (const auto &i : line) {
       if (i == ' ' || i == '\n') {
         if (!prev_space) {
           if (count == 0) {
              rowTitle.push_back(tmp);
           }
           else {
              tmp_data.push_back(stoi(tmp));
           }
           tmp="";
           count++;
         }
         prev_space = true;
         continue;
       }
       else {
         tmp += i;
         prev_space = false;
       }
     }
     if (tmp != "") {
       if (count == 0) {
         rowTitle.push_back(tmp);
       } else {
         tmp_data.push_back(stoi(tmp));
       }
       tmp="";
     }
     data.push_back(tmp_data);
  }
}

int main() {
  string line;
  getline(std::cin, line);
  parserHeader(line);
  nCols = colTitle.size();
  parserData();

  cout << "cols:" << endl;
  for (const auto &i : colTitle) {
    cout << i << " ";
  }
  cout << std::endl;

  cout << "rows:" << endl;
  for (const auto &i : rowTitle) {
    cout << i << " ";
  }
  cout << std::endl;

  for (const auto &d : data) {
    for (const auto &i : d) {
       cout << i << " ";
    }
    cout << std::endl;
  }

  return 0;
}