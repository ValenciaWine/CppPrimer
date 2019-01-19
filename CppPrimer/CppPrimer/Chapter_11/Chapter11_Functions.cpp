#include "Chapter11_Functions.h"
#include "../Chapter_7/Chapter7_Functions.h"


void chapter_11()
{
	exer113();
	cout << "------------\n";
	exer114();
	cout << "------------\n";
	exer117();
	cout << "------------\n";
	exer1110();
	cout << "------------\n";
	exer1111();
	cout << "------------\n";
	exer1112();
	cout << "------------\n";
	exer1114();
	cout << "------------\n";
	exer1116();
	cout << "------------\n";
	exer1117();
	cout << "------------\n";
	exer1118();
	cout << "------------\n";
	exer1119();
	cout << "------------\n";
	exer1120();
	cout << "------------\n";
	exer1123();
	cout << "------------\n";
	exer1126();
	cout << "------------\n";
	exer1128();
	cout << "------------\n";
	exer1131();
	cout << "------------\n";
	exer1132();
	cout << "------------\n";
	wordTransform();
	cout << "------------\n";
	exer1138v1();
	cout << "------------\n";
	exer1138v2();

	cout << "---\nEnd\n";
	int end;
	cin >> end;
}

void exer113()
{
	std::map<string, std::size_t> word_count;
	string word;
	std::istringstream str_st("hola hola estas que es esto");
	while (str_st >> word) {
		++word_count[word];
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
	}
}

void exer114()
{
	std::map<string, std::size_t> word_count;
	std::set<string> exclude = {",",".", "?", "!", "¿", "¡", ":", ";", "-", "_"};
	string word;
	std::string str_st("Hola hola HOLA, estas . ,  que es esto");
	string newstr;
	size_t i = 0;
	for(char ch : str_st) {
		if (std::isspace(ch)) {
			newstr += " ";
		}
		if (std::isalpha(ch)) {
			ch = std::tolower(ch);
			newstr += ch;
		}

	}

	std::istringstream str_st2(newstr);
	while (str_st2 >> word) {
		//std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		if ( exclude.find(word) == exclude.end()) {
			++word_count[word];
		}
			
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
	}
}

void exer117()
{
	std::map<string, std::vector<string>> families;
	families["Smith"].push_back("Liam");
	families["Smith"].push_back("Noah");
	families["Smith"].push_back("William");
	families["Smith"].push_back("James");
	families["Johnson"].push_back("Mason");
	families["Johnson"].push_back("Logan");
	families["Johnson"].push_back("Benjamin");

	// list sons and family names
	for (auto i : families) {
		for (auto j : i.second) {
			cout << j << " ";
			cout << i.first << " ";
			cout << endl;
		}
		cout << endl;
	}
}

void exer118()
{
	// vector version
	std::vector<string> exclude1 = { ",",".", "?", "!", "¿", "¡", ":", ";", "-", "_" };
	auto it = std::find(exclude1.cbegin(), exclude1.cend(), "?");

	// set version
	std::set<string> exclude2 = { ",",".", "?", "!", "¿", "¡", ":", ";", "-", "_" };
	exclude2.find("?");
}

void exer119()
{
	std::map<string, std::list<int>>  word_line_number;
	word_line_number["hello"].push_back(5);
	word_line_number["hello"].push_back(6);
}

void exer1110()
{
	std::vector<int> vec = { 1,2,3,4,5 };
	auto vec_beg = vec.begin();
	std::map <vector<int>::iterator, int > vec_it_map;
	vec_it_map[vec_beg] = 1;
//
//	std::list<int> list = { 1,2,3,4,5 };
//	auto list_beg = list.begin();
//	std::map<std::list<int>::iterator, int> list_it_map;
//	list_it_map[list_beg] = 1;
}

void exer1111()
{
	//Sales_data item;
	//std::multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
	std::multiset<Sales_data, bool(*)(Sales_data &item1, Sales_data &item2)> bookstore(compareIsbn);
}

