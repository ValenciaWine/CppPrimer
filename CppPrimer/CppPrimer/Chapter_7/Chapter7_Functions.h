#pragma once

#include <iostream>

#include <string>
#include <vector>
#include <initializer_list>
#include <fstream>
#include <algorithm>



using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


// Main function chapter 7
void chapter_7(string &filename, string &filename_out);

struct Sales_data {
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);
	friend Sales_data add(Sales_data &item1, Sales_data & item2);

public:
	Sales_data() : bookNo(""), units_sold(0), price(0.0), revenue(0.0) {}
	Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), price(p) {}
	Sales_data(const string &s) : bookNo(s) {}
	Sales_data(std::istream &is) { read(cin, *this); }



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

	explicit Person(std::istream &is) {
		read_person(is, *this);
	}

	Person(string &n, string &a) : name(n), address(a) {}

};

class Screen;

class Window_mgr {
public:
	// location ID for each screen on the window
	using ScreenIndex = std::vector<Screen>::size_type;
	//reset the Screen at the given position to all blanks
	void clear(ScreenIndex);
	Window_mgr() = default;

private:
	std::vector<Screen> screens;
};

class Screen {

public:
	friend void Window_mgr::clear(ScreenIndex);
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

// Exercise 8.6
int bookstore_program_exer86(string &filename);

// Exercise 8.7 and 8.8
int bookstore_program_exer87(string &input_name, string &output_name);


struct X {

	int item;
	Screen item2;
};


class Y {
	X item2;
	int item;
};


class Screener {
public:
	typedef std::string::size_type pos;
	void dummy_fcn(pos height) {
		cursor = width * height;
	}

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	
};

enum VehTypes { car, bike, truck };
// Exercise 7.40
class Vehicle {
public:
	
	Vehicle() : Vehicle(car, 5) { cout << "Constructor 1 default\n"; }
	Vehicle(VehTypes t, string lp, string b, string m, unsigned s) : type(t), licensePlate(lp), brand(b), model(m), sits(s) { cout << "Constructor 2\n"; }
	Vehicle(VehTypes t = car, unsigned s = 5) : Vehicle(car, "", "", "", 5) { cout << "Constructor 3 vehicle unsigned\n"; };
	
private:
	VehTypes type;
	string licensePlate;
	string brand;
	string model;
	unsigned sits;

};


// Exercise 7.41
// Delegated constructors example to show execution order inside body functions and delegated constrctors.
struct Sales_data_delegated {

public:

	Sales_data_delegated(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n*p) { cout << "Constructor 1 main\n"; }

	Sales_data_delegated() : Sales_data_delegated("", 0, 0) { cout << "Constructor 2 default\n";  }
	Sales_data_delegated(const string &s) : Sales_data_delegated(s, 0, 0) { cout << "Constructor 3 string s\n"; }
	Sales_data_delegated(std::istream &is) : Sales_data_delegated() { cout << "Constructor 4 cin\n"; }



	Sales_data_delegated& combine(const Sales_data_delegated& transaction);
	string isbn() const;
	double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double price = 0.0;
	double revenue = 0.0;
};

class NoDefault {
public:
	NoDefault(int &a) : member_a(a) {}
	NoDefault() = default;
	int get_member_a() { return member_a; }

private:
	int member_a;
};

class C {
public:
	C(NoDefault &o) : obj(o) {}
	C() = default;

private:	
	NoDefault obj;
};

class Debug {
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
	constexpr bool any() { return hw || io || other; }

	constexpr void set_io(bool io) { this->io = io; }
	void set_hw(bool hw) { this->hw = hw; }
	void set_other(bool other) { this->other = other; }

private:
	bool hw;	// hardware errors other than IO errors
	bool io;	// IO errors
	bool other;	// other errors

};

class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double rate) { Account::interestRate = rate; }

private:
	static constexpr int period = 30; // period is a constant expression
	double daily_tbl[period];
	string owner;
	double amount;
	static double interestRate;
	static double initRate() {
		return 0.0;
	}

};
 

// Chapter 10 crossover
// Exercise 10.12
bool compareIsbn(Sales_data &item1, Sales_data &item2);
void exer1012();

// Chapter 10 crossover
// Exercise 10.17
void exer1017();


