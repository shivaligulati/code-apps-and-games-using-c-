#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	fstream fileStream;
	fileStream.open("test.txt", ios::out);
	if (fileStream.is_open()) {
		cout << "File opened successfully!" << endl;
		fileStream << "Saving this to the file." << endl;
	}
	fileStream.close();

	fileStream.open("test.txt", ios::in);
	string readWord;
	string readLine;

	if (fileStream.is_open()) {
		fileStream >> readWord;
		cout << readWord << endl;
		getline(fileStream, readLine);
	}
	fileStream.close();
	return 0;
}
