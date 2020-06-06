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
	field = new char* [SIZE_OF_FIELD];

	for (int i = 0; i < SIZE_OF_FIELD; i++)
		field[i] = new char[SIZE_OF_FIELD];

	for (int i = 0; i < SIZE_OF_FIELD; i++) {
		for (int j = 0; j < SIZE_OF_FIELD; j++) {
			field[i][j] = c;
		}
	}
	
}
void landMines(){
	int pos_row, pos_column;
	do {
		 pos_row = rand() % SIZE_OF_FIELD;
		 pos_column = rand() % SIZE_OF_FIELD;

	} while (fieldMine[pos_row][pos_column] == MINE_CHAR);
	fieldMine[pos_row][pos_column] = MINE_CHAR;
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

	fieldPlayer[row][column] = '0' + countNeib(row, column);

	return true;
}

int main()
{
	srand(time(0));
	
	int countOfMines = SIZE_OF_FIELD * SIZE_OF_FIELD * PART_OF_FIELD;

	initField(fieldMine, EMPTY);
	initField(fieldPlayer, EMPTY);

	for (int i = 0; i < countOfMines; i++) {
		landMines();
	}

	int row, column;
	cin >> row >> column;

	if (fieldMine[row][column] == MINE_CHAR) {
		fieldMine[row][column] = EMPTY;
	}

	//showField();

	return 0;
}