// this is the comment syntax

#include <iostream>
// this is a standard library that's usually included in order to use input/output streams
// using namespace std;   is like doing 'from time import *' in python

int main() {
	std::cout << "please enter your name: ";
	std::string name;
	std::cin >> name;
	//int stands for integer function
	//if we want to exit the function here we put return 0;
	std::cout << "Hello world!\n";
	std::cout << "Hello " << name;
	return 0;
	//we return 0 because it's an int function, to have a proper ending.
}