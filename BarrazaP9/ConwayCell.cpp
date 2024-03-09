//Alexis Barraza abarraza24@cnm.edu
//Project 9 The Game of Life 
//ConwayCell.cpp

#include "ConwayCell.h"

void ConwayCell::GetLivingNeighbors(int r, int c)
{
	//ConwayCell is a Moore Neighborhood
	//can call GetLivingNeighboors from LifeCell

	LifeCell::GetLivingNeighbors(r, c);
	//Initialize count
		count = 0;

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

void ConwayCell::UpdateCells()
{
	//Apply the rules to each cell
	//Loop through every cell on the gride
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			GetLivingNeighbors(i, j); // this for one cell

			//apply the conway rules 
			//Live Cells 
			if (cell[i][j] == '*')
			{
				if (count < 2 || count > 3) // Cell dies 
					nextCellState[i][j] = '.';
				else
					nextCellState[i][j] = '*';
			}

			//dead cell
			else
			{
				if (count == 3)
					nextCellState[i][j] = '*';
				else
					nextCellState[i][j] = '.';
			}
		}


	}
	//Apply the changes to the cell array for the next generation
	SetNextState();
}

ConwayCell::ConwayCell():LifeCell()
{
}
