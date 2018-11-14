#include "Chapter6_Functions.h"
#define NDEBUG

int main()
{

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


	cout << " ------- \n";
	vector<int> vec2 = { 1,2,3,4,5 };
	print_vec_rec(vec2, 5);
	cout << endl;
	cout << " ------- \n";
	string str10[] = { "a","a", "a", "a", "a", "a", "a", "a", "a", "a" };
	cout << ((exer635(str10))[0]) << endl;
	cout << endl;
	cout << " ------- \n";

	int ia[10];
	for (int i = 0; i != 10; ++i) {
		cout << (get(ia, i) = i) << endl;
	}



	int i = 1;
	print(&i);
	std::initializer_list<int> list = { 1, 2, 3, 4, 5, 6 };
	cout << exer627(list) << endl;;
	


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

	
	




	return 0;

}