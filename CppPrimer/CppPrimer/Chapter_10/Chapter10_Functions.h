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
#include <numeric>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// Main function chapter 9
void chapter_10();

// Exercise 10.1
void exer101();

// Exercise 10.2
void exer102();

// Exercise 10.3
void exer103();

// Exercise 10.5
void exer105();

// Exercise 10.6
void exer106();

// Exercise 10.9
void exer109(vector<string> &words);

// Exercise 10.11
bool isShorter10(const string &s1, const string &s2);
void exer1011(vector<string> &words);
void printVecStr(vector<string> &words);

// Exercise 10.12 -> Check Chapter 7 functions

// Exercise 10.13
// partition algorithm
void exer1013(vector<string> words);
bool has5orMore(string word);

// Exercise 10.14
void exer1014();

// Exercise 10.15
void exer1015();

// Exercise 10.16
void biggies(vector<string> &words, vector<string>::size_type sz);

// Exercise 10.17 -> check Chapter 7 functions. Rewrite of the 10.12

// Exercise 10.18
void biggies_partition(vector<string> &words, vector<string>::size_type sz);



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