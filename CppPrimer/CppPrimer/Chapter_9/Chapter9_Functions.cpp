#include "Chapter9_Functions.h"

void chapter_9()
{
	exer952();
	cout << "------------\n";
	T_Date date = T_Date("July 25, 1990");
	cout << "------------\n";
	exer950();
	cout << "------------\n";
	exer949();
	cout << "------------\n";
	exer947_2();
	cout << "------------\n";
	exer947_1();
	cout << "------------\n";
	exer945();
	cout << "------------\n";
	exer941();
	cout << "------------\n";
	exer938();
	cout << "------------\n";
	exer934();
	cout << "------------\n";
	exer933();
	cout << "------------\n";
	exer931();
	cout << "------------\n";
	exer931_list();
	cout << "------------\n";
	exer931_flist();
	cout << "------------\n";
	std::forward_list<string> flist{ "banana", "chicken", "pork", "beef" };
	exer928(flist, "chicken", "bacon");
	for (auto st : flist) {
		cout << st << " ";
	}
	cout << endl;
	cout << "------------\n";
	exer926();
	cout << "------------\n";
	exer924();
	cout << "------------\n";
	exer922();
	cout << "------------\n";
	exer921();

	cout << "------------\n";
	// Exercise 9.2
	std::list<std::deque<int>> dequeList;

	std::vector<int> ex94vec{ 1,2,3,4,5 };
	cout << (exer94(ex94vec.begin(), ex94vec.end(), 5) ? "true\n" : "false\n") ;
	
	cout << "------------\n";

	std::vector<int>::iterator it = exer95(ex94vec.begin(), ex94vec.end(), 6);
	cout << (it == ex94vec.end() ? "Not found\n" : "Found!\n");

	std::list<int> list1{ 1,2,3,4,5 };
	std::list<int>::iterator iter1 = list1.begin(), iter2 = list1.end();
	while (iter1 != iter2) {
		cout << *iter1;
		++iter1;
	}

	cout << "---\nEnd\n";
	int end;
	cin >> end;
}

bool exer94(std::vector<int>::iterator beg, std::vector<int>::iterator end, int seek)
{
	bool found = false;
	for (auto i = beg; i != end; ++i) {
		if (*i == seek) {
			found = true;
		}
	}

	return found;
}

std::vector<int>::iterator exer95(std::vector<int>::iterator beg, std::vector<int>::iterator end, int seek)
{
	std::vector<int>::iterator found_iterator;
	bool found = false;
	for (auto i = beg; i != end && !found; ++i) {
		if (*i == seek) {
			found_iterator = i;
			found = true; // number found!
		}
	}
	if (!found) { // if number not found, return end iterator
		found_iterator = end;
	}
	return found_iterator;
}

void exer911()
{
	std::vector<int> vec1 = { 1, 2, 3, 4 };
	std::vector<int> vec2{ 1, 2, 3, 4 };
	std::vector<int> vec3(4);
	std::vector<int> vec4(4, 1);
	std::vector<int> vec5(vec1.begin(), vec2.end());
	std::vector<int> vec6;
	std::vector<int> vec7 = vec1;
	std::vector<int> vec8(vec1);
}

void exer913()
{
	std::list<int> list1 = { 1,2,3,4 };
	std::vector<int> vec2{1,2,3,4};
	vector<double> vec1(list1.begin(),list1.end());
	vector<double> vec3(vec2.begin(), vec2.end());
}

void exer914()
{
	std::list<const char*> list1 = {"hello", "bye"};
	//vector<string> vec1(list1.begin(), list1.end());
	std::vector<string> vec2;
	vec2.assign(list1.begin(),list1.end());
}

// Exercise 9.15 // Compare two vector<int> to check if they are equal.
bool areVectorsEqual(std::vector<int> vecA, std::vector<int> vecB)
{
	bool equal = false;
	if (vecA == vecB) {
		equal = true;
	}
	return equal;
}

