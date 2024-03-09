//Alexis Barraza abarraza24@cnm.edu
//Project 9 The Game of Life 
//Seeds.h

#ifndef SEEDS_H
#define SEEDS_H
#include"LifeCell.h"
class Seeds : public LifeCell
{
protected:
	virtual void GetLivingNeighbors(int r, int c) override;
	virtual void UpdateCells() override;
public:
	Seeds();
};
#endif