void exer1112()
{
	std::vector< std::pair<string,int> > pair_store;
	string stream = "a 1 b 2 c 3 d 4";
	std::istringstream st(stream);
	string word;
	int num;
	while (st >> word >> num) {
		pair_store.push_back({word,num});
	}

	for (auto &i : pair_store) {
		cout << i.first << " " << i.second;
		cout << endl;
	}
}

void exer1113()
{
	std::vector< std::pair<string, int> > pair_store1;
	string stream = "a 1 b 2 c 3 d 4";
	std::istringstream st(stream);
	string word;
	int num;
	st >> word >> num;

	pair_store1.push_back({ word,num }); // version 1
	pair_store1.push_back(std::make_pair(word,num)); // version 2
	pair_store1.push_back( std::pair<string, int>(word, num) ); // version 3

	std::pair<string, int> pair1{ word, num }; // version 4
	std::pair<string, int> pair2 = { word, num }; // version 5
	std::pair<string, int> pair3(word, num); // version 6
	pair_store1.push_back(pair1); 
	pair_store1.push_back(pair2); 
	pair_store1.push_back(pair3); 
}

void exer1114()
{
	std::map<string, std::vector<std::pair<string, string>>> families; // last name, vector of siblings (name and birthday)
	families["Smith"].push_back({ "Liam" , "01/10/99"});
	families["Smith"].push_back({ "Noah" ,"01/10/99"});
	families["Smith"].push_back({ "William" ,"01/10/99"});
	families["Smith"].push_back({ "James" ,"01/10/99"});
	families["Johnson"].push_back({ "Mason" ,"01/10/99"});
	families["Johnson"].push_back({ "Logan" ,"01/10/99"});
	families["Johnson"].push_back({ "Benjamin"  ,"01/10/99"});

	// list sons and family names
	for (auto i : families) {
		for (auto j : i.second) {
			cout << j.first << " ";
			cout << i.first << " ";
			cout << j.second << " ";
			cout << endl;
		}
		cout << endl;
	}
}

void exer1116()
{
	std::map<string, int> map;
	map["test1"];
	std::map<string, int>::iterator map_it = map.begin();
	map_it->second = 5;
	cout << map_it->first << " " << map_it->second << endl;
}

void exer1117()
{
	std::multiset<string> c{ "1","2", "3", "4", "5" };
	std::vector<string> v{ "1","2", "3", "4", "5" };

	std::copy(v.begin(), v.end(), std::inserter(c, c.end())); // Okay
	for (auto it : c) {
		cout << it << " ";
	}
	cout << endl;

	//std::copy(v.begin(), v.end(), std::back_inserter(c2)); // wrong

	std::copy(c.begin(), c.end(), inserter(v, v.end())); // Okay
	for (auto it : v) {
		cout << it << " ";
	}
	cout << endl;

	std::copy(c.begin(), c.end(), std::back_inserter(v) ); // Okay
	for (auto it : v) {
		cout << it << " ";
	}
	cout << endl;
}

void exer1118()
{
	std::map<string, int> word_count;
	std::map<string, int>::iterator word_count_it;
}

void exer1119()
{
	std::multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
	std::multiset<Sales_data,bool(*)(Sales_data &item1, Sales_data &item2)>::iterator it = bookstore.begin();
}

void exer1120()
{
	std::map<string, std::size_t> word_count;
	string word;
	std::istringstream str_st("hola hola estas que es esto");
	while (str_st >> word) {
		// this is easier to write/read.
		auto ret = word_count.insert({word,1});
		if (!ret.second) {
			++((ret.first)->second); // increment word count
		}
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
	}
}

void exer1122()
{
	std::map<string, std::vector<int>> word_count;
	string word;
	std::istringstream str_st("hola hola estas que es esto");
	while (str_st >> word) {
		// insert word to map with count 1.
		std::pair<std::map<string,std::vector<int>>::iterator,bool> ret = word_count.insert({ word,{1} });
		if (!ret.second) {
			++((ret.first)->second[0]); // increment word count
		}
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second[0] << ((w.second[0] > 1) ? " times" : " time") << endl;
	}
}

