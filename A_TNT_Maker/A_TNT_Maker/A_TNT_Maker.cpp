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
_declspec(dllexport) char* GetTeam() {
	return team;
}

_declspec(dllexport) bool SetMaze(const int** data, int width, int height) {

	if (maze != nullptr) //Clears previous data
	{
		delete[] maze;
	}

	if (width != 0 && height != 0 || width > 0 && height > 0) //If width is not 0 or negative and height is not 0 or negative
	{
		maze = new int*[width]; //Initialize maze

		mWidth = width; //Set width
		mHeight = height; //Set height

		for (int x = 0; x < width; x++) //Loop to fill in the maze array
		{
			maze[x] = new int[height]; //Initialize maze

			for (int y = 0; y < height; y++)
			{
				maze[x][y] = data[x][y];
			}
		}
	}
	else return false;
}

_declspec(dllexport) int** GetMaze(int& width, int& height) {

	width = mWidth; //Get width
	height = mHeight; //Get height

	if (width == NULL && height == NULL) //If the maze data is not set
	{
		return nullptr; //Return nullptr
	}

	return maze; //Return the saved maze with data
}

_declspec(dllexport) bool GetNextPosition(int& xpos, int& ypos) {

	xpos = **(tempPath + currentPathIndex); //Array -> Position -> First int (x)
	ypos = *(*(tempPath + currentPathIndex) + 1); //Array -> Position -> Second int (y)

	if (currentPathIndex < tempPathLength - 1) {
		currentPathIndex++;
		return true;
	}
	else return false;
}

_declspec(dllexport) bool SetStart(int xpos, int ypos) {

	**tempPath = xpos; //Array -> First position -> First int (x) 
	*(*tempPath + 1) = ypos; //Array -> First position -> Second int (y)
	return true;
}
_declspec(dllexport) bool GetStart(int& xpos, int& ypos) {

	if (tempPath != nullptr) {
		xpos = **tempPath; //Array -> First position -> First int (x) 
		ypos = *(*tempPath + 1); //Array -> First position -> Second int (y)
		return true;
	}
	else return false;
}

_declspec(dllexport) bool SetEnd(int xpos, int ypos) {

	 tempPath[sizeof tempPath / sizeof *tempPath - 1][0] = xpos; //Array -> Last position -> First int (x)
	 tempPath[sizeof tempPath / sizeof *tempPath - 1][1] = ypos; //Array -> Last position -> Second int (y)
	 return true;
}

_declspec(dllexport) bool GetEnd(int& xpos, int& ypos) {

	if (tempPath != nullptr) {
		xpos = tempPath[sizeof tempPath / sizeof *tempPath - 1][0]; //Array -> Last position -> First int (x)
		ypos = tempPath[sizeof tempPath / sizeof *tempPath - 1][1]; //Array -> Last position -> Second int (y)
		return true;
	}
	else return false;
}

_declspec(dllexport) bool Restart() {

	currentPathIndex = 0;
}
#pragma endregion