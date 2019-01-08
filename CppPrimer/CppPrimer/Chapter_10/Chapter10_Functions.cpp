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
	exer1022(words, 6);
	cout << "------------\n";
	exer1024();
	cout << "------------\n";
	exer1025(words,6);
	cout << "------------\n";
	exer1027(words);
	cout << "------------\n";
	exer1028();
	cout << "------------\n";
	exer1029();
	cout << "------------\n";
	//exer1030(); // cin OK
	cout << "------------\n";
	//exer1031(); // cin OK
	cout << "------------\n";
	exercise1033(); cout << "10.33: Ok." << endl;
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

void exer1022(vector<string> &words, vector<string>::size_type sz)
{


	elimDups(words);
	std::stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
	auto wc = std::find_if(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1,sz) );
	auto count = words.end() - wc;
	cout << count << " " << " words of length " << sz << " or longer" << endl;
	std::for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

bool check_size(const string & s, string::size_type sz)
{
	return s.size() >= sz;
}

bool check_size2(unsigned s, string::size_type sz)
{
	return s >= sz;
}

bool check_size3(const string &s, string::size_type sz)
{
	return s.size() < sz;
}

void exer1024()
{
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	std::string word = "hello";
	auto it = std::find_if(vec.begin(), vec.end(), std::bind(check_size2, std::placeholders::_1,word.size()));
	cout << "First value greater than word.size() in vec:  "<< *it << endl;
}

void exer1025(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
	auto wc = std::partition(words.begin(), words.end(), std::bind(check_size3, std::placeholders::_1,sz) );
	auto count = words.end() - wc;
	cout << count << " " << " words of length " << sz << " or longer" << endl;
	std::for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

void exer1027(vector<string>& words)
{
	std::list<string> lst;
	std::unique_copy(words.begin(),words.end(),std::inserter(lst,lst.begin()));
	for (auto i : lst) {
		cout << i << " ";
	}
	cout << endl;
}

void exer1028()
{
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	std::vector<int> vec1;
	std::list<int> vec2;
	std::vector<int> vec3;
	std::copy(vec.begin(),vec.end(),std::back_inserter(vec1) );
	std::copy(vec.begin(), vec.end(), std::front_inserter(vec2) );
	std::copy(vec.begin(), vec.end(), std::inserter(vec3,vec3.begin() ) );

	for (auto i : vec1) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : vec2) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : vec3) {
		cout << i << " ";
	}
	cout << endl;
}

void exer1029()
{
	std::vector<string> vecStr;
	string word;
	std::ifstream in_file("filename.txt");
	std::istream_iterator<string> str_it(in_file);
	std::istream_iterator<string> eof;
	while (str_it != eof) {
		vecStr.push_back(*str_it++);
	}
	// now print vec string
	for (auto str : vecStr) {
		cout << str << " ";
	}
	cout << endl;
}

void exer1030()
{
	std::vector<int> vec;
	std::istream_iterator<int> int_in(cin);
	std::istream_iterator<int> eof;
	while (int_in != eof) {
		vec.push_back(*int_in++);
	}
	std::sort(vec.begin(),vec.end());
	std::ostream_iterator<int> os_it(cout, " ");
	std::copy(vec.begin(), vec.end(), os_it);
}

void exer1031()
{
	std::vector<int> vec;
	std::istream_iterator<int> int_in(cin);
	std::istream_iterator<int> eof;
	while (int_in != eof) {
		vec.push_back(*int_in++);
	}
	std::sort(vec.begin(), vec.end());
	std::ostream_iterator<int> os_it(cout, " ");
	std::unique_copy(vec.begin(), vec.end(), os_it);
}

void exer1032()
{
	//TODO
}

void exercise1033()
{
	std::vector<int> vecStr;
	int number;
	std::ifstream in_file("numbers.txt");
	std::ofstream out_file_odd("odd.txt");
	std::ofstream out_file_even("even.txt");
	std::ostream_iterator<int> out_odd_it(out_file_odd, " ");
	std::ostream_iterator<int> out_even_it(out_file_even, "\n");
	std::istream_iterator<int> int_it(in_file);
	std::istream_iterator<int> eof;
	while (int_it != eof) {
		number = *int_it++;
		if((number % 2) == 0) {
			*out_even_it++ = number;
		}
		else {
			*out_odd_it++ = number;
		}
	}
}






