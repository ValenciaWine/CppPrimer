#include "Chapter_6/Chapter6_Functions.h"
#include "Chapter_7/Chapter7_Functions.h"
#include "Chapter_8/Chapter8_Functions.h"
#include "Chapter_9/Chapter9_Functions.h"
#define NDEBUG


int main(int argc,char**argv)
{

	//chapter_6();

	string filename = argv[1];
	string filename_out = argv[2];
	//cout << argv[1] << endl;
	//chapter_7(filename, filename_out);
	

	//const string filename = "filename.txt";

	//chapter_8(filename);
	chapter_9();


	return 0;

}