#ifndef ALEXIS_CELL_H
#define ALEXIS_CELL_H
#include"LifeCell.h"
class AlexisCell :public LifeCell
{
protected:
	virtual void GetLivingNeighbors(int r, int c) override;
	virtual void UpdateCells() override;
public:
	AlexisCell();
};
#endif
