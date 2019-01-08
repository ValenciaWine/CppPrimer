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
#include <functional>

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

// Exercise 10.22
void exer1022(vector<string> &words, vector<string>::size_type sz);
bool check_size(const string &s, string::size_type sz);

// Exercise 10.24
void exer1024();

// Exercise 10.25
void exer1025(vector<string> &words, vector<string>::size_type sz);

// Exercise 10.27
void exer1027(vector<string> &words);

// Exercise 10.28
void exer1028();

// Exercise 10.29
void exer1029();

// Exercise 10.30
void exer1030();

// Exercise 10.31
void exer1031();

// Exercise 10.32
void exer1032(); // TODO

// Exercise 10.33
void exercise1033();