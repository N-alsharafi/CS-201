#include <iostream>
using namespace std;

bool meth(int s1, int s2, int s3) {
	if ((s1+s2) > s3) {
		if ((s1 + s3) > s2) {
			if ((s2 + s3) > s1) {
				return true;
			}
			
		}
	}
	else {
		return false;
	}
 


}

int main() {
	int side1, side2, side3;
	bool result = false;
	cout << "enter the 3 sides of the potential triangle: ";
	cin >> side1 >> side2 >> side3;
	result = meth(side1, side2, side3);
	if (result) {
		cout << "It is a triangle";
	}
	else {
		cout << "tis not a triangle";
	}




	return 0;
}