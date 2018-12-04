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


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


// Main function chapter 9
void chapter_9();

bool exer94(std::vector<int>::iterator beg, std::vector<int>::iterator end, int seek);

std::vector<int>::iterator exer95(std::vector<int>::iterator beg, std::vector<int>::iterator end, int seek);

// Exercise 9.11
void exer911();

// Exercise 9.13
void exer913();

// Exercise 9.14
void exer914();

// Exercise 9.15
bool areVectorsEqual(std::vector<int> vecA, std::vector<int> vecB);

// Exercise 9.16
// Compare list int to vector int to check if they are equal
bool compareListVector(std::list<int> listA, std::vector<int> vecB);

// Exercise 9.18
// Read sequence of strings into a deque
std::deque<string> exer918();

// Exercise 9.19
// Read sequence of strings into a list
std::list<string> exer919();

// Exercise 9.20
void exer920(std::list<int> &inputList, std::deque<int> &evenDeque, std::deque<int> &oddDeque);

// Exercise 9.21
void exer921();

// Exercise 9.22
void exer922();