// Exercise 9.16
// Compare list int to vector int to check if they are equal
// Change type of list int to vector int to make comparison possible
// between 2 vectors.
bool compareListVector(std::list<int> listA, std::vector<int> vecB)
{
	bool equal = false;
	std::vector<int> vecA(listA.begin(), listA.end());
	if (vecA == vecB) {
		equal = true;
	}
	return equal;
}

std::deque<string> exer918()
{
	std::deque<string> result;
	string word;

	while (cin >> word) {
		result.push_back(word);
		//result.insert(result.end(), word);
	}
	for (string s : result) {
		cout << s << " ";
	}
	cout << endl;
	return result;
}

// Exercise 9.19
// The only necessary change is just the container type from deque
// to list
std::list<string> exer919()
{
	std::list<string> result;
	string word;

	while (cin >> word) {
		result.push_back(word);
		//result.insert(result.end(), word);
	}
	for (string s : result) {
		cout << s << " ";
	}
	cout << endl;
	return result;
}

// Exercise 9.21
// Copy elements from list into evenDeque if even or oddDeque if odd
void exer920(std::list<int>& inputList, std::deque<int>& evenDeque, std::deque<int>& oddDeque)
{
	for (int n : inputList) {
		if (n % 2 == 0) { // even
			evenDeque.push_back(n);
		}
		else { //odd
			oddDeque.push_back(n);
		}
	}
}

// Exercise 9.21
// changing container type from list to vector produces same behaviour
void exer921()
{
	vector<string> words = { "hola", "adios", "killo", "que", "pasa" };
	std::vector<string> vec;
	auto iter = vec.begin();
	for (auto word : words) {
		iter = vec.insert(iter, word);
	}
	
	for (auto ix : vec) {
		cout << ix << " " ;
	}
	cout << endl;
}

// Exercise 9.22
// Fixed endless loop
void exer922()
{
	std::vector<int> iv{ 1,2,3,4,5 };
	std::vector<int>::iterator iter = iv.begin(),
		mid = iv.begin() + iv.size() / 2;
	while (iter != mid) {
		if (*iter == 5) {
			iter = iv.insert(iter, 2 * 5);
		}
		++iter;
	}
}

void exer924()
{
	vector<int> vec1{ 1,2,3,4 };
	int a = vec1.at(1);
	a = vec1[1]; cout << a << " ";
	a = vec1.front(); cout << a << " ";
	a = *vec1.begin(); cout << a << " ";
	cout << endl;
	//vector<int> vec2;
	//cout << vec2.at(2);
}

void exer926()
{
	std::vector<int> vec;
	std::list<int> list;

	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	for (auto a : ia) {
		vec.push_back(a);
		list.push_back(a);
	}

	auto it = vec.begin();
	while (it != vec.end()) {
		if ((*it % 2) == 0) { // even
			it = vec.erase(it);
		}
		else {
			++it;
		}
	}
	auto it2 = list.begin();
	while (it2 != list.end()) {
		if ((*it2 % 2) != 0) { // even
			it2 = list.erase(it2);
		}
		else {
			++it2;
		}
	}

	for (auto a : vec) {
		cout << a << " ";
	}
	cout << endl;
	for (auto a : list) {
		cout << a << " ";
	}
	cout << endl;
}

void exer927()
{
	std::forward_list<int> flist{ 1,2,3,4,5 };
	auto prev = flist.before_begin();
	auto curr = flist.begin();

	while (curr != flist.end()) {
		if (*curr % 2) {
			curr = flist.erase_after(prev);
		}
		else {
			prev = curr;
			curr++;
		}
	}
}

void exer928(std::forward_list<string> &flist, string str1, string str2)
{
	flist.resize(10, "notfood"); // resize list
	auto prev = flist.before_begin();
	auto curr = flist.begin();
	bool found = false;

	while (curr != flist.end()) {
		if (*curr == str1) {
			flist.insert_after(curr, str2);
			found = true;
		}
		prev = curr;
		++curr;
	}
	if (!found) {
		flist.insert_after(prev, str2);
	}
}

