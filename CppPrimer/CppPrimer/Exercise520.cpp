#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main4()
{
	// change the values of the vector here
	string s1;
	string lastWord = "";

	do {
		cin >> s1;

		if (s1 == lastWord) {
			cout << "The word repeated is: " << s1 << endl;
			break;
		}

		lastWord = s1;

	} while (cin);



	return 0;

}
