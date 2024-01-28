#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "strutils.h"
using namespace std;

void insertSort(vector<string>& a, int size) {
	int k, loc;
	for (k = 1; k < size; k++) {
		string hold = a[k];
		loc = k;
		while (0 < loc && hold < a[loc - 1]) {
			a[loc] = a[loc - 1];
			loc--;
		}
		a[loc] = hold;
	}
}


int bsearch(const vector<string>& list, const string& key) {
	// pre: list.size() == # elements in list
	// post: returns index of key in list, -1 if key not found
	int low = 0;                   // leftmost possible entry
	int high = list.size() - 1;      // rightmost possible entry
	int mid;                       // middle of current range

	while (low <= high) {
		mid = (low + high) / 2;
		if (list[mid] == key)       // found key, exit search
			return mid;
		else if (list[mid] < key)   // key in upper half
			low = mid + 1;
		else                        // key in lower half
			high = mid - 1;
	}
	return -1;                      // not in list
}

int seqSearch(const vector<string>& list, const string& key) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == key) {
			return i;
		}
	}
	return -1;
}


bool spellCheck(const string& word, const string& searchtype, const vector<string> dictionary) {
	int index;
	if (searchtype == "sequential") {
		index = seqSearch(dictionary, word);
	}
	else if (searchtype == "binary") {
		index = bsearch(dictionary, word);
	}
	if (index != -1) {
		return true;
	}
	else {
		return false;
	}
}





int main() {
	string infile, word, searchType;
	ifstream firstFile, dictionary;
	ofstream output;

	cout << "Enter the name of the file to be spell-checked: ";
	cin >> infile;

	firstFile.open(infile.c_str());

	if (firstFile.fail()) {
		cout << "Error 404: could not find file";
		return 0;
	}

	//This section is for opening the dat file
	string filename = "words.dat";
	dictionary.open(filename.c_str());

	vector <string> dict;
	string something;
	while (dictionary >> something) {
		dict.push_back(something);
	}
	dictionary.close();
	insertSort(dict, dict.size()); //I should only do this if im doing binary search, 
	//but I do for both anyways
	//words inside dictionary now

	cout << "Which search type do you want: ";
	cin >> searchType;

	string outputfile = "output.txt";
	output.open(outputfile.c_str());

	while (firstFile >> word) {
		ToLower(word);
		StripPunc(word); //to remove punctuation

		if (!spellCheck(word, searchType, dict)) {
			cout << word << " Is spelled incorrectly\n";
			output << word << " Is spelled incorrectly\n";
		}
	}
	
	output.close();
	return 0;
}