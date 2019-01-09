#include "Chapter10_Functions.h"
#include "../Chapter_7/Chapter7_Functions.h"

void chapter_10()
{
	exer1012();
	vector<string> words = { "fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the", "turtle" };
	printVecStr(words);
	exer109(words);
	printVecStr(words);
	cout << "-------------" << endl;
	exer1011(words);
	cout << "-------------" << endl;
	exer1013(words);
	cout << "-------------" << endl;
	exer106();
	cout << "-------------" << endl;
	exer105();
	cout << "-------------" << endl;
	exer103();
	cout << "-------------" << endl;
	exer101();
	cout << "-------------" << endl;
	exer102();
	cout << "-------------" << endl;
	cout << "-------------" << endl;
	exer1014();
	cout << "-------------" << endl;
	exer1015();
	cout << "-------------" << endl;
	words = { "fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the", "turtle" };
	biggies(words, 5);
	cout << "-------------" << endl;
	exer1017();
	cout << "-------------" << endl;

	cout << "---\nEnd\n";
	int end;
	cin >> end;
}

void exer101()
{
	std::vector<int> vec{ 2,3,4,5,6,8,9,1,2,3,4,5,1,1 };
	int result = std::count(vec.cbegin(), vec.cend(), 1);
	cout << "Total count of 1's in vector: " << result << endl;
}

void exer102()
{
	std::list<string> list{ "hi", "hi", "bye", "owl", "dog", "cat", "hi", "hi"};
	int result = std::count(list.cbegin(), list.cend(), "hi");
	cout << "Total count of hi's in list<string>: " << result << endl;
}

void exer103()
{
	vector<int> vec{ 1,2,3,4,5,6 };
	int sum = std::accumulate(vec.cbegin(), vec.cend(), 0);
	cout << "Accumulated sum from vector is: " << sum << endl;
}

void exer105()
{
	char arr[] = { 'a','a','h','e', 'l','l','o','\0' };
	char arr2[] = { 'h','e', 'l','l','o','\0' };
	// Compare 2 different size c style array strings, but within same range
	bool isEqual = std::equal(std::begin(arr)+2, std::end(arr), std::begin(arr2));
	if (isEqual) cout << "They are equal" << endl; else cout << "they are not equal" << endl;
}

void exer106()
{
	std::list<int> seq;
	std::fill_n(std::back_inserter(seq),10,0);
	for (auto i : seq) {
		cout << i << " ";
	}
	cout << endl;
}

void exer109(vector<string> &words)
{
	//sort alphabetically
	// put unique words first
	// erase the duplicated words
	cout << endl;
	std::sort(words.begin(), words.end());
	auto it = std::unique(words.begin(), words.end());
	words.erase(it, words.end());
}

bool isShorter10(const string & s1, const string & s2)
{
	return s1.size() < s2.size();
}

void exer1011(vector<string>& words)
{
	exer109(words); // Eliminate duplicates
	stable_sort(words.begin(), words.end(), isShorter10);
	for (const auto &s : words) {
		cout << s << " ";
	}
	cout << endl;
}

void printVecStr(vector<string>& words)
{
	for (const auto &s : words) {
		cout << s << " ";
	}
	cout << endl;
}

void exer1013(vector<string> words)
{
	auto it = std::partition(words.begin(), words.end(), has5orMore);
	for (auto i = words.begin(); i != it; ++i) {
		cout << *i << " ";
	}
	cout << endl;
}

bool has5orMore(string word)
{
	bool result = false;
	if (word.size() >= 5) {
		result = true;
	}
	return result;
}

void exer1014()
{
	// print once from inside the lambda expression, and once from 
	// calling and printing the lambda expression
	auto l = [](int a, int b) -> int {int result = a + b; cout << result << endl; return result; };
	cout << l(1,2) << endl;
}

void exer1015()
{
	int a = 5;
	auto sum = [a](int b) -> int {return a + b; };
	cout << sum(1) << endl;
}

void biggies(vector<string>& words, vector<string>::size_type sz)
{
	// eliminate duplicates of the vector words
	exer109(words);

	//sort alphabetically
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });

	// find the position where the word size is greater than sz
	auto wc = std::find_if(words.begin(), words.end(), [sz](const string &a) {return a.size() >= sz; });

	//calculate how many words 
	auto count = words.end() - wc;
	cout << "number of words greater than sz: " << count << endl;
	std::for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

void biggies_partition(vector<string>& words, vector<string>::size_type sz)
{

}




