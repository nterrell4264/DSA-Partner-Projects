#include "stdafx.h"

#pragma region Variables
char team[] = "A T&T Maker, made by Aiden Thinn and Nathan Terrell. AT NT.";

//Pathfinding variables

//Currently unused until A* is implemented
/*int path[][2];
int pathLength = 0;
int* end;*/
int currentPathIndex = 0;

//Temporary path
int tempPath[10][2] = { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, 1 }, { 3, 1 }, { 3, 2 }, { 3, 3 }, { 4, 3 }, { 4, 4 }, { 4, 5 } };
int tempPathLength = 10;

//Maze variables
int** maze;
int mWidth;
int mHeight;
#pragma endregion

#pragma region Methods
char* GetTeam() {
	return team;
}

void SetMaze(const int** data, int width, int height) {

	maze = {};

	mWidth = width;
	mHeight = height;

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			 maze[x][y] = data[x][y];
		}
	}
}
int** GetMaze(int& width, int& height) {
	mWidth = width;
	mHeight = height;
	return maze;
}

void GetNextPosition(int& xpos, int& ypos) {
	xpos = **(tempPath + currentPathIndex * 4); //Array -> Position -> First int (x)
	ypos = *(*(tempPath + currentPathIndex * 4) + 4); //Array -> Position -> Second int (y)
}

void SetStart(int xpos, int ypos) {
	**tempPath = xpos; //Array -> First position -> First int (x) 
	*(*tempPath + 4) = ypos; //Array -> First position -> Second int (y) 
}
void GetStart(int& xpos, int& ypos) {
	if (tempPath != nullptr) {
		xpos = **tempPath; //Array -> First position -> First int (x) 
		ypos = *(*tempPath + 4); //Array -> First position -> Second int (y)
	}
	else {
		xpos = -1;
		ypos = -1;
	}
}
void SetEnd(int xpos, int ypos) {
	xpos = *tempPath[sizeof tempPath / sizeof *tempPath - 2];
	ypos = *tempPath[sizeof tempPath / sizeof *tempPath - 1];
}
void GetEnd(int& xpos, int& ypos) {
	if (tempPath != nullptr) {
		
	}
	else
	{
		xpos = -1;
		ypos = -1;
	}
}
#pragma endregion