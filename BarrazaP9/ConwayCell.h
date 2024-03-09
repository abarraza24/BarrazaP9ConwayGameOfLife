#ifndef CONWAY_H
#define CONWAY_H
#include "LifeCell.h"

//inherith lifeCell for ConwayCell
class ConwayCell:public LifeCell
{
protected:
	virtual void GetLivingNeighbors(int r, int c) override; 
	virtual void UpdateCells() override; 
public:
	ConwayCell();
};


#endif
