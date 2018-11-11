#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main3()
{
	// change the values of the vector here
	int i1, i2, result;

	cin >> i1 >> i2;

	try {

		if (i2 == 0) {
			throw std::logic_error("Cant divide by zero \n");
		}

		result = i1 / i2;
		cout << "Result is: " << result << endl;
	}
	catch (std::logic_error err) {
		cout << err.what() << "error: divide by 0. enter numbers again: \n";
		cin >> i1 >> i2;
		if (i2 == 0) {
			throw std::logic_error("Cant divide by zero \n");
		}
		result = i1 / i2;
		cout << "Result is: " << result << endl;
	}


	return 0;

}