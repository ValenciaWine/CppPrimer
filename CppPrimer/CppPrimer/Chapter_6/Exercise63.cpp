#include <iostream>
#include <string>
#include <vector>



using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int factorial(int n) {
	int result = n;
	for (int i = n; i >= 1; --i) {
		if (i != 1) {
			result = result * (i - 1);
		}
		if (i == 1) {
			result += 1;
		}
	}
	return result;
}

int main()
{

	cout << factorial(1) << endl;
	cout << factorial(2) << endl;
	cout << factorial(3) << endl;
	cout << factorial(4) << endl;

	return 0;

}