// change to accept list and forward_list
void exer931()
{
	std::vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			iter = iter + 2;
		}
		else {
			iter = vi.erase(iter);
		}
	}
	for (auto i : vi) {
		cout << i << " ";
	}
	cout << endl;
}

// list version
void exer931_list()
{
	std::list<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			++iter;
			++iter;
		}
		else {
			iter = vi.erase(iter);
		}
	}
	for (auto i : vi) {
		cout << i << " ";
	}
	cout << endl;
}

// forward_list version
void exer931_flist()
{
	std::forward_list<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();
	auto iter_prev = vi.before_begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert_after(iter_prev, *iter);
			++iter;
			++iter_prev;
			
		}
		else {

			iter = vi.erase_after(iter_prev);
			iter_prev = iter;
			

		}
	}
	for (auto i : vi) {
		cout << i << " ";
	}
	cout << endl;
}

void exer933()
{
	std::vector<int> vec{ 1,2,3,4,5 };

	auto begin = vec.begin();
	while (begin != vec.end()) {
		++begin;
		begin = vec.insert(begin, 42);
		++begin;
	}

	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
}

void exer934()
{
	std::vector<int> vec{ 1,2,3,4,5 };
	auto iter = vec.begin();
	while (iter != vec.end()) {
		if (*iter % 2) {
			iter = vec.insert(iter, *iter);
			++iter;
		}
		++iter;
	}

	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
}

void exer938()
{
	vector<int> ivec;

	cout << "ivec: Size: " << ivec.size() << endl
		<< "Capacity: " << ivec.capacity() << endl << "--------" << endl;

	for (vector<int>::size_type ix = 0; ix != 24; ++ix) {
		ivec.push_back(ix);
	}

	cout << "ivec: Size: " << ivec.size() << endl
		<< "Capacity: " << ivec.capacity() << endl << "--------" << endl;

	ivec.reserve(50);

	cout << "ivec: Size: " << ivec.size() << endl
		<< "Capacity: " << ivec.capacity() << endl << "--------" << endl;

	while (ivec.size() != ivec.capacity()) {
		ivec.push_back(0);
	}

	cout << "ivec: Size: " << ivec.size() << endl
		<< "Capacity: " << ivec.capacity() << endl << "--------" << endl;

	ivec.push_back(42);
	
	cout << "ivec: Size: " << ivec.size() << endl
		<< "Capacity: " << ivec.capacity() << endl << "--------" << endl;

	ivec.shrink_to_fit();

	cout << "ivec: Size: " << ivec.size() << endl
		<< "Capacity: " << ivec.capacity() << endl << "--------" << endl;
}

void exer941()
{
	std::vector<char> vecChar = { 'h', 'o','l','a','\0'};
	for (auto i : vecChar) {
		cout << i;
	}
	cout << endl;
	string str(vecChar.begin(), vecChar.end());
	cout << str;
	cout << endl;
}

void exer943()
{
	string s = "ugh";
	string oldVal = "though";
	string newVal;

	oldVal.erase(3,3);
	oldVal.insert(3, s);
}

void exer945()
{
	string Lname = "Smith";
	string prefix = "Mr.";
	string suffix = "Jr.";
	string name = prefix.append(" ").append(Lname).append(" ").append(suffix);

	cout << name << endl;
}

