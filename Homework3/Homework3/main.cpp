#include <iostream>
#include <string>
using namespace std;

int intInputCheck();
	//do while loop that makes sure the input integer is even and positive
string strInputCheck(string who, string what);
	//do while loop to get correct inputs for the code and guesses
string determineCoder(string p1, string p2, int run);
	//if statement that determines whose turn it is
string determineGuesser(string p1, string p2, int run);
	//if statement that determines who has to guess the code
string colorfeedback(string code, string guess);
	//this function takes the code and guess and returns the respective RRWW values
void pointKeeping(string who, string p1, string p2, int& p1points, int& p2points);


int main() {
	string player1, player2, turn, notTurn;
	string code, guess, feedback;
	int run = 1, runs = 0;
	int player1points = 0, player2points = 0;
	cout << "Please enter the names of the players: ";
	cin >> player1 >> player2;
	cout << "Welcome " << player1 << " and " << player2 << endl << endl;

	runs = intInputCheck();

	while (run <= runs) {
		//this loop is missing the point keeping
		bool flag = false;
		turn = determineCoder(player1, player2, run); //returns the name of the codemaker
		notTurn = determineGuesser(player1, player2, run); //returns the name of the codebreaker
		
		cout << endl <<  turn << ", it is your turn to select the secret!\n";
		cout << "Valid colors: R - Red, G - Green, B - Blue, P - Purple, Y - Yellow, M - Magenta\n";

		code = strInputCheck(turn, "secret");
		cout << endl;

		for (int i = 0;  i < 6; i++) { //this is the guesses loop
			guess = strInputCheck(notTurn, "guess");
			feedback = colorfeedback(code, guess);

			if (feedback == "RRRR") { //the statement that checks if the player correctly
				//guessed the code and displays a winning message for the round
				cout << notTurn << ", you won this run!\n";
				pointKeeping(notTurn, player1, player2, player1points, player2points);
				flag = true;
				i = 6; //this should stop the loop
			}
			else {
				cout << feedback << endl;
				pointKeeping(turn, player1, player2, player1points, player2points);
			}
			
		}
		if (!flag) {
			cout << notTurn << ", you're out of chances, you lost this run!\n";
			pointKeeping(turn, player1, player2, player1points, player2points);
		}
		run++;
	}

	cout << "\nThe game has ended!\n";
	cout << player1 << ": " << player1points << " - " << player2 << ": " << player2points << endl << endl;
	if (player1points == player2points) {
		cout << player1 << " and " << player2 << ", there is a tie!";
	}
	else if (player1points > player2points) {
		cout << "Congrats " << player1 << ", you have won the game!";
	}
	else {
		cout << "Congrats " << player2 << ", you have won the game!";
	}

	return 0;
}


int intInputCheck() {
	int noOfruns = 0;
	bool flag = true;
	while (flag) {
		cout << "Please enter the number of runs: ";
		cin >> noOfruns;
		if (noOfruns > 0 && (noOfruns % 2) != 1) {
			flag = false;
		}
		else {
			cout << "Invalid number of runs!\n";
		}
	}
	
	return noOfruns;
}

string strInputCheck(string who, string what) {
	//the workings of this function are suspicious
	bool stringflag = false;
	string input;
	while(!stringflag) {
		bool containsflag = true;
		string validInput = "RGBPYM";
		cout << who << ", please enter your " << what << ": ";
		cin >> input;
		

		if (input.length() != 4) {
			cout << "Invalid " << what << "!\n";
		}
		else if (input.length()==4) {
			for (int i = 0; i < 4; i++) {
				if (validInput.find(input[i]) == string::npos) {
					containsflag = false;

				}
				else {
					validInput.erase(validInput.find(input[i]), 1);
				}
			}

			if (containsflag) {
				stringflag = true;
			}
			
		}
		if (!containsflag){
			cout << "Invalid " << what << "!\n";
		}
	}
	return input;
}

string determineCoder(string p1, string p2, int run) {
	if (run % 2 == 1) {
		return p1;
	}
	else {
		return p2;
	}
}

string determineGuesser(string p1, string p2, int run) {
	if (run % 2 == 1) {
		return p2;
	}
	else {
		return p1;
	}
}

string colorfeedback(string code, string guess) {
	//remove as many ws as there are rs
	string feedback, Ws;
	for (int i = 0; i < 4; i++) {
		if (code[i] == guess[i]) {
			feedback += "R";
		}
	} // this loop checks if we have Rs, correct color and position
	for (int i = 0; i < 4; i++) {
		if (code.find(guess[i]) != string::npos) {
			Ws += "W";
		}
	}
	Ws.erase(0, feedback.length());
	return feedback+Ws;
}

void pointKeeping(string who, string p1, string p2, int& p1points, int& p2points) {
	if (who == p1) {
		p1points++;
	}
	if (who == p2) {
		p2points++;
	}
}