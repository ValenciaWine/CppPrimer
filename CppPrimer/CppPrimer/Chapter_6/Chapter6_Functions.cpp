#include "Chapter6_Functions.h"


int static_func() {
	static int a = 0;
	++a;
	return a;
}

int abs(int n) {

	int result = -1;
	if (n >= 0) {
		result = n;
	}
	else {
		result = -n;
	}

	return result;

}

int factorial(int n) {
	int result = n;
	if (n == 1) {
		return 1;
	}
	for (int i = n; i >= 1; --i) {
		if (i == 1) {
			result *= 1;
		}
		if (i != 1) {
			result = result * (i - 1);
		}

	}
	return result;
}

int swap_ints(int * a, int * b)
{
	int aux_b = *b;
	*b = *a;
	*a = aux_b;
	return 0;
}

void reset(int & a)
{
	a = 0;
}

void swap_ints_ref(int & a, int & b)
{
	int aux = b;
	b = a;
	a = aux;
}
/* Checks if the string contains a capital letter at all */
bool is_capital_letter_string(const std::string s)
{
	bool capital = false;
	for (auto i : s) {
		if (!islower(i)) {
			capital = true;
		}
	}
	return capital;
}

void string_tolower_case(std::string & s) {
	for (auto &i : s) {
		i = tolower(i);
	}
}



int exer621(int a, int * b)
{
	int result;
	if (a > *b) {
		result = a;
	}
	else {
		result = *b;
	}
	return result;
}

void print(const int *a) {

	if (a) {
		while (*a) {
			cout << *a++ << " ";
		}
	}
}

void print(const char * cp) {
	if (cp) {
		while (*cp) {
			cout << *cp++ << " ";
		}
		cout << endl;
	}

}

void print(const int * beg, const int * end)
{
	for (const int *i = beg; i != end; ++i) {
		cout << *i << " ";
	}
	cout << endl;
}

void print(const int ia[], size_t size)
{
	for (int i = 0; i != size; ++i) {
		cout << ia[i] << " ";
	}
	cout << endl;
}

void print(int(&arr)[10])
{
	for (auto i : arr) {
		cout << i << endl;
	}

}

void print(int(*matrix)[10], int rowSize)
{
	for (int i = 0; i != rowSize; ++i) {
		for (int j = 0; j != 10; ++j) {
			matrix[i][j];
		}
	}

}


int exer627(std::initializer_list<int> list)
{
	int result = 0;
	for (auto i = list.begin(); i != list.end(); ++i) {
		result += *i;
	}
	return result;
}
// incorrect return values, this code will not compile
bool str_subrange(const string & str1, const string & str2)
{
	// same sizes: return normal equality test
	if (str1.size() == str2.size()) {
		return str1 == str2;
	}
	// find the suze of the smaller string; conditional operator
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (decltype(size) i = 0; i != size; ++i) {
		if (str1[i] != str2[i]) {
			break;
		}
	}
	return false;
}

int &get(int *arry, int index) {
	return arry[index];
}

void print_vec_rec(vector<int> vec, int index)
{
	if (index != 0 && index >= 0) {
		print_vec_rec(vec, --index);
		cout << vec[index] << " ";


	}
}

string(&exer635( string(&str)[10] ))[10]
{
	return str;
}

int add(int x, int y)
{
	return x+y;
}

int sub(int x, int y)
{
	return x-y;
}

int multiply(int x, int y)
{
	return x*y;
}

int divide(int x, int y)
{
	return x/y;
}

// Exercise 6.38
int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };

decltype(odd) &arrPtr(int i) {
	return (i % 2) ? odd : even;
}


inline bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}


void chapter_6() {
	using FP = int(*)(int, int);
	typedef decltype(add)* FPA;
	typedef decltype(sub)* FPS;
	typedef decltype(multiply)* FPM;
	typedef decltype(divide)* FPD;
	vector<FP> vec = { add, multiply, divide, sub };

	int num1 = 5;
	int num2 = 5;

	for (auto i : vec) {
		cout << (*i)(num1, num2) << " ";
	}
	cout << endl;
	//////////////

	cout << " ------- \n";
	vector<int> vec2 = { 1,2,3,4,5 };
	print_vec_rec(vec2, 5);
	cout << endl;
	cout << " ------- \n";
	string str10[] = { "a","a", "a", "a", "a", "a", "a", "a", "a", "a" };
	cout << ((exer635(str10))[0]) << endl;
	cout << endl;
	cout << " ------- \n";
	//////////////
	int ia[10];
	for (int i = 0; i != 10; ++i) {
		cout << (get(ia, i) = i) << endl;
	}

	////////////////

	int i = 1;
	print(&i);
	std::initializer_list<int> list = { 1, 2, 3, 4, 5, 6 };
	cout << exer627(list) << endl;;

	//////////////
	int number;
	cout << "enter a number to calc factorial: " << endl;
	cin >> number;
	cout << abs(number) << endl;
	cout << factorial(2) << endl;
	cout << factorial(3) << endl;
	cout << factorial(4) << endl;

	while (cin >> number) {
		cout << static_func() << endl;
	}

	//int a = 7, b = 1;
	//swap_ints(&a, &b);

	//cout << "a value: " << a << " | b value: " << b << endl;


	//reset(b);

	//cout << "New resetted value of B is: " << b << endl;

	//a = 7, b = 1;

	//swap_ints_ref(a, b);
	//cout << "a value: " << a << " | b value: " << b << endl;

	//std::string s1 = "HOLA";
	//std::string s2 = "hola";

	//cout << s1 << ": " << (is_capital_letter_string(s1) ? "Yes, capital letter" : "No, No capital letter") << endl;
	//cout << s2 << ": " << (is_capital_letter_string(s2) ? "Yes, capital letter" : "No, No capital letter") << endl;

	//string_tolower_case(s1);
	//cout << "Lowering case: " << s1 << endl;
	//
}



