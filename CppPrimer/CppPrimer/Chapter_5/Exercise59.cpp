#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main59()
{
	int aCnt=0, eCnt=0 , iCnt=0 , oCnt =0, uCnt = 0;
	char vowel;

	while (std::cin >> vowel) {

		if (vowel == 'a') {
			++aCnt;
		}
		if (vowel == 'e') {
			++eCnt;
		}
		if (vowel == 'i') {
			++iCnt;
		}
		if (vowel == 'o') {
			++oCnt;
		}
		if (vowel == 'u') {
			++uCnt;
		}
	}


	cout << "Number of a vowels: " << aCnt << endl;

	
}
