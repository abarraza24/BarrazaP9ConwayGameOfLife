//Alexis Barraza abarraza24@cnm.edu
//Project 9 The Game of Life 
//LifeCell.cpp

#include "LifeCell.h"

void LifeCell::InitializeBoard()
{
  //read the file chosen by the user
	ifstream input(pattern);

	if (input.is_open())
	{
		//Read the contents of the txt file and initialize the board
		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLS; ++j)
			{
				//read
				char currentChar;
				input >> currentChar;

				//checking if the character is '*'
				if (currentChar == '*')
				{
					cell[i][j] = '*'; // sets the cell as alive
				}
				else
				{
					cell[i][j] = '.'; //sets the cell as dead 
				}
			}
		}
		//closes the file after readin
		input.close();
	}
	
}

void LifeCell::GetLivingNeighbors(int r, int c)
{
	count = 0;
	//Implement a Von Neumann neighborhood.
	//Check the Cell on the bottom and if it is not an edge,
	//then we check if the cell in that direction is alive.
	//If it is alive, than increment count

	//top cell
	if (r != 0 && cell[r - 1][c] == '*')
	{
		count++;
	}
	//right cell
	if (c != COLS - 1 && cell[r][c + 1] == '*')
	{
		count++;
	}
	//bottom cell
	if (r !=ROWS-1 && cell[r+1][c]=='*')
	{
		count++;
	}
	//left cell
	if (c !=0 && cell[r][c-1]=='*')
	{
		count++;
	}
	
}

void LifeCell::SetNextState()
{
	//Use nested for loops to set each element of nextCellState array
	//into cell array
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			cell[i][j] = nextCellState[i][j];
		}
	}
}

LifeCell::LifeCell()
{
	//initialize the cell array as dead.
	//Also the nextCellState array
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cell[i][j] = '.';
			nextCellState[i][j] = '.';
		}
	}
}

void LifeCell::SetPattern(string pat)
{
	pattern = pat; //easier if we make this the filename.
	InitializeBoard();
}

void LifeCell::UpdateBoard()
{
	//call updateCells
	//and SetNextState this updates boards
	UpdateCells();
	SetNextState();
}

string LifeCell::PrintBoard()
{
	//Use stringstream and created a string with the array on it 
	//Same old thing, use a nested for loops, and Check to see if 
	//the content of the element is '.' dead. If so, add ' ' to 
	//the stringStream. Then Convert the stringstream inta string and return it.
	
	stringstream ss;
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			//checking if the cell is dead
			if (cell[i][j] == '.')
			{
				//if dead will add space.
				ss <<' ';
			}
			else
			{
				//if alive will add a *
				ss << '*';
			}
		}
		//adding a newline character after each row
		ss << '\n';
	}

	//convert the stringstream to a string and return it
	return ss.str();
}

void LifeCell::Clear()
{
	//Reset the arrays as dead.
	//will use a nested loop that iterate
	//through each element of cell and nextCell state
	
	//resting the arrays to dead ('.')
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			cell[i][j] = '.';
			nextCellState[i][j] = '.';
		}
	}
}
