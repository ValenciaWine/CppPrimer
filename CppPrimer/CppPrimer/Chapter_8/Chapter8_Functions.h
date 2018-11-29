#pragma once

#include <iostream>

#include <string>
#include <vector>
#include <initializer_list>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


// Main function chapter 8
void chapter_8(string filename);

//Exercise 8.1
std::istream &exer81(std::istream &is);

//// Exercise 8.4
vector<string> readFile(string filename);

//// Exercise 8.5
vector<string> readFile2();

//Exercise 8.9
std::istringstream &exer89(string &s, std::istringstream &strm);

//Exercise 8.10
void exercise810(string &filename);

//Exercise 8.11
void exercise811();


//Exercise 8.13
void exercise813();