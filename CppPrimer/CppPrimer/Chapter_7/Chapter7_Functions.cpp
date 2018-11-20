#include "Chapter7_Functions.h"

void chapter_7()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 1).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << endl;


	//bookstore_program_exer71();
	//
	//Sales_data item1;
	//Sales_data item2 = Sales_data(cin);
	//Sales_data item3 = Sales_data("3293-23X");
	//Sales_data item4 = Sales_data("223-23X", 10, 20.0);

	//print(cout, item1); cout << endl;
	//print(cout, item2); cout << endl;
	//print(cout, item3); cout << endl;
	//print(cout, item4); cout << endl;
	//
	
	

	cout << "End\n";
	int end;
	cin >> end;

}

std::istream & read_person(std::istream & is, Person & persona)
{
	is >> persona.name >> persona.address;
	return is;
}

std::ostream & print_person(std::ostream & os, Person & persona)
{
	os << persona.getName() << " " << persona.getAddress();
	return os;
}

int bookstore_program_exer71()
{

	//Sales_data total;	// variable to hold data for the next transaction
	//// read the first transaction and ensure that there are data to process
	//if (cin >> total.bookNo >> total.price >> total.revenue >> total.units_sold) {
	//	Sales_data trans; // variable to hold the running sum
	//	// read and process the remaining transactions
	//	while (cin >> trans.bookNo >> trans.price >> trans.revenue >> trans.units_sold) {
	//		// if we're still processing the same book
	//		if (total.bookNo == trans.bookNo) {
	//			//total += trans; // update the running total
	//			total.revenue += trans.revenue;
	//			total.units_sold += trans.units_sold;
	//		}
	//		else {
	//			// print results for the previous book
	//			std::cout << "ISBN: " << total.bookNo << std::endl;
	//			std::cout << "Total Revenue: " << total.revenue << std::endl;
	//			std::cout << "Total units sold: "  << total.units_sold << std::endl;
	//			total = trans; // total now refers to the next book
	//		}
	//	}
	//	cout << "ISBN: " << total.bookNo << endl; //print the last transaction
	//	cout << "Price: " << total.price << endl; //print the last transaction
	//	cout << "Total Revenue: " << total.revenue << endl; //print the last transaction
	//	cout << "Total units sold: " << total.units_sold << endl; //print the last transaction
	//}
	//else {
	//	// no input! warn the user
	//	std::cerr << "No data?!" << endl;
	//	return -1; // indicate failure
	//}
	return 0;
}

int bookstore_program_exer73()
{
	//Sales_data total;	// variable to hold data for the next transaction
	//// read the first transaction and ensure that there are data to process
	//if (cin >> total.bookNo >> total.price >> total.revenue >> total.units_sold) {
	//	Sales_data trans; // variable to hold the running sum
	//	// read and process the remaining transactions
	//	while (cin >> trans.bookNo >> trans.price >> trans.revenue >> trans.units_sold) {
	//		// if we're still processing the same book
	//		if (total.isbn() == trans.isbn()) {
	//			//total += trans; // update the running total
	//			total.combine(trans);
	//		}
	//		else {
	//			// print results for the previous book
	//			std::cout << "ISBN: " << total.bookNo << std::endl;
	//			std::cout << "Total Revenue: " << total.revenue << std::endl;
	//			std::cout << "Total units sold: " << total.units_sold << std::endl;
	//			total = trans; // total now refers to the next book
	//		}
	//	}
	//	cout << "ISBN: " << total.bookNo << endl; //print the last transaction
	//	cout << "Price: " << total.price << endl; //print the last transaction
	//	cout << "Total Revenue: " << total.revenue << endl; //print the last transaction
	//	cout << "Total units sold: " << total.units_sold << endl; //print the last transaction
	//}
	//else {
	//	// no input! warn the user
	//	std::cerr << "No data?!" << endl;
	//	return -1; // indicate failure
	//}
	return 0;
}

int bookstore_program_exer77()
{
	Sales_data total;	// variable to hold data for the next transaction
	// read the first transaction and ensure that there are data to process
	if (read(cin,total)) {
		Sales_data trans; // variable to hold the running sum
		// read and process the remaining transactions
		while (read(cin,trans)) {
			// if we're still processing the same book
			if (total.isbn() == trans.isbn()) {
				//total += trans; // update the running total
				total.combine(trans);
			}
			else {
				// print results for the previous book
				print(cout, total); cout << endl;
				total = trans; // total now refers to the next book
			}
		}
		print(cout, total); cout << endl;
	}
	else {
		// no input! warn the user
		std::cerr << "No data?!" << endl;
		return -1; // indicate failure
	}
	return 0;
}

int bookstore_program_exer713()
{
	Sales_data total = Sales_data(cin);	// variable to hold data for the next transaction
	// read the first transaction and ensure that there are data to process
	if (cin ) {
		Sales_data trans = Sales_data(cin); // variable to hold the running sum
		// read and process the remaining transactions
		while (cin) {
			// if we're still processing the same book
			if (total.isbn() == trans.isbn()) {
				//total += trans; // update the running total
				total.combine(trans);
			}
			else {
				// print results for the previous book
				print(cout, total); cout << endl;
				total = trans; // total now refers to the next book
			}
		}
		print(cout, total); cout << endl;
	}
	else {
		// no input! warn the user
		std::cerr << "No data?!" << endl;
		return -1; // indicate failure
	}
	return 0;
}

std::istream &read(std::istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> item.price;
	item.revenue = item.units_sold * item.price;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
	os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.price;
	return os;
}

Sales_data add(Sales_data &item1, Sales_data & item2)
{
	Sales_data sum = item1;
	sum.combine(item2);
	return sum;

}



Sales_data & Sales_data::combine(const Sales_data & transaction)
{
	if (this->isbn() == transaction.isbn()) {
		this->revenue += transaction.revenue;
		this->units_sold += transaction.units_sold;
	}
	return *this;
}

string Sales_data::isbn() const
{
	return this->bookNo;
}

inline double Sales_data::avg_price() const
{
	return this->units_sold ? this->revenue / this->units_sold : 0;
}

string Person::getName() const
{
	return this->name;
}

string Person::getAddress() {	// const?
	return this->address;
}

inline char Screen::get(pos r, pos c) const
{
	pos row = width * r;
	return contents[row+c];

}

Screen & Screen::move(pos r, pos c)
{
	pos row = width + r;
	cursor = row + c;
	return *this;
	// TODO: insert return statement here
}

Screen & Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
	// TODO: insert return statement here
}

Screen & Screen::set(pos r, pos col, char c)
{
	pos row = r * width;
	contents[row + col] = c;
	return *this;
	// TODO: insert return statement here
}

