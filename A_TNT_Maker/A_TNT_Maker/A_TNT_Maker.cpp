#include "stdafx.h"

#pragma region Variables
char team[] = "A T&T Maker, made by Aiden Thinn and Nathan Terrell. AT NT.";

//Pathfinding variables
const int pathLength = 10;
int* path[pathLength][2] = {};
int** maze;
int currentPathIndex = 0;
#pragma endregion

#pragma region Methods
char* GetTeam() {
	return team;
}

void SetMaze(const int** data, int width, int height) {

	maze = {};

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			 maze[x][y] = data[x][y];
		}
	}
}
int** GetMaze(int& width, int& height) {
	return maze;

	
}

void GetNextPosition(int& xpos, int& ypos) {
	xpos = **(*path + currentPathIndex * 4); //Pointer -> Array -> index in ints -> First Value
	ypos = *(*(*path + currentPathIndex * 4) + 4); //Pointer -> Array -> index in ints -> Second int
}

void SetStart(int xpos, int ypos) {
	***path = xpos; //Pointer -> Array -> First Position -> First int (x) 
	*(**path + 4) = ypos; //Pointer -> Array -> First Position -> Second int (y) 
}
void GetStart(int& xpos, int& ypos) {
	xpos = ***path; //Pointer -> Array -> First Position -> First int (x) 
	ypos = *(**path + 4); //Pointer -> Array -> First Position -> Second int (y) 
}
void SetEnd(int xpos, int ypos) {
	
}
void GetEnd(int& xpos, int& ypos) {
	xpos = 
	ypos =
}
#pragma endregion