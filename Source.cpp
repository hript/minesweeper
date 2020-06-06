#include<iostream>
#include<ctime>
#include<Windows.h>

#define SIZE_OF_FIELD 10 
#define PART_OF_FIELD 0.2
#define MINE_CHAR 'X'
#define EMPTY '*'


using namespace std;

char** fieldMine;
char** fieldPlayer;

void initField(char** field, char c) {
	

	for (int i = 0; i < SIZE_OF_FIELD; i++) {
		for (int j = 0; j < SIZE_OF_FIELD; j++) {
			field[i][j] = c;
		}
	}
	
}
void landMines(char** field){
	int pos_row, pos_column;
	do {
		 pos_row = rand() % SIZE_OF_FIELD;
		 pos_column = rand() % SIZE_OF_FIELD;

	} while (field[pos_row][pos_column] == MINE_CHAR);
	field[pos_row][pos_column] = MINE_CHAR;
}

void showField(char** field) {
	for (int i = 0; i < SIZE_OF_FIELD; i++) {
		for (int j = 0; j < SIZE_OF_FIELD; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

int countNeib(int row, int column) {
	int count = 0;
	for (int i = row - 1; i <= row + 1; i++) {
		for (int j = column - 1; j <= column + 1; j++) {
			if (i >= 0 && j >= 0 && i < SIZE_OF_FIELD && j < SIZE_OF_FIELD && fieldMine[i][j] == MINE_CHAR) {
				count += 1;
			}
		}
	}
	return count;
}
bool openCell(int row, int column) {
	if (fieldMine[row][column] == MINE_CHAR)
		return false;

	int count = countNeib(row, column);

	fieldPlayer[row][column] = '0' + count;
	
	if (count == 0) {
		for (int i = row - 1; i <= row + 1; i++) {
			for (int j = column - 1; j <= column + 1; j++) {
				if (i >= 0 && j >= 0 && i < SIZE_OF_FIELD && j < SIZE_OF_FIELD) {
					if (i == row && j == column)
						continue;
					if (fieldPlayer[i][j] == EMPTY)
						openCell(i, j);


				}
			}
		}
	}
	return true;
}

int main()
{
	srand(time(0));
	
	int countOfMines = SIZE_OF_FIELD * SIZE_OF_FIELD * PART_OF_FIELD;

	fieldMine = new char* [SIZE_OF_FIELD];
	for (int i = 0; i < SIZE_OF_FIELD; i++)
		fieldMine[i] = new char[SIZE_OF_FIELD];

	fieldPlayer = new char* [SIZE_OF_FIELD];
	for (int i = 0; i < SIZE_OF_FIELD; i++)
		fieldPlayer[i] = new char[SIZE_OF_FIELD];

	initField(fieldMine, EMPTY);
	initField(fieldPlayer, EMPTY);

	for (int i = 0; i < countOfMines; i++) {
		landMines(fieldMine);
	}

	showField(fieldMine);
	cout << endl;

	int row, column;
	cin >> row >> column;
	row -= 1;
	column -= 1;

	if (fieldMine[row][column] == MINE_CHAR) {
		fieldMine[row][column] = EMPTY;
	}

	while (1) {
		openCell(row , column);
		//system("cls");
		showField(fieldPlayer);
		cin >> row >> column;
		row -= 1;
		column -= 1;
		if (!openCell(row, column))
			return 0;
		
	}

	return 0;
}