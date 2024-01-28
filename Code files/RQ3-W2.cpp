#include <iostream>
#include <string>
using namespace std;

int main() {
	string place_1, place_2;
	double distance, velocity_1, velocity_2, timee, meeting_distance;

	cout << "For car 1, where does the car depart from?\n";
	cin >> place_1; // you can't have multi-word inputs in cin
	cout << endl << "For car 2, where does the car depart from?\n";
	cin >> place_2;
	cout << endl << "For cars 1 & 2, enter their velocities(kmph) respectively:\n";

	cin >> velocity_1 >> velocity_2;
	cout << "Enter the distance between both cars(KM): ";
	cin >> distance; 
	timee = distance / (velocity_1 + velocity_2);
	meeting_distance = velocity_1 * timee;

	cout << "The cars will need " << timee << " hour(s) to meet and will meet " << meeting_distance
		<< " Kilometre(s) from " << place_1 << ", or " << distance-meeting_distance <<
		" from " << place_2 << ".";

	return 0;
}