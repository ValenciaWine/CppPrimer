#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main2()
{
	// change the values of the vector here
	vector<int> vec1 = {0,1,1,2};
	vector<int> vec2 = {0,1,2,2,3,5,8};

	int size = 0;
	bool prefix = true;
	if (vec1.size() <= vec2.size()) {
		size = vec1.size();
	}
	else {
		size = vec2.size();
	}

	for (int i = 0; i < size; ++i) {
		if (vec1[i] != vec2[i]) {
			prefix = false;
		}
	}

	cout << "Is one vector a prefix of the other? " << (prefix ? "True" : "False") << endl;

	return 0;

}
