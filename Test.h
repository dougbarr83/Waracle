#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::fstream;
using std::string;


class Test{
private:
	//stores the number of numbers read from the input file
	int counter;
	//stores the sum of the numbers from the input file
	int sum;

private:
	/**
	 * This function reads the numbers from the input file and records relevant data about them
	 * @param file: the file stream used to read the input numbers from
	 * @return: 0 for successful operation, -1 if an error is detected
	 * **/
	int get_numbers(fstream &file);

	/**
	 * This function takes the stats generated from the input file and stores them in the
	 * specified output file
	 * @param output_file: the location of the output file to be written to
	 * @return: 0 for successful operation, -1 if an error is detected
	 * **/
	int output_to_file(const char *const ouput_file)const;
public:
	/**
	 * This is the only public function of the class. It reads numbers from an input file and ouputs
	 * associated stats to an output file.
	 *
	 * @param input: location of input file containing numbers
	 * @param output: location of file which will have output read to
	 * @return: 0 for successful operation, -1 if an error is detected
	 * **/
    int analyse(const char *const input, const char *const output);

    /**
     * Test object constructor
     * */
    Test();

};
