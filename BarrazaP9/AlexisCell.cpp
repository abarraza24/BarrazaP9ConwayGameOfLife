//Alexis Barraza abarraza24@cnm.edu
//Project 9 The Game of Life 
//Alexis.cpp

#include "AlexisCell.h"


void AlexisCell::GetLivingNeighbors(int r, int c)
{

	count = 0;
	
	//Top right cell
	if (r != 0 && c != COLS - 1)
	{
		if (cell[r - 1][c + 1] == '*')
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
	//Cell to the bottom left
	if (r != ROWS - 1 && c != 0)
	{
		if (cell[r + 1][c - 1] == '*')
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
}

void AlexisCell::UpdateCells()
{
	//Implementing AlexisCell new rules
	//If cell has 0 or 4 live neighbors than cell dies 
	//If cell has 1,2, or 3 live neighbors then cell becomes alive

	//start by looping through every cell in the grid
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			//call GetLivingNeighbors(i,j)
			GetLivingNeighbors(i, j);

			//Rules
			if (cell[i][j]=='*')
			{
				if (count==0||count ==4)
				{
					nextCellState[i][j] = '.'; //celldies
				}
				else
				{
					nextCellState[i][j] = '*';
				}
			}

			//dead cells
			else
			{
				if (count >0 && count <4)
				{
					nextCellState[i][j] = '*';
				}
				else
				{
					nextCellState[i][j] = '.';
				}
			}

		}
		//SetNextState();
	}
	
}

AlexisCell::AlexisCell(): LifeCell()
{
}
