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

	words = { "fox", "argument","jumps", "over", "quick", "red", "red", "slow", "the", "the", "the", "turtle" };
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
	exer1025(words, 6);
	cout << "------------\n";
	exer1027(words);
	cout << "------------\n";
	exer1028();
	cout << "------------\n";
	exer1029();
	cout << "------------\n";
	cout << "exer1030()\n";
	//exer1030(); // cin OK
	cout << "------------\n";
	cout << "exer1031()\n";
	//exer1031(); // cin OK
	cout << "------------\n";
	exercise1033(); cout << "10.33: Ok." << endl;
	cout << "------------\n";
	exercise1034();
	cout << "------------\n";
	exercise1035();
	cout << "------------\n";
	exercise1036();
	cout << "------------\n";
	exercise1037();
	cout << "------------\n";
	std::list<string> listWords = { "fox", "argument","jumps", "over", "quick", "red", "red", "slow", "the", "the", "the", "turtle" };
	exercise1042(listWords);
	for (auto st : listWords) {
		cout << st << " ";
	}
	cout << endl;
	cout << "------------\n";

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

void exercise1034()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	for (std::vector<int>::const_reverse_iterator it = vec.crbegin(); it != vec.crend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

// ugly code. Bad. Fix. Print reverse without reverse iterators.
void exercise1035()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	auto it = vec.cend() - 1;
	while ( it >= vec.cbegin() ) {
		cout << *it << " ";
		if (it != vec.cbegin()) {
			it--;
		}
		else { 
			break;
		}
	}
	cout << endl;
}

void exercise1036()
{
	std::list<int> ls{0,1,2,3,4,5,6,7,8,1,1,1,0,1,1,9 };
	auto count = std::distance(ls.cbegin(), find(ls.crbegin(), ls.crend(), 0).base());
	cout << "Position where 0 located: " << count << endl ;
}

void exercise1037()
{
	std::vector<int> vec{ 0,1,2,3,4,5,6,7,8,9 };
	std::list<int> list;
	auto beg = vec.crbegin() + 2;
	auto end = vec.crbegin() + 7;
	std::copy(beg, end, std::back_inserter(list));
	for (auto it : list) {
		cout << it << " ";
	}
	cout << endl;
}

// using list-version algorithms
void exercise1042(std::list<string> &words)
{
	words.sort();
	words.unique(); 
}

