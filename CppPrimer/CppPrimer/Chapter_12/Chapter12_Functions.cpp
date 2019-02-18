#include "Chapter12_Functions.h"


void chapter_12()
{

	exer121();
	cout << "------------\n";
	exer126();
	cout << "------------\n";
	exer127();
	cout << "------------\n";
	exer1216();
	cout << "------------\n";
	exer1217();
	cout << "------------\n";
	exer1220();
	cout << "------------\n";
	exer1222();
	cout << "------------\n";
	exer1223();
	cout << "------------\n";
	exer1224();
	cout << "------------\n";
	exer1226();
	cout << "------------\n";
	exer1228();
	cout << "------------\n";
	runQueries();
	cout << "------------\n";
	runQueries2();
	cout << "------------\n";

	cout << "---\nEnd\n";
	int end;
	cin >> end;
}

std::ostream & print2(std::ostream & os, const QueryResult & qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " times" << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	}
	return os;
}

void runQueries2()
{
	std::ifstream infile("query.txt");
	TextQuery2 tq = TextQuery2(infile);
	while (true) {
		cout << "Enter word to look for, or q to quit: ";
		std::string s;
		if (!(cin >> s) || s == "q") break;
		print2(cout, tq.query(s));
		cout << endl;
	}
}



void exer121()
{
	StrBlob b1;
	{
		StrBlob b2 = {"a","an","the"};
		b2.print();
		b1 = b2;
		b1.print();
		b2.push_back("about");
		b2.print();
		b1.print();
		cout << "Number of references: " << b1.get().use_count() << endl;
	}
	b1.print();
	cout << "Number of references: " << b1.get().use_count() << endl;
}

// Exercise 12.6
void exer126()
{
	auto *vec = exer126_1();
	std::istringstream string_stream("1 2 3 4 5");
	int num;
	while (string_stream >> num) {
		vec->push_back(num);
	}

	exer126_2(vec);

	delete vec;
}
std::vector<int>* exer126_1()
{
	std::vector<int> *vec = new std::vector<int>;
	return vec;
}
void exer126_2(std::vector<int> *vec) {
	for (auto i : *vec) {
		cout << i << " ";
	}
	cout << endl;
}


// Exercise 12.7
void exer127()
{
	std::shared_ptr<std::vector<int>> vec = exer127_1();
	std::istringstream string_stream("1 2 3 4 5");
	int num;
	while (string_stream >> num) {
		vec->push_back(num);
	}
	exer127_2(vec);

}
std::shared_ptr<std::vector<int>> exer127_1()
{
	std::shared_ptr<std::vector<int>> vec = std::make_shared<std::vector<int>>();
	return vec;
}
void exer127_2(std::shared_ptr<std::vector<int>> vec)
{
	for (auto i : *vec) {
		cout << i << " ";
	}
	cout << endl;
}

void exer1216()
{
	std::unique_ptr<int> p1;
	std::unique_ptr<int> p2(new int(42));

	std::unique_ptr<std::string> p3(new std::string("Stegosaurus"));
	//std::unique_ptr<std::string> p4(p3); // WRONG
	std::unique_ptr<std::string> p5;
//	p5 = p3; // WRONG
}

void exer1217()
{
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef std::unique_ptr<int> IntP;
	//IntP p0(ix);			// WRONG
	//IntP p1(pi);			// WRONG
	IntP p2(pi2);
	//IntP p3(&ix);			// WRONG
	IntP p4(new int(2048));
	//IntP p5(p2.get());	// WRONG

}

void exer1220()
{
	std::ifstream file("blob.txt");
	std::string line;
	std::vector<std::string> vec;
	std::string word;

	StrBlob obj1 = StrBlob();
	std::size_t sz = 0;
	StrBlobPtr obj2 = StrBlobPtr(obj1);
	while (std::getline(file, line)) {
		std::istringstream lineWords(line);
		while (lineWords >> word) {
			obj1.push_back(word);
			cout << obj2.deref() << " ";
			obj2.incr();

		}
		cout << endl;
	}
}

void exer1222()
{
	const StrBlob obj1 = StrBlob({"hello"});
	ConstStrBlobPtr obj2 = ConstStrBlobPtr(obj1);
	cout << obj2.deref() << endl;
}

void exer1223()
{
	std::string str1 = "hello there, ";
	std::string str2 = "my friend";
	str1 += str2;
	char *result = new char[str1.size() + 1];
	std::size_t size = str1.size() + 1;
	for (size_t i = 0; i != size; ++i) {
		result[i] = str1[i];
	}
	cout << result << endl;
	delete[] result;
}

void exer1224()
{
	std::istringstream strm("hello there my friend goodbye");
	std::string line;
	while (strm >> line) {
		std::string new_line = line;
		char *word = new char[new_line.size() + 1]; // allocate enough memory for the word from stdin
		for (size_t i = 0; i != new_line.size() +1; ++i) {
			word[i] = new_line[i];
		}
		cout << word << " ";
		delete[] word; // free the memory allocated for the char array
	}
	cout << endl;
}

void exer1226()
{
	std::istringstream strm("hello bye what is this how are you");
	size_t n = 8;               

	std::allocator<std::string> alloc;
	auto const p = alloc.allocate(n);
	std::string s; 
	auto q = p;

	while (strm >> s && q != p + n) {
		alloc.construct(q++, s);
	}
	const size_t size = q - p;
	cout << "Allocated: " << endl;
	for (auto i = p; i != q; ++i) {
		cout << *i << " ";
	}
	cout << endl;

	while (q != p) {
		alloc.destroy(--q);
	}
	alloc.deallocate(p, n);
	cout << endl;
	cout << "Deallocated: " << endl;
	for (auto i = p; i != q; ++i) {
		cout << *i << " ";
	}
}

