#pragma once

#include <iostream>

#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

// Main function chapter 12
void chapter_12();

// Exercise 12.2
class StrBlob {
public:
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	StrBlobPtr begin();
	StrBlobPtr end();
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() { return data->size(); }
	bool empty() { return data->empty(); }
	// add and remove elements
	void push_back(std::string str) { data->push_back(str); };
	void pop_back();
	// element access
	std::string& front();
	std::string& back();
	void print();
	std::shared_ptr<std::vector<std::string>>& get();

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg);
};

class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr();		// Prefix version
private:
	// check returns a shared_ptr to the vector if the check succeeds
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;		// Current position within the vector
};


class ConstStrBlobPtr {
public:
	ConstStrBlobPtr()  : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& deref() const;
	
private:
	// check returns a shared_ptr to the vector if the check succeeds
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr ;
	std::size_t curr;		// Current position within the vector
};

class TextQuery {
public:
	TextQuery(std::ifstream &infile);
	std::ostringstream query(std::string &s);

private:
	std::vector<std::string> lines;
	std::map<std::string,std::set<size_t>> queryMap;
};

class QueryResult;
class TextQuery2 {
public:
	using line_no = std::vector<std::string>::size_type;	// typedef size_type
	TextQuery2(std::ifstream&);		// Constructor

	QueryResult query(const std::string&) const;

private:
	std::shared_ptr<std::vector<std::string>> file;	// stored text by line; each vector element is a line
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wordsMap;


};

class QueryResult {
public:
	friend std::ostream& print2(std::ostream&, const QueryResult& qr);
	QueryResult(std::string s, std::shared_ptr<std::set<TextQuery2::line_no>> l, std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(l), file(f) {}
	std::set<TextQuery2::line_no>::iterator begin();
	std::set<TextQuery2::line_no>::iterator end();
	std::shared_ptr<std::vector<std::string>> get_file();

private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery2::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

void runQueries2();



// Exercise 12.1
void exer121();

// Exercise 12.6
void exer126();
std::vector<int>* exer126_1();
void exer126_2(std::vector<int> *vec);

// Exercise 12.7
void exer127();
std::shared_ptr<std::vector<int>> exer127_1();
void exer127_2(std::shared_ptr<std::vector<int>> vec);

// Exercise 12.16
void exer1216();

// Exercise 12.17
void exer1217();

// Exercise 12.20
void exer1220();

// Exercise 12.22
void exer1222();

// Exercise 12.23
void exer1223();

// Exercise 12.24
void exer1224();

// Exercise 12.26
void exer1226();

// Exercise 12.28
void exer1228();

void runQueries();

void print(std::ostream &os, std::ostringstream query);

// Exercise 12.29. While version is more explicit
void exer1229();

// Exercise 12.33
