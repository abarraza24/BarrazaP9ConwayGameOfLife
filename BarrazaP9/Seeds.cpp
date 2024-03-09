//Alexis Barraza abarraza24@cnm.edu
//Project 9 The Game of Life 
//Seeds.cpp

#include "Seeds.h"

void Seeds::GetLivingNeighbors(int r, int c)
{
	
	//call GetLivingNeighboors from LifeCell

	LifeCell::GetLivingNeighbors(r, c);

	//Than we write a code for the cells on the diagonal
	//Check through each cell

	//Find out where each cell is at all 8 of them
	//Top right cell
	if (r != 0 && c != COLS - 1)
	{
		if (cell[r - 1][c + 1] == '*')
		{
			count++;
		}
	}
	//Cell to the right
	if (c != COLS - 1)
	{
		if (cell[r][c + 1] == '*')
		{
			count++;
		}
	}
	//cell to the bottow right
	if (r != ROWS - 1 && c != COLS - 1)
	{
		if (cell[r + 1][c + 1] == '*')
		{
			count++;
		}
	}
	//Cell to the bottom
	if (r != ROWS - 1)
	{
		if (cell[r + 1][c] == '*')
		{
			count++;
		}
	}
	//Cell to the bottom left
	if (r != ROWS - 1 && c != 0)
	{
		if (cell[r + 1][c - 1] == '*')
		{
			count++;
		}
	}
	//Cell to the left
	if (c != 0)
	{
		if (cell[r][c - 1] == '*')
		{
			count++;
		}
	}
	//Cell to upper left
	if (r != 0 && c != 0)
	{
		if (cell[r - 1][c - 1] == '*')
		{
			count++;
		}
	}
	//cell to top
	if (r != 0)
	{
		if (cell[r - 1][c] == '*')
		{
			count++;
		}

	}
}

void Seeds::UpdateCells()
{
	//Create nested for loops
	//call GetLivingNeighbors
	//apply the rules

	//Nested for loops to iterate trough each cell
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			//calling GetLivingNeighbors to update the count
			GetLivingNeighbors(i, j);

			//Applying the rules based on seeds cell
			// Rule: a dead cell becomes alive if exactly 2 neighbors are alive
			if (cell[i][j]=='.'&& count == 2)
			{
				nextCellState[i][j] = '*';
			}
			else
			{
				// Rule: all other cells become dead
				nextCellState[i][j] = '.';
			}
			//Live Cell
			//if (cell[i][j] == '*')
			//{
			//	//Rule: a dead cell becomes alive if exactly 2 neighbors are alive
			//	if (count == 2)
			//	{
			//		nextCellState[i][j] = '*';
			//	}
			//	else
			//	{
			//		//Rule: all other cells become dead
			//		nextCellState[i][j] = '.';
			//	}
			//}
			////dead cell
			//else
			//{
			//	//Rule: a dead cell becomes alive if exactly 2 neighbors are alive
			//	if (count == 2)
			//	{
			//		nextCellState[i][j] = '*';
			//	}
			//	else
			//	{
			//		//Rule: all other cells become dead
			//		nextCellState[i][j] = '.';
			//	}
			//}
		}

	}
	//SetNextState();
}

//passing Consturctor
Seeds::Seeds() : LifeCell()
{
}
