
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int numberOfLeaves = 14;
	for (int i = 0; i < numberOfLeaves; i++) {
		cout << "A leaf fell to the ground." << i + 1 << " leaves have fallen." << endl;
	}
	cout << "All the leaves fell." << endl;
	return 0;
}

int blast() {
	for (int count = 10; count >= 0; count--) {
		if (count == 5) {
			continue;
		}
		cout << count << endl;
		if (count == 0) {
			cout << "Blastoff!" << endl;
		}
	}
	return 0;
}

int choicefun() {
	int choice;
	cout << "Enter in your choice!" << endl;
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "That's a good choice." << endl;
		break;
	case 2:
		cout << "That's a bad choice." << endl;
		break;
	case 3:
		cout << "That's a choice a kitty cat would make." << endl;
		break;
	}
	default:
		cout << "Choosing not to decide, you still have made a choice." << endl;
		break;
	}
	return 0;
}