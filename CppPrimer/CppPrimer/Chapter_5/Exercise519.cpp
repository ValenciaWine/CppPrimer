#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main19()
{
	// change the values of the vector here
	string s1;
	string s2;

	do {
		cin >> s1 >> s2;

		if (s1 < s2) {
			cout << "s1 is less than s2\n";
		}
		else { cout << "s2 is less than s1\n"; }



	} while (cin);

	

	return 0;

}
