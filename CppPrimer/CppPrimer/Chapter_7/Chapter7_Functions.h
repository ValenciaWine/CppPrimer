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


// Main function chapter 6
void chapter_7();

struct Sales_data {
	Sales_data() : bookNo(""), units_sold(0), price(0.0), revenue(0.0) {}
	Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), price(p) {}
	Sales_data(const string &s) : bookNo(s) {}
	Sales_data(std::istream &is) { read(is, *this); }
	Sales_data& combine(const Sales_data& transaction);
	string isbn() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double price = 0.0;
	double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
Sales_data add(Sales_data &item1, Sales_data & item2);

struct Person {
private:
	string name;
	string address;
	
public:
	string getName() const;
	string getAddress(); // const?? 

	Person() : name(""), address("") {}

	Person(std::istream &is) {
		read_person(is, *this);
	}

	Person(string &n, string &a) : name(n), address(a) {}

};

std::istream &read_person(std::istream &is, Person &persona);
std::ostream &print_person(std::ostream &os, Person &persona);

int bookstore_program_exer71();

int bookstore_program_exer73();

int bookstore_program_exer77();

int bookstore_program_exer713();