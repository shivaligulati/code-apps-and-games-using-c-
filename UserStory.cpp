
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{

	string animal;
	string location;
	string adjective;
	string plant;
	string plant2;
	string name;
	string job;
	string action;
	string city;


	cout << "An adjective: ";
	cin >> adjective;
	cout << "An animal: ";
	cin >> animal;
	cout << "A location: ";
	cin >> location;
	cout << "A plant: ";
	cin >> plant;
	cout << "Another plant: ";
	cin >> plant2;
	cout << "A name: ";
	cin >> name;
	cout << "A job: ";
	cin >> job;
	cout << "An action/verb : ";
	cin >> action;
	cout << "A place : ";
	cin >> city;


	cout << "Once upon a time, there was a happy " << animal << endl;
	cout << "The " << animal << " lived by the " << location << endl;
	cout << "He ate " << plant << " and " << plant2 << endl;
	cout << "People thought the " << animal << " was too " << adjective << endl;
	cout << "The people sent " << name << ", the village's " << job << " to " << action << " the " << animal << endl;
	cout << "The " << animal << " thought that sounded unpleasant, so he left the " << location << endl;
	cout << "Now he lives in the " << city << " and eats the " << plant << " and " << plant2 << " there instead." << endl;
	return 0;
}