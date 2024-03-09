//Alexis Barraza abarraza24@cnm.edu
//Project 9 The Game of Life 
//Functions.cpp

#include "Functions.h"

void WriteInstructions()
{
	//Write a good intro for the user and explains what we are doing
	cout << "Alexis Barraza Project 9\nGame of Life\n"
	 << "Hello and welcome to the \"Game of Life\"!" << endl
	 << "This game lets you explore the fascinating world of cellular automata." << endl
	 << "As you play, you'll discover how simple rules can lead to complex and ever-changing patterns." << endl
	 << "Each cell in the game can be alive or dead, and their fate is determined by their neighbors." << endl
	 << "Prepare to be captivated by the beauty and complexity of life emerging from simple beginnings!\n\n" << endl;
	
}

int UserChoosesAnImplementation()
{
	//Give the user the choice of the 5 cells types and number them
	//they can select  a number.
	//than return the number 
	int choice;
	while (true)
	{
		cout <<"Rules for Game of Life:\n\n"
			<< "1.Conway Cell: Cells evolve depending on how many of its 8 neighbors are alive.\n"
			<< "A dead Cell becomes a live cell, if exactly 3 neighbors are alive as if by reproduction.\n"
			<< "A live cell with more than 3 live neighbor dies, by overcrowding\n"
			<< "A live cell with 2 or 3 live neighbors lives on to the next generation.\n"
			<< "A live cell with fewer than 2 live neighbors dies, as if caused by under-population\n" << endl
			<< "2.Fredkin Cell: Cells Stay alive depending on how many of its 4 neighbors are alive.\n"
			<< "A dead cell becomes a live cell if 1 or 3 neighbors are alive.\n"
			<< "A live cell becomes a dead cell,if 0,2,or 4 neighbors are alive\n"
			<< "Otherwise it stays the same.\n" << endl
			<< "3.Modified Fredkin Cell: The cell begins as a Fredkin Cells, and turns into a ConwayCell based on age\n "
			<< "If a Fredkin Cell age becomes 2, than it becomes a live conway cell instead.If not it becomes a dead cell\n" << endl
			<< "4. Seed Cell: Seeds is a pattern of chaos\n"
			<< "The rules are: A cell becomes a live cell if excatly 2 neighbors are alive.\n"
			<< "Otherwise all other live cells become dead\n" << endl
			<< "5. Alexis Cell:\n"
			<< "If neighbors are 0 or 4 then cell dies. If cell has 1,2, or 3 live neighbors then cell becomes alive.\n" << endl
			<<"Choose a Cell type for the Game of Life by selecting a number from 1-5 ===>  ";


		if (cin >> choice && choice >= 1 && choice <= 5)
		{
			break;// valid input,
		}
		else
		{
			//cin.clear(); // clears input buffer to restor cin
			cin.ignore();
			cout << "Invalid Input. Please enter a number from 1-5" << endl;
		}
	}
	return choice;
}

string UserChoosesInitialPattern()
{
	//give the user the choice of the however many cell types
	// and number them so they can select a number.

	//Then use a switch to return the appropriate pattern filename
	//for the selected pattern.
	//and return the filename.
	int choice;
	cout << "Choose an initial pattern to start the Game: " << endl;
	cout << "1. Boat" << endl;
	cout << "2. Cross" << endl;
	cout << "3. GlidderGun" << endl;
	cout << "4. Pentomino" << endl;
	cout << "5. StickFigure" << endl;
	cout << "6. Acorn" << endl;
	cout << "7. Diehard" << endl;
	cout << "8. Queen Bee Shuttle" << endl;
	cout << "9. Gosper Glider Gun" << endl;
	cout << "10.Diamond" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		return "boat.txt";
	case 2:
		return "cross.txt";
	case 3:
		return "GliderGun.txt";
	case 4:
		return "pentomino.txt";
	case 5:
		return "StickFigure.txt";
	case 6:
		return "Acorn.txt";
	case 7:
		return "Diehard.txt";
	case 8:
		return "QueenBeeShuttle.txt";
	case 9:
		return "GosperGliderGun.txt";
	case 10:
		return "Diamonds.txt";

	default:
		return "Not a Valid Choice";
	}
}
bool doAnother()
{
	char response;
	cout << "Do you want to try another simulation? (y/n):  ";
	cin >> response;
	return (response == 'y' || response == 'Y');
}