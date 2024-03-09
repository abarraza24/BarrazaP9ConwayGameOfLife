//Alexis Barraza abarraza24@cnm.edu
//Project 9 The Game of Life 
//Driver.cpp

//Driver.cpp
#include<iostream>
#include"LifeCell.h"
#include"ConwayCell.h"
#include"FredkinCell.h"
#include"ModifiedFredkinCell.h"
#include"Seeds.h"
#include"AlexisCell.h"
#include"Functions.h"
#include<Windows.h>
#include<iomanip>
using namespace std;
//array of LifeCell pointers and the object created above main(), 
// in global scope to avoid a Visual Studio stack overflow.
LifeCell* pLife[5];
ConwayCell con;
FredkinCell fred;
ModifiedFredkinCell modFred;
Seeds seed;
AlexisCell al;

int main()
{
	// Set console window size to its largest size for your screen
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	// Adjust the width and height if needed
	MoveWindow(console, r.left, r.top, 1920, 1080, TRUE);

	// Change color
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(screen, 4);
	

	//Assign the object address to the element of the array
	pLife[0] = &con;
	pLife[1] = &fred;
	pLife[2] = &modFred;
	pLife[3] = &seed;
	pLife[4] = &al;

	//variables
	int lifeCount = 0;
	int config;
	string pattern;

	//write instructions
	WriteInstructions();

	//open a play loop
	do
	{
		lifeCount = 0;

		config = UserChoosesAnImplementation();
		config--;

		pattern = UserChoosesInitialPattern();
	

		//set the pattern
		pLife[config]->SetPattern(pattern);

		cout<< pLife[config]->PrintBoard();
		system("pause");

		//Now set the game in motion
		do
		{
			//checking age based calc
			//// Update all cell types
			//for (int i = 0; i < 5; ++i) 
			//{
			//	pLife[i]->UpdateBoard();
			//}

			//// Only display specific cell types
			//if (config == 2 || config == 4) 
			//{
			//	// ModifiedFredkinCell or Seeds need age-based display
			//	pLife[config]->PrintBoard();
			//}
			//else 
			//{
			//	// Other cell types don't need age-based display
			//	pLife[config]->PrintBoard();
			//}
			pLife[config]->UpdateBoard();
			//using dynamic casting to check for aged cells
			ModifiedFredkinCell* mfc = dynamic_cast<ModifiedFredkinCell*>(pLife[config]);
			if (mfc != nullptr)
			{
				//Age based calculations for modified fredkin cell
				//if dynamic cast is successful than I kow it's a 
				//ModifiedFredkinCell due to returning a non-null pointer than we can proceed with
				//age based calculations.
				mfc->PrintBoard();
			}
			else
			{
				//Non-Aged based calculations;
				pLife[config]->PrintBoard();
			}
			cout << pLife[config]->PrintBoard() << flush;
			Sleep(150);
			system("cls");
			lifeCount++;
		} while (lifeCount<200);

		//resting the board to all deal cells
		pLife[config]->Clear();

		//reset the age to all 0
		ModifiedFredkinCell* mfc = dynamic_cast<ModifiedFredkinCell*>(pLife[config]);
		if (mfc != nullptr)
		{
			mfc->ClearAge();
		}

		

	} while (doAnother());
	
	cout << "\n\n Thanks for Playing the Game of Life! " << endl << endl;

	return 0;
}