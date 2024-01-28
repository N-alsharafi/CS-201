#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printContent(vector<vector<int>> input) {
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[0].size(); j++) {
			cout << input[i][j] << " ";
		}
		cout << endl;
	}

}

int sumOfColumn(vector<vector<int>> input, int column) {
	//pre: column is a column number, starting from 0
	int sum = 0;
	for (int i = 0; i < input[0].size(); i++) {
		sum += input[i][column];
	}
	return sum;
}

//the last 2 parts are just more of the same...

int main() {
	int m, n;
	cout << "Enter the dimensions of the matrix as m*n: ";
	cin >> m >> n;
	vector <vector <int> > matrix(m, vector <int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int element;
			cout << "Enter the element for row " << i << " and column " << j << ": ";
			cin >> element;
			matrix[i][j] = element;
		}
	}
	printContent(matrix);
	cout << sumOfColumn(matrix, 0);
	return 0;
}