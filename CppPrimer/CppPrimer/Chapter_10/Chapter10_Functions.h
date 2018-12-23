#pragma once

#include <iostream>

#include <string>
#include <vector>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <deque>
#include <list>
#include <iterator>
#include <forward_list>
#include <algorithm>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// Main function chapter 9
void chapter_10();

// Exercise 10.18
void exer1018(vector<string> &words, vector<string>::size_type sz);

// Exercise 10.19
void exer1019(vector<string> &words, vector<string>::size_type sz);


void elimDups(vector<string> &words);

// Exercise 10.20
void exer1020(vector<string> &words, vector<string>::size_type sz);

// Exercise 10.21
void exer1021();