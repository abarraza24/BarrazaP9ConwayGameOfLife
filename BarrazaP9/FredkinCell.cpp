//Alexis Barraza abarraza24@cnm.edu
//Project 9 The Game of Life 
//FredkingCell.cpp

#include "FredkinCell.h"

void FredkinCell::UpdateCells()
{
	//Create nested for loops
	//call GetLivingNeighbors
	//apply the rules

	//Created a nested loops to iterate over each cell on the grid
	for (int i{ 0 }; i < ROWS; i++)
	{
		for (int j{ 0 }; j < COLS; j++)
		{
			GetLivingNeighbors(i, j);

			//LiveCells
			if (cell[i][j] == '*')
			{
				if (count == 0 || count == 2 || count == 4)
				{
					nextCellState[i][j] = '.';
				}
				else
				{
					nextCellState[i][j] = '*';
				}
			}
			//deadcells
			if (cell[i][j] == '.')
			{
				if (count==1||count==3)
				{
					nextCellState[i][j] = '*';
				}
				else
				{
					nextCellState[i][j] = '.';
				}
			}
		}
	}
	SetNextState();
}

FredkinCell::FredkinCell(): LifeCell()
{
	 
}
