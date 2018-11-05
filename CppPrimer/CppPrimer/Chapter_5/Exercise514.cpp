#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main1()
{

	string currentWord;
	vector<string> wordList;
	vector<int> wordCount;
	int index;
	bool found = false;

	while (cin >> currentWord) {
		for (string seek : wordList) {
			if (seek == currentWord) {
				++wordCount[index];
				found = true;
			}
			++index;
		}
		if (!found) { // New word! Add the new word to wordList and wordCount
			wordList.push_back(currentWord);
			wordCount.push_back(1);
		}
		// reset search variables
		found = false;
		index = 0;

	}

	index = 0;
	// print results
	for (string word : wordList) {
		cout << word << ": " << wordCount[index] << endl;
		++index;

	}


	return 0;
}
