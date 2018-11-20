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
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);
	friend Sales_data add(Sales_data &item1, Sales_data & item2);

public:
	Sales_data() : bookNo(""), units_sold(0), price(0.0), revenue(0.0) {}
	Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), price(p) {}
	Sales_data(const string &s) : bookNo(s) {}
	Sales_data(std::istream &is) { read(is, *this); }


	Sales_data& combine(const Sales_data& transaction);
	string isbn() const;
	double avg_price() const;
	
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double price = 0.0;
	double revenue = 0.0;
};



struct Person {
	friend std::istream &read_person(std::istream &is, Person &persona);
	friend std::ostream &print_person(std::ostream &os, Person &persona);

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

class Screen {

public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos h, pos w, char c) : height(h), width(w), contents(h*w,c) {}
	Screen(pos h, pos w) : height(h), width(w), contents(h*w, ' ') {}
	char get() const { return contents[cursor]; }
	inline char get(pos r, pos c) const;
	Screen &move(pos r, pos c);
	Screen &set(char c);
	Screen &set(pos r, pos col, char c);
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}


private:
	pos cursor;
	pos height;
	pos width;
	std::string contents;

	void do_display(std::ostream &os) const {
		os << contents; 
	}

};


int bookstore_program_exer71();

int bookstore_program_exer73();

int bookstore_program_exer77();

int bookstore_program_exer713();

class X {

	int item;
	Screen item2;
};

class Y {
	X item2;
	int item;
};