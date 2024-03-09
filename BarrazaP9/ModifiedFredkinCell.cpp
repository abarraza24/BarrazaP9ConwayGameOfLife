#include "ModifiedFredkinCell.h"

void ModifiedFredkinCell::GetLivingNeighbors(int r, int c)
{
	//This is a VonNeuman neighborhood, to start.
	FredkinCell::GetLivingNeighbors(r, c);

	//check if the age[r][c] > 2
	if (age[r][c] > 2)
	{
		//If it is, check the 4 other cells like we did for Seeds and Conway.
		//to see if they are alive.
		//Top Right
		if (r != 0 && c != COLS - 1)
		{
			if (cell[r-1][c+1]=='*')
			{
				count++;
			}
		}
		//Cells to the bottom right
		if (r != ROWS - 1 && c != COLS - 1)
		{
			if (cell[r + 1][c + 1] == '*')
			{
				count++;
			}
		}
		//cells to the bottom left
		if (r != ROWS - 1 && c != 0)
		{
			if (cell[r+1][c-1]=='*')
			{
				count++;
			}
		}
		//cells to the upper left
		if (r !=0 && c !=0)
		{
			if (cell[r-1][c-1]=='*')
			{
				count++;
			}
		}
	}
}

void ModifiedFredkinCell::UpdateCells()
{
	//create a nested loop
	//call GetLivingNeighbors
	//apply the rules depending on the age of the cell.
	//if age > 2, it's a  Conway Cell -when does this happen?
	// if the cell is alive and stays alive, increment age of cell.
	// if the cell is alive and dies, reset the age to 0 and set to dead cell.
	//else it's a Fredkin Cell
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			GetLivingNeighbors(i, j);

			if (age[i][j] > 2)
			{
				// Conway rules
				if (cell[i][j] == '*' && (count < 2 || count > 3))
				{
					nextCellState[i][j] = '.';
				}
				else if (cell[i][j] == '.' && count == 3)
				{
					nextCellState[i][j] = '*';
				}
				else
				{
					nextCellState[i][j] = cell[i][j];
				}

				// Increment age for living cells
				if (cell[i][j] == '*')
				{
					age[i][j]++;
				}
				else
				{
					age[i][j] = 0;
				}
			}
			else
			{
				// Fredkin rules
				if (cell[i][j] == '*' && (count == 0 || count == 2 || count == 4))
				{
					nextCellState[i][j] = '.';
				}
				else if (cell[i][j] == '.' && (count == 1 || count == 3))
				{
					nextCellState[i][j] = '*';
				}
				else
				{
					nextCellState[i][j] = cell[i][j];
				}

				// Increment age for living cells
				if (cell[i][j] == '*')
				{
					age[i][j]++;
				}
				else
				{
					age[i][j] = 0;
				}
			}
		}
	}
	//Apply the changes to the cell array for the next generation
	//SetNextState();
}

ModifiedFredkinCell::ModifiedFredkinCell() : FredkinCell()
{
	//Clear();
	ClearAge();
}

void ModifiedFredkinCell::ClearAge()
{
	//sets all the cells to age =0;
	// Loop through all cells and set their ages to 0
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			age[i][j] = 0;
		}
	}
}
