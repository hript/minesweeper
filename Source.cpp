#include<iostream>
#include<ctime>
#include<Windows.h>

#define SIZE_OF_FIELD 10 
#define PART_OF_FIELD 0.2
#define MINE_CHAR 'X'

using namespace std;

char field[SIZE_OF_FIELD][SIZE_OF_FIELD] = { '0' };

void landMines(int countOfMines){
	int pos_row, pos_column;
	do {
		 pos_row = rand() % SIZE_OF_FIELD;
		 pos_column = rand() % SIZE_OF_FIELD;

	} while (field[pos_row][pos_column] == MINE_CHAR);
	field[pos_row][pos_column] = MINE_CHAR;
}

int main()
{
	srand(time(0));// 2 2 2 2 2
	int countOfMines = SIZE_OF_FIELD * SIZE_OF_FIELD * PART_OF_FIELD;
	
	

	return 0;
}