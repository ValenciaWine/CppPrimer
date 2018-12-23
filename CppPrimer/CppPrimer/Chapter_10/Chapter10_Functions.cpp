#include "Chapter10_Functions.h"

void chapter_10()
{
	vector<string> words{"fox", "argument","jumps", "over", "quick", "red", "red", "slow", "the", "the", "the", "turtle"};
	exer1018(words, 6);
	cout << "------------\n";
	exer1019(words, 6);
	cout << "------------\n";
	exer1020(words, 6);
	cout << "------------\n";
	exer1021();
	cout << "------------\n";

	cout << "---\nEnd\n";
	int end;
	cin >> end;
}

// partition
void exer1018(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
	auto wc = std::partition(words.begin(), words.end(), [sz](const string &s) {return s.size() < sz; });
	auto count = words.end() - wc;
	cout << count << " " << " words of length " << sz << " or longer" << endl;
	std::for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

void exer1019(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
	auto wc = std::stable_partition(words.begin(), words.end(), [sz](const string &s) {return s.size() < sz; });
	auto count = words.end() - wc;
	cout << count << " " << " words of length " << sz << " or longer" << endl;
	std::for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

void elimDups(vector<string>& words)
{
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(),words.end());
	words.erase(end_unique, words.end());
}

void exer1020(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
	auto count = std::count_if(words.begin(), words.end(), [sz](const string &s) {return s.size() >= sz; });
	cout << count << " " << " words of length " << sz << " or longer" << endl;
	std::for_each(words.end()-count, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

void exer1021()
{
	int a = 3;
	auto f = [&a]() -> bool {
		bool result = false;
		if (a != 0) {
			--a;
		}
		else {
			result = true;
		}
		return result;
	};
	for (auto i = 0; i != 5; ++i) {
		bool result = f();
		cout << (result? "Zero\n" : "Not zero\n");
	}
}