void exer1123()
{
	std::multimap<string, string> families;
	families.insert({"Smith", "Liam"});
	families.insert({ "Smith", "Noah" });
	families.insert({ "Smith", "William" });
	families.insert({ "Smith", "James" });
	families.insert({ "Johnson", "Mason" });
	families.insert({ "Johnson", "Logan" });
	families.insert({ "Johnson", "Benjamin" });

	// list sons and family names
	for (auto i : families) {
		cout << i.second << " " << i.first;
		cout << endl;
	}
}

void exer1126()
{
	std::map<int, int> m;
	m[1] = 1;
	std::map<int,int>::mapped_type a = m[1]; // mapped_type
}

void exer1128()
{
	std::map<string, std::vector<int>> m;
	std::map<string,std::vector<int>>::iterator it = m.find("test");
	auto it2 = m.find("test");
}

void exer1131()
{
	std::multimap<string,string> authors;
	authors.insert({"Tolkien","Lotr"});
	authors.insert({"Tolkien","Hobbit"});
	authors.insert({ "Tolkien","Silmarillion" });
	
	//print original map
	for (auto i : authors) {
		cout << i.second << " by " << i.first << "." << endl;
	}
	cout << "---:--" << endl;
	std::multimap<string, string>::iterator it;
	string removeElement = "Hobbit";
	// Look for the position in the map where Hobbit is located
	for (auto pos = authors.equal_range("Tolkien"); pos.first != pos.second; ++pos.first) {
		if (pos.first->second == removeElement) {
			it = pos.first;
		}
	}
	// once located the hobbit, erase it from map
	if (it != authors.end()) {
		authors.erase(it);
	}
	//print map to see results
	for (auto i : authors) {
		cout << i.second << " by " << i.first << "." << endl;
	}
}

void exer1132()
{
	// Create map with authors and book titles
	std::multimap<string, string> authors;
	authors.insert({ "Tolkien","Lotr" });
	authors.insert({ "Tolkien","Hobbit" });
	authors.insert({ "Tolkien","Silmarillion" });
	authors.insert({ "Shakespeare","Hamlet" });
	authors.insert({ "Shakespeare","Macbeth" });
	authors.insert({ "Shakespeare","Coriolanus" });
	// print alphabetically ordered map
	for (auto i : authors) {
		cout << i.second << " by " << i.first << "." << endl;
	}
}

void wordTransform()
{
	std::ifstream rules("input1.txt");
	std::ifstream text("input2.txt");
	//transfer rules to map
	string key;
	string value;
	std::map<string, string> ruleMap;
	while (rules >> key) {
		rules.ignore();
		std::getline(rules, value);
		ruleMap.insert({key,value});
	}
	//loop through text applying rules, save result to string
	string result;
	string word;
	while (text >> word) {
		if (ruleMap.find(word) != ruleMap.end()) { //check if word is in map, then replace 
			result += ruleMap[word];
			result += " ";
		}
		else { // bypass words not found in map
			result += word;
			result += " ";
		}
		if (text.get() == '\n') { // check new line character
			result += '\n';
		}
	}
	// print string
	cout << result << endl;
}

void exer1138v1()
{
	// Word transformation program but with unordered map
	std::ifstream rules("input1.txt");
	std::ifstream text("input2.txt");
	//transfer rules to map
	string key;
	string value;
	std::unordered_map<string, string> ruleMap;
	while (rules >> key) {
		rules.ignore();
		std::getline(rules, value);
		ruleMap.insert({ key,value });
	}
	//loop through text applying rules, save result to string
	string result;
	string word;
	while (text >> word) {
		if (ruleMap.find(word) != ruleMap.end()) { //check if word is in map, then replace 
			result += ruleMap[word];
			result += " ";
		}
		else { // bypass words not found in map
			result += word;
			result += " ";
		}
		if (text.get() == '\n') { // check new line character
			result += '\n';
		}
	}
	// print string
	cout << result << endl;
}

void exer1138v2()
{
	std::unordered_map<string, std::size_t> word_count;
	string word;
	std::istringstream str_st("hello hello are you what is this");
	while (str_st >> word) {
		++word_count[word];
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
	}
}









