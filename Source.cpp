#include<iostream>
#include<ctime>
#include<Windows.h>

#define SIZE_OF_FIELD 10 
#define PART_OF_FIELD 0.2
#define MINE_CHAR 'X'

using namespace std;

char field[SIZE_OF_FIELD][SIZE_OF_FIELD];

void initField() {
	for (int i = 0; i < SIZE_OF_FIELD; i++) {
		for (int j = 0; j < SIZE_OF_FIELD; j++) {
			field[i][j] = '0';
		}
	}
}
void landMines(){
	int pos_row, pos_column;
	do {
		 pos_row = rand() % SIZE_OF_FIELD;
		 pos_column = rand() % SIZE_OF_FIELD;

	} while (field[pos_row][pos_column] == MINE_CHAR);
	field[pos_row][pos_column] = MINE_CHAR;
}

void showField() {
	for (int i = 0; i < SIZE_OF_FIELD; i++) {
		for (int j = 0; j < SIZE_OF_FIELD; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	srand(time(0));
	
	int countOfMines = SIZE_OF_FIELD * SIZE_OF_FIELD * PART_OF_FIELD;

	initField();

	for (int i = 0; i < countOfMines; i++) {
		landMines();
	}

	showField();

	return 0;
}