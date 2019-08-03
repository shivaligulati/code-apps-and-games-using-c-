#include "pch.h"
#include <iostream>
using namespace std;

// function which prints the grid
void printBoard(int grid[9][9]) {
	cout << "" << endl;
	cout << "   1 2 3   4 5 6   7 8 9" << endl;
	cout << "  ***********************" << endl;
	// makes the grid print 
	for (int i = 0; i < 9; i++) {
		cout << i+1 << "| ";
		
		//makes all zero array elements blank
		for (int j = 0; j < 9; j++) {
			if (grid[i][j] == 0) {
				cout << "  ";
			}
			else {
				cout << grid[i][j] << " ";
			}

			//prints vertical lines of the grid
			if (j % 3 == 2 && j != 8) {
				cout << "| ";
			}
		}
		cout << endl;
		// prints horizontal lines of the grid 
		if (i % 3 == 2 && i != 8) {
			cout << "-------------------------" << endl;
		}
	}
}

bool checkBoard(int grid[9][9]) {
	bool check[9] = { false, false, false, false, false, false, false, false, false };

	check rows of sedoku board for repeats
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << "Checking position: (" << i << ", " << j << "): " << grid[i][j] << endl;

			//if the value equals zero, it is not valid. 
			if (grid[i][j] == 0) {
				return false;
			}
			if (check[grid[i][j] - 1]) {
				return false;
			}
			else {
				check[grid[i][j] - 1] = true;
			}
		}
		//reset
		for (int j = 0; j < 9; j++) {
			check[j] = false;
		}
	}

	//check columns of sedoku board for repeats 
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			//if the value equals zero, it is not valid. 
			if (grid[j][i] == 0) {
				return false;
			}
			cout << "Checking position: (" << i << ", " << j << "): " << grid[i][j] << endl;
			if (check[grid[j][i] - 1]) {
				return false;
			}
			else {
				check[grid[j][i] - 1] = true;
			}
		}
		for (int j = 0; j < 9; j++) {
			check[j] = false;
		}
	}

	//3x3 box code
	int colStart = 0;
	int rowStart = 0;

	int col = 3;
	int row = 3;
	int runcount = 0;
	bool running = true;

	while (running) {
		for (int i = colStart; i < col; i++) {
			for (int j = rowStart; j < row; j++) {
				//cout << "Testing: " << grid[i][j] << " from row: " << i << " and column: " << j << endl;
				if (grid[j][i] == 0) {
					//no number has been inputted into this slot so by default we fail
					return false;
				}
				else {
					if (check[grid[j][i] - 1] == true) {
						//number has already been seen in this row
						return false;
					}
					else {
						check[grid[j][i] - 1] = true;
					}
				}
			}
		}
		//reset array for next pass
		for (int j = 0; j < 9; j++) {
			check[j] = false;
		}

		col += 3;
		colStart += 3;
		if (colStart >= 9) {
			col = 3;
			colStart = 0;
			row += 3;
			rowStart += 3;
			if (rowStart >= 9) {
				running = false;
				break;
			}
		}
	}

}


int main()
{
	//title information + instructions on how to play (add later)
	cout << "" << endl;
	cout << "Welcome to my Sudoku Game!" << endl;
	cout << "" << endl;

	//2D arrays for grid and solution of soduku
	int grid[9][9] = {
		{0, 5, 3, 2, 0, 7, 0, 0, 8},
		{ 6, 0, 1, 5, 0, 0, 0, 0, 2},
		{ 2, 0, 0, 9, 1, 3, 0, 5, 0},
		{ 7, 1, 4, 6, 9, 2, 0, 0, 0},
		{ 0, 2, 0, 0, 0, 0, 0, 6, 0},
		{ 0, 0, 0, 4, 5, 1, 2, 9, 7},
		{ 0, 6, 0, 3, 2, 5, 0, 0, 9},
		{1, 0, 0, 0, 0, 6, 3, 0, 4},
		{8, 0, 0, 1, 0, 9, 6, 7,0 },
	};
	int gridStart[9][9] = {
		{0, 5, 3, 2, 0, 7, 0, 0, 8},
		{ 6, 0, 1, 5, 0, 0, 0, 0, 2},
		{ 2, 0, 0, 9, 1, 3, 0, 5, 0},
		{ 7, 1, 4, 6, 9, 2, 0, 0, 0},
		{ 0, 2, 0, 0, 0, 0, 0, 6, 0},
		{ 0, 0, 0, 4, 5, 1, 2, 9, 7},
		{ 0, 6, 0, 3, 2, 5, 0, 0, 9},
		{1, 0, 0, 0, 0, 6, 3, 0, 4},
		{8, 0, 0, 1, 0, 9, 6, 7,0 },
	};

	int solution[9][9] = {
		{9, 5, 3, 2, 6, 7, 1, 4, 8},
		{ 6, 7, 1, 5, 8, 4, 9, 3, 2},
		{ 2, 4, 8, 9, 1, 3, 7, 5, 6},
		{ 7, 1, 4, 6, 9, 2, 5, 8, 3},
		{ 5, 2, 9, 7, 3, 8, 4, 6, 1},
		{ 3, 8, 6, 4, 5, 1, 2, 9, 7},
		{ 4, 6, 7, 3, 2, 5, 8, 1, 9},
		{1, 9, 5, 8, 7, 6, 3, 2, 4},
		{8, 3, 2, 1, 4, 9, 6, 7,5 },
	};


	int coordinateRow;
	int coordinateColumn;
	//loops sudoku code so user can keep inputting values 
	while (true) {
		printBoard(grid);
	
		//input coordinate (what row, what column)
		while (true) {
			cout << "" << endl;
			cout << "Enter column #:" << endl;
			cin >> coordinateColumn;
			cout << "Enter row #:" << endl;
			cin >> coordinateRow;
			cout << endl;

			if (gridStart[coordinateRow - 1][coordinateColumn - 1] == 0) {
				break;
			}
			else {
				cout << "You can't place a number here. Try again." << endl;
			}
		}
		
		//value to replace in specified slot (1-9)
		int value;
		while (true) {
			cout << "Enter number for slot: (" << coordinateColumn << ", " << coordinateRow << ")" << endl;
			cin >> value;
			if (value > 0 && value <= 9) {
				break;
			}
			else {
				cout << "Invalid number. Try again." << endl;
			}
		}

		// sets value equal to blank value in coordinate specified above
		grid[coordinateRow - 1][coordinateColumn - 1] = value;

		if (checkBoard(grid)) {
			cout << "succeed" << endl;
			break;
		}
		else {
			cout << "You have not completed the puzzle. Continue playing." << endl;
		}
	}

	return 0;
};