void exer947_1()
{
	string str{ "ab2c3d7R4E6" };
	string numbers{ "0123456789" };
	string letters{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	string::size_type pos = 0;
	while ((pos = str.find_first_of(numbers, pos)) != string::npos) {
		cout << "found number: " << str[pos] << endl;
		++pos;
	}
	cout << endl;

	pos = 0;
	while ((pos = str.find_first_of(letters, pos)) != string::npos) {
		cout << "found letter: " << str[pos] << endl;
		++pos;
	}
	cout << endl;

	cout << "test -------------------" << endl;
	cout << "test -------------------" << endl;
	cout << "test -------------------" << endl;

	string prueba = "aaaaaa";
	pos = 0;
	cout << "Found example: " << endl;
	pos = prueba.find_first_of(numbers);
	cout << "test pos: "<< pos << endl;

	string prueba2 = "aaaaaaa";
	cout << "not found example: " << endl;
	pos = prueba2.find_first_of(numbers,pos);
	cout << "test2 pos: " << pos << endl;
	cout << "npos = " << string::npos << endl;

	cout << "test -------------------" << endl;
	cout << "test -------------------" << endl;
	cout << "test -------------------" << endl;
}

void exer947_2()
{
	string str{ "ab2c3d7R4E6" };
	string numbers{ "0123456789" };
	string letters{ "abcdefghijklmnopqrstuvwxyz" };

	string::size_type pos = 0;
	while ((pos = str.find_first_not_of(numbers, pos)) != string::npos) {
		cout << "found number: " << str[pos] << endl;
		++pos;
	}
	cout << endl;

	pos = 0;
	while ((pos = str.find_first_not_of(letters, pos)) != string::npos) {
		cout << "found letter: " << str[pos] << endl;
		++pos;
	}
	cout << endl;

	string numbers2 = "0123456789";
	string name2 = "r2d2";

	auto pos2 = numbers2.find(name2);
	cout << pos2 << endl;
}

// read file
// read every word
// find the longest word with no descend or ascend
void exer949()
{
	string descender = "gjpqy"; // descender letters
	string ascender = "bdfhkl"; // ascender letters
	string word;				// current word being analyzed
	std::ifstream fileLines;	// file where the text is
	fileLines.open("filename.txt");
	size_t longest = 0;			// longest word size found at the moment without asc/desc letters
	string longestWord;			// longest word found without asc/desc letters
	while (fileLines >> word) {
		bool descenderFound = false;
		bool ascenderFound = false;
		string::size_type posDes = 0;
		string::size_type posAsc = 0;

		posDes = word.find_first_of(descender);
		if (posDes != string::npos) {
			descenderFound = true;
		}

		posAsc = word.find_first_of(ascender);
		if (posAsc != string::npos) {
			ascenderFound = true;
		}

		if (!descenderFound && !ascenderFound) {
			if (word.size() > longest) {
				longestWord = word;
				longest = word.size();
			}
		}
	}
	cout << "Longest word: " << longestWord << endl;
	cout << "Word size: " << longest << endl;
}

void exer950()
{
	vector<string> vec1 = { "1","2","3","4"};
	vector<string> vec2 = { "1.2","2.3","3.4","4.5" };
	int sum = 0;
	double fsum = 0.0;

	for (auto str : vec1) {
		sum += stoi(str);
	}
	for (auto str : vec2) {
		fsum += stod(str);
	}
	cout << "total sum: " << sum << endl;
	cout << "total float sum: " << fsum << endl;
}

T_Date::T_Date(string date)
{
	// January 1, 1990
	string wordMonth;
	string wordDay;
	string wordYear;
	std::istringstream str(date);
	str >> wordMonth >> wordDay >> wordYear;

	//get month
	vector<string> months = { "January","February","March","April","May","June", "July", "August", "September", "October", "November", "December" };
	auto pos = std::find(months.begin(), months.end(), wordMonth );
	T_Date::month = std::distance(months.begin(), pos) + 1;

	//get day
	T_Date::day = stoul(wordDay);

	// get year
	T_Date::year = stoul(wordYear);

	// Print date
	cout << "Month: " << this->month << endl;
	cout << "Day: " << this->day << endl;
	cout << "Year: " << this->year << endl;
}

void exer952()
{
	string parenString = "()()()()()((((()()()(())))))";
	std::stack<char> parStack;
	bool error = false;
	for (auto c : parenString) {
		if (c == '(') {
			parStack.push('(');
		}
		if (c == ')') {
			if (!parStack.empty()) {
				parStack.pop();
			}
			else {
				error = true;
				break;
			}
		}
	}
	if (parStack.empty() && !error) {
		cout << "Parenthesis expression is correct" << endl;
	}
	else {
		cout << "Parenthesis expression is not correct" << endl;
	}
}