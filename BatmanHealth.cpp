
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int pointsUser = 0;
	int pointsBatman = 0;
	int userInput;
	cout << "Who would win in a fight, you or Batman?" << endl;
	cout << "Answer these questions to find out!" << endl;
	cout << "On a scale of 1 to 10, how strong are you?" << endl;
	cin >> userInput;
	if (userInput > 7) {
		pointsUser += 1;
	}
	else {
		pointsBatman += 1;
	}
	cout << "On a scale of 1 to 10, how tactical of a planner are you?" << endl;
	cin >> userInput;
	if (userInput <= 8) {
		pointsBatman += 1;
	}
	else {
		pointsUser += 1;
	}
	char userYN;
	cout << "Would you be terrified of a giant bat flying at you? (y/n)" << endl;
	cin >> userYN;
	if (userYN != 'n') {
		pointsBatman += 1;
	}
	else {
		pointsUser += 1;
	}
	if (pointsUser > pointsBatman) {
		//Remember, the Batman wins ties!
		cout << "Batman wins!" << endl;
	}
	else {
		cout << "You win! Are you sure you aren't the Batman?" << endl;
	}
	return 0;
}


