//Alexis Barraza abarraza24@cnm.edu
//Project 9 The Game of Life 
//ModifiedFredkinCell.h

#ifndef MODIFIED_FREDKIN_CELL_H
#define MODIFIED_FREDKIN_CELL_H
#include"FredkinCell.h"
//inherating from fredkincell
class ModifiedFredkinCell : public FredkinCell
{
private:
	int age[ROWS][COLS]{};
protected:
	virtual void GetLivingNeighbors(int r, int c)override;
	virtual void UpdateCells()override;
public:
	ModifiedFredkinCell();
	void ClearAge();

};
#endif

