

#include <iostream>
using namespace std;

int main() {
	double filesize, connectionspeed;

	cout << "Enter the filesize in MB:\n";
	cin >> filesize;
	cout << endl << "Enter the connection speed in bps:\n"; //this can be entered in 8e+6 format
	cin >> connectionspeed;

	connectionspeed = connectionspeed / (8 * 1024 * 1024); //changes speed to MBps

	int time; //this variable has to be an int in other for modulus operation to work
	//also for the time/3600 we need time to be an integer
	time = filesize / connectionspeed;

	cout << "\nThe file will take " << time / 3600 << " hours and " << (time % 3600)/60 
		<< " minutes and " << (time % 60) << " seconds.";

	return 0;
}