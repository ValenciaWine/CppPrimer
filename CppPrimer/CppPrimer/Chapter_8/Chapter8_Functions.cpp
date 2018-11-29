#include "Chapter8_Functions.h"

void chapter_8(string filename)
{
	//exer81(cin);


	vector<string> vecString = readFile(filename);
	for (auto p : vecString) {
		cout << p << endl;
	}

	cout << "----------\n";

	vecString = readFile2();
	for (auto p : vecString) {
		cout << p << endl;
	}
	cout << "----------\n";

	exercise810(filename);

	cout << "----------\n";
	exercise811();

	cout << "---\nEnd\n";
	int end;
	cin >> end;
}

//Exercise 8.1
std::istream & exer81(std::istream & is)
{
	char c;
	while (is >> c) {
		std::cout << c;
	}
	is.clear(is.rdstate() & ~is.eofbit);

	return is;
}

vector<string> readFile(string filename)
{

	vector<string> fileRead;
	string line;
	std::ifstream file;
	file.open(filename);
	if (file.is_open()) {
		while (std::getline(file, line)) {
			fileRead.push_back(line);
		}
	}
	else {
		std::cerr << "ERROR: file not open" << endl;
	}

	file.close();


	return fileRead;
}

vector<string> readFile2()
{
	vector<string> fileRead;
	string word;
	std::ifstream file;
	file.open("filename.txt");
	if (file.is_open()) {
		while (file >> word) {
			fileRead.push_back(word);
		}
	}
	else {
		std::cerr << "ERROR: file not open" << endl;
	}
	file.close();
	return fileRead;
}

std::istringstream& exer89(string &s, std::istringstream &strm)
{
	strm.str(s);

	string word;
	while (strm >> word) {
		std::cout << word;
	}

	return strm;

}

void exercise810(string & filename)
{
	std::ifstream file(filename);
	vector<string> vecLines;
	string line;
	string word;

	while (getline(file, line)) {
		vecLines.push_back(line);
	}

	// every line now in the vector
	for (auto p : vecLines) {
		std::istringstream strm(p);
		while (strm >> word) {
			cout << word << " ";
		}
		cout << endl;
	}
	

}

//Exercise 8.11
void exercise811() {
	struct PersonInfo {
		string name;
		vector<string> phones;
	};

	string line, word;
	vector<PersonInfo> people;

	while (getline(cin, line)) {
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}

	for (auto p : people) {
		for (auto t : p.phones) {
			cout << t << " ";
		}
	}

}

void exercise813() {
	struct PersonInfo {
		string name;
		vector<string> phones;
	};

	string line, word;
	vector<PersonInfo> people;

	std::ifstream file("filename.txt");

	while (getline(file, line)) {
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}

	for (auto p : people) {
		for (auto t : p.phones) {
			cout << t << " ";
		}
	}

}