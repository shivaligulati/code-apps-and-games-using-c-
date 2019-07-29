#include "pch.h"
#include <iostream>
#include <random> 
using namespace std;

int main() {
	while (true) {
		int playerChoice;
		random_device rd;
		cout << "Choose an attack 1-3:" << endl;
		cout << "1) Sword Smash" << endl;
		cout << "2) Fire Exploder" << endl;
		cout << "3) Sneaky Dagger" << endl;
		cin >> playerChoice;

		switch (playerChoice) {
		case 1:
			cout << " You swing away with your sword!" << endl;
			break;
		case 2:
			cout << "You shoot a ton of fire out of your hands!" << endl;
			break;
		case 3:
			cout << "You poke at the enemy with your dagger!" << endl;
			break;
		default:
			cout << "You trip over your own feet and skip your turn!" << endl;
		}

		int enemyChoice = rd() % 3;
		switch (enemyChoice) {
		case 0:
			cout << "Your enemy runs at you with his sword" << endl;
			break;
		case 1:
			cout << "Your enemy shoots fireballs at you" << endl;
			break;
		case 2:
			cout << "Your enemy disappears, only to reappear next to you holding a dagger" << endl;
			break;
		}

	}
}
