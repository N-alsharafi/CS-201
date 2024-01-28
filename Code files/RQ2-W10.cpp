#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;


bool isUpper(char l) {
	if (l >= 'A' && l <= 'Z') {
		return true;
	}
	return false;
}

bool isLower(char l) {
	if (l >= 'a' && l <= 'z') {
		return true;
	}
	return false;
}

int countWords(string str)
{
	// Breaking input into word 
	// using string stream

	// Used for breaking words
	stringstream s(str);

	// To store individual words
	string word;

	int count = 0;
	while (s >> word)
		count++;
	return count;
}

void processFile(ifstream& input, ofstream& output) {
	vector<string> contents;
	string line;
	while (getline(input, line)) {
		if (line != "") {
			contents.push_back(line); //this could be done without the vector
		}
	}

	for (int i = 0; i < contents.size(); i++) {
		cout << contents[i] << endl;
		output << contents[i] << endl;
	}
}

void addNewLine(ifstream& input, ofstream& output) {
	char character;
	while (input.get(character)) {
		if (character == '.') {
			output << character << endl;
		}
		else {
			output << character;
		}
	}
}

void upToLow(ifstream& input, ofstream& output) {
	char letter;
	while (input.get(letter)) {
		if (isUpper(letter)) {
			letter = letter + ('a' - 'A');
		}
		else if (isLower(letter)){
			letter = letter - ('a' - 'A');
		}
		output << letter;
	}
}

void wordCount(ifstream& input, ofstream& output) {
	string line, word;
	int counter;
	while (getline(input, line)) {
		cout << countWords(line) << endl;
		output << countWords(line) << endl;
	}
}

int main() {
	string inFileName, outFileName;
	ifstream contents; //i for input

	cout << "Enter infile name: ";
	cin >> inFileName;
	contents.open(inFileName.c_str());

	if (contents.fail()) {
		cout << "Error 404";
	}
	else {
		cout << "Enter outfile name: ";
		cin >> outFileName;

		ofstream output; //o for output
		output.open(outFileName.c_str());
		if (output.fail()) {
			cout << "Error 404 for output file.";
		}
		else {
			//processFile(contents, output);
			//addNewLine(contents, output);
			//upToLow(contents, output);
			wordCount(contents, output);
		}
	}

	

	
}