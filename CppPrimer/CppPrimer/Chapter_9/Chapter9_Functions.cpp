#include "Chapter9_Functions.h"

void chapter_9()
{

	exer922();
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
	std::list<const char*> list1 = {"hola", "adios"};
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

