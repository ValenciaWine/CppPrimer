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

// Exercise 9.24:
// Accesing elements in containers
void exer924();

// Exercise 9.26
// erase odd values from list and even values from vector
void exer926();

// Exercise 9.27
void exer927();

// Exercise 9.28
void exer928(std::forward_list<string> &flist, string str1, string str2);

// Exercise 9.31
// Duplicate odd numbers and remove even numbers
void exer931();
void exer931_list();
void exer931_flist();

// Exercise 9.33
void exer933();

// Exercise 9.34
void exer934();

// Exercise 9.38
void exer938();

// Exercise 9.41
void exer941();

// Exercise 9.43
void exer943();

// Exercise 9.45
void exer945();

// Exercise 9.47 version 1
void exer947_1();
// Exercise 9.41 version 2
void exer947_2();

// Exercise 9.49
void exer949();

// Exercise 9.50
void exer950();

// Exercise 9.51
class T_Date {

private:
	unsigned year = 2018;
	unsigned month = 1;
	unsigned day = 1;

public:
	T_Date(string date);

};

// Exercise 9.52
//Check for balanced parentheses in an expression
void exer952();