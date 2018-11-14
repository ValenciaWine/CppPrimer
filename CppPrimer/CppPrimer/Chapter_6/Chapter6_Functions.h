#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int static_func();
int abs(int n);
int factorial(int n);

//Exercise 6.10 
int swap_ints(int *a, int *b);

// Exercise 6.11
void reset(int &a);

// Exercise 6.12
void swap_ints_ref(int &a, int &b);

// Exercise 6.17
bool is_capital_letter_string(const std::string s);
void string_tolower_case(std::string &s);

// Exercise 6.18
//bool compare(matrix &m1, matrix &m2);
vector<int>::iterator change_val(int a1, vector<int>::iterator);

//Exercise 6.21
int exer621(int a, int *b);

//Exercise 6.23

void print(const int*);
void print(const char *cp);
void print(const int *beg, const int *end);
void print(const int ia[], size_t size);
void print(int (&arr)[10]);
void print(int (*matrix)[10], int rowSize);

// Exercise 6.27
int exer627(std::initializer_list<int> list);

// Exercise 6.30
bool str_subrange(const string &str1, const string &str2);

// Exercise 6.32
int &get(int *arry, int index);

//Exercise 6.33 
void print_vec_rec(vector<int> vec, int index);

// Exercise 6.36
string (&exer635( string (&str)[10]  ))[10];

// Exercise 6.37
auto exer635( string(&str)[10] ) -> string(&)[10];

typedef string ArrayString[10]; //using arrayString = string[10];
ArrayString &exer635(string(&str)[10]);

//string(&str)[10];
//decltype(str) exer635(string(&str)[10]);

//Exercise 6.54
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);







