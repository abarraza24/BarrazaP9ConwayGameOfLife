#ifndef FREDKIN_H
#define FREDKIN_H
#include "LifeCell.h"
class FredkinCell :public LifeCell
{
protected:
	virtual void UpdateCells() override;
public:
	FredkinCell();
};
#endif
