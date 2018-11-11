#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int get_size() { return 0; }

int main5()
{
	// change the values of the vector here

/*
begin: 
	int sz = get_size;
	if (sz <= 0) {
		goto begin;
	}
*/

	int sz = get_size();
	while (sz <= 0) {
		sz = get_size();
	}

	return 0;

}