void exer1228()
{
	std::ifstream file("query.txt");	// text file
	std::string search_word("when");	// word to search
	std::string line;					// current line that we are getting from file
	size_t line_count = 0;				// count of total lines in file
	size_t word_count = 0;				// how many times word appears in the text
	std::map<size_t, std::string> text;	// map data structure where the file is saved
	std::vector<size_t> tracked_lines;  // vector to keep track of the lines every time a word shows up. Every element is a line

	// save text file to map, ordered by line number
	while (std::getline(file,line)) {
		text[line_count++] = line;
	}

	// iterate through the map, looking for the search_word and keeping track of the lines
	for (auto i : text) {
		bool added = false; // boolean flag to only add the line once if found. Resetted every time there's a new line
		size_t pos = 0;
		while ((pos = i.second.find(search_word, pos)) != std::string::npos) { // if word is found in the current line
			if (!added) { // if flag not active it can add the line to vector
				tracked_lines.push_back(i.first);	// add line number to vector 
				added = true; // change flag, cant add the same line anymore
			}
			++word_count;
			++pos;
		}
	}

	// print results
	cout << search_word << " occurs " << word_count << " times:" << endl;
	for (auto i : tracked_lines) {
		cout << "(line " << i << ") " << text[i] << endl;
	}
}

void runQueries()
{
	std::ifstream infile("query.txt");
	TextQuery tq = TextQuery(infile);
	while (true) {
		cout << "Enter word to look for, or q to quit: ";
		std::string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s));
		cout << endl;
	}
}

void print(std::ostream &os, std::ostringstream query)
{
	os << query.str();
}

void exer1229()
{
	std::ifstream infile("query.txt");
	TextQuery tq = TextQuery(infile);
	do {
		cout << "Enter word to look for, or q to quit: ";
		std::string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s));
		cout << endl;
	} while (true);
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this,data->size());
}

// default constructor
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

// list initialize constructor
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::pop_back()
{
	check(0, "pop back on empty StrBlob");
	data->pop_back();
}

std::string & StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string & StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::print()
{
	for (auto i = data->begin(); i != data->end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}

std::shared_ptr<std::vector<std::string>>& StrBlob::get()
{
	return data;
}

void StrBlob::check(size_type i, const std::string & msg)
{
	if (i >= data->size()) {
		throw std::out_of_range(msg);
	}
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const 
{	
	auto ret = wptr.lock(); // is the vector still around?
	if (!ret) {
		throw std::runtime_error("Unbound StrBlobPtr");
	}
	if (i >= ret->size()) {
		throw std::out_of_range(msg);
	}
	return ret;
}

std::string& StrBlobPtr::deref() const 
{
	auto p = check(curr,"Dereference past end");
	return (*p)[curr];	// (*p) is the vector to whicj the object points
}

StrBlobPtr& StrBlobPtr::incr() 
{
	check(curr, "increment op ");
	++curr;
	return *this;
}

std::string & ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "Dereference past end");
	return (*p)[curr];	// (*p) is the vector to whicj the object points
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string & msg) const
{
	auto ret = wptr.lock(); // is the vector still around?
	if (!ret) {
		throw std::runtime_error("Unbound StrBlobPtr");
	}
	if (i >= ret->size()) {
		throw std::out_of_range(msg);
	}
	return ret;
}

TextQuery::TextQuery(std::ifstream &infile)
{
	// get text data into vector
	std::string line;
	while (std::getline(infile, line)) {
		lines.push_back(line);
	}

	//create map of words/lines
	// iterate through lines, to each word assign a line in set
	for (size_t i = 0; i != lines.size(); ++i) { // for (string s : lines)
		std::istringstream words(lines[i]);
		std::string word;
		while (words >> word) {
			std::set<size_t> myset = queryMap[word];
			myset.insert(i);
			queryMap[word] = myset;
		}
	}

	// print map
//	for (auto i : queryMap) {
//		cout << i.first << ": ";
//		for (auto j : i.second) {
//			cout << j << " ";
//		}
//		cout << endl;
//	}

}

std::ostringstream TextQuery::query(std::string & s)
{
	std::set<size_t> myset = queryMap[s];
	size_t occurs = myset.size();
	std::ostringstream stringResult;
	stringResult << s << " occurs " << occurs << " times:" << endl;
	for (auto l : myset) {
		stringResult << "(line " << l << ") " << lines[l] << endl;
	}
	return stringResult;
}

TextQuery2::TextQuery2(std::ifstream &infile) : file(new std::vector<std::string>)
{
	std::string line;
	while (std::getline(infile, line)) {
		file->push_back(line);
	}

	//create map of words/lines
	// iterate through lines, to each word assign a line in set
	for (size_t i = 0; i != file->size(); ++i) { // for (string s : lines)
		std::istringstream words(file->at(i));
		std::string word;
		while (words >> word) {
			auto &lines = wordsMap[word];
			if (!lines) {
				lines.reset(new std::set<line_no>);
			}
			lines->insert(i);
		}
	}
}

QueryResult TextQuery2::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto p = wordsMap.find(sought);
	if (p == wordsMap.end()) {
		return QueryResult(sought,nodata,file);
	}
	else {
		return QueryResult(sought, p->second, file);
	}
}

std::set<TextQuery2::line_no>::iterator QueryResult::begin()
{
	return lines->begin();
}

std::set<TextQuery2::line_no>::iterator QueryResult::end()
{
	return lines->end();
}

std::shared_ptr<std::vector<std::string>> QueryResult::get_file()
{
	return file;
}
