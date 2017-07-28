#include "Test.h"

Test::Test():counter(0),sum(0)
{

}

int Test::analyse(const char *const input, const char *const output){
	int result = -1;
	fstream file;
	file.open(input,fstream::in);
	if(file.is_open()){
		if(get_numbers(file) == 0){
			if(output_to_file(output) !=0){
				cout<<"Failed to write to the output file!\n\n";
			}
		}
		else{
			cout<<"Failed to get numbers from file "<<input<<" \n\n";
		}
	}
	else{
		cout<<"Failed to open input file for reading!\n\n";
	}
	file.close();
	return result;
}


int Test::get_numbers(fstream &file){
	int result = 0;
	string line = "";
	while(getline(file,line)){
		try{
			const int number = std::stoi(line);
			counter++;
			sum+=number;
		}
		catch(std::out_of_range &e){
			cout<<"line from file is out of range! line: "<<line<<"\n";
			result = -1;
			break;
		}
		catch(std::invalid_argument &e){
			cout<<"line from file cannot be converted to a number! line: "<<line<<"\n";
			result = -1;
			break;
		}

	}
	return result;
}

int Test::output_to_file(const char *const output_file)const{
	int result = -1;
	fstream file;
	file.open(output_file,fstream::out|fstream::trunc);
	if(file.is_open()){
		file <<counter<<"\n";
		file <<sum<<"\n";
		file <<(sum/counter)<<"\n";
		result = 0;
	}
	else{
		cout<<"Failed to open the output file for writing!\n\n";
	}
	file.close();
	return result;
}
