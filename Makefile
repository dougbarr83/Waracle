all: Test

Test:
	g++ -c -std=c++11 -Wall -Werror -fpic Test.cpp
	g++ -shared -std=c++11 -o libTest.so Test.o
	g++ -std=c++11 -L/home/doug/workspace/Test/src -Wl,-rpath=/home/doug/workspace/Test/src -Wall -o test main.cpp -lTest
	

clean: 
	rm Test.o libTest.so test
