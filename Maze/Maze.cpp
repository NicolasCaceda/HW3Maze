// Maze.cpp : Defines the entry point for the console application.
//Nicolas Caceda 4/4/2018

#include "stdafx.h"
#include "Stack.h"

const int MAZEROWS = 10;
const int MAZECOLS = 16;



char Maze[MAZEROWS][MAZECOLS] = {
	"000000000000000",
	"0             0",
	"0 000000 0000 0",
	"0       0000000",
	"0 00 0       00",
	"0 00 000 00 000",
	"0 0     000   0",
	"0 0000000000000",
	"0             0",
	"000000000000000"
};

/*
//No solution
char Maze[MAZEROWS][MAZECOLS] = {
	"000000000000000",
	"0             0",
	"0 000000 0000 0",
	"0       0000000",
	"0 00 0       00",
	"0 00 000 00 000",
	"0 0     000   0",
	"0 0000000000000",
	"0          0  0",
	"000000000000000"
};
*/

void PrintMaze() {
	for (int i = 0; i < MAZEROWS; i++) {
		for (int j = 0; j < MAZECOLS; j++) {
			printf("%c", Maze[i][j]);
		}
		printf("\n");
	}
	printf("\n ------------------------------------------ \n");
}

int main()
{

	Stack StackRow(160);
	int CurrentRow = 1;
	int EndRow = 8;

	Stack StackCol(160);
	int EndCol = 13;
	int CurrentCol = 1;
	
	const int STEP = 1;
	bool Done = false;

	//maze loop
	while (!Done) {
		
		//done?
		if (CurrentRow == EndRow && CurrentCol == EndCol) {
			Done = true;
			Maze[CurrentRow][CurrentCol] = '*';
			PrintMaze();
			printf("DONE \n");
			break;
		}
		//right
		else if (Maze[CurrentRow][CurrentCol + STEP] == ' ') {
			StackRow.Push(CurrentRow);
			StackCol.Push(CurrentCol);
			Maze[CurrentRow][CurrentCol] = '*';
			CurrentCol++;
			//Used for debugging
			//printf("right \n");
			//PrintMaze();
		}
		//down
		else if (Maze[CurrentRow + STEP][CurrentCol] == ' ') {
			StackRow.Push(CurrentRow);
			StackCol.Push(CurrentCol);
			Maze[CurrentRow][CurrentCol] = '*';
			CurrentRow++;
			//Used for debugging
			//printf("down \n");
			//PrintMaze();
		}
		//left
		else if (Maze[CurrentRow][CurrentCol - STEP] == ' ') {
			StackRow.Push(CurrentRow);
			StackCol.Push(CurrentCol);
			Maze[CurrentRow][CurrentCol] = '*';
			CurrentCol--;
			//Used for debugging
			//printf("left \n");
			//PrintMaze();
		}
		//up
		else if (Maze[CurrentRow - STEP][CurrentCol] == ' ') {
			StackRow.Push(CurrentRow);
			StackCol.Push(CurrentCol);
			Maze[CurrentRow][CurrentCol] = '*';
			CurrentRow--;
			//Used for debugging
			//printf("up \n");
			//PrintMaze();
		}
		else {
			//backtrack
			if(StackRow.StackSize()){
				Maze[CurrentRow][CurrentCol] = 'D';

				CurrentRow = StackRow.Pop();
				CurrentCol = StackCol.Pop();
				//Used for debugging
				//printf("Backtracking... \n");
				//PrintMaze();
			}
			//done
			else if (!StackRow.IsEmpty() || !StackCol.IsEmpty()){
				PrintMaze();
				printf("No solution\n");
				Done = true;
			}
		}


	}
	
    return 0;
}

