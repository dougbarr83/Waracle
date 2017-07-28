#include "Test.h"

using namespace std;


/**
 * Program entry point. The program accepts two runtime arguments - input file location and output file location.
 *
 * Example: ./test input.txt output.txt
 * */
int main(int argc, char *argv[])
{
	int result = 0;
	Test tester;

	if(argc != 3){
		cout<<"Please provide two arguments - input file location and output file location.\n\n";
	}
	else{
		result = tester.analyse(argv[1],argv[2]);
	}

    return result;
}
