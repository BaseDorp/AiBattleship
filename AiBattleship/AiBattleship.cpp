#include "pch.h"
#include <iostream>

int AddShipx(int _l);
int AddShipy(int _l);
void PrintBoard(int _w, int _l);

int main()
{
	const int length = 5;
	const int width = 5;
	int x = 0;
	int y = 0;
	int Board[width][length];
	bool AddShip = true;
	int numShips = 0;

	//Set all board values to 0
	for (int i = 0; i < length; i++)
	{
		Board[i][i] = 0;
		for (int j = 0; j < width; j++)
		{
			Board[j][i] = 0;
		}
	}

	// Constructs Board
	int n = 0;
	std::cout << "  ";
	// Prints the x axis number line
	for (int i = 1; i < length + 1; i++)
	{
		std::cout << "  " << i;
	}
	// Prints the rest of the board
	for (int i = 0; i < length; i++)
	{
		n++;
		std::cout << "\n" << n << " ";
		std::cout << "|" << Board[0][i] << "|";
		for (int j = 1; j < width; j++)
		{
			std::cout << "|" << Board[j][i] << "|";
		}
	}
	std::cout << std::endl;

	while (AddShip)
	{
		//Take in input from user
		Board[AddShipx(width)][AddShipy(length)] = 1;

		// Reprints new Board
		int n = 0;
		std::cout << "  ";
		// Prints the x axis number line
		for (int i = 1; i < length + 1; i++)
		{
			std::cout << "  " << i;
		}
		// Prints the rest of the board
		for (int i = 0; i < length; i++)
		{
			n++;
			std::cout << "\n" << n << " ";
			std::cout << "|" << Board[0][i] << "|";
			for (int j = 1; j < width; j++)
			{
				std::cout << "|" << Board[j][i] << "|";
			}
		}
		std::cout << std::endl;
		numShips++;

		// Get out of loop
		std::cout << "Would you like to add another ship?\n1. Yes\n2. No\n";
		int input = 0;
		std::cin >> input;
		while (input < 1 || input > 2)
		{
			std::cout << "Sorry this is not a valid input. Please try again...\n";
			std::cin >> input;
		}
		if (input == 2)
		{
			AddShip = false;
		}
	}

	// AI Finds Ships ------------------------------------------------------------------------
	while (numShips > 0)
	{
		for (int i = 0; i < length; i++)
		{
			for  (int j = 0; j < width; j++)
			{
				if (Board[j][i] == 1)
				{
					std::cout << "Hit at (" << j+1 << ", " << i+1 << ")\n";
					numShips--;
				}
				else if (Board[j + 1][i] == 1 || Board[j - 1][i] == 1 || Board[j + 1][i + 1] == 1 || Board[j + 1][i - 1] == 1 || Board[j][i + 1] == 1 || Board[j][i - 1] == 1 || Board[j - 1][i + 1] == 1 || Board[j - 1][i - 1] == 1)
				{
					for (int a = i-1; a < i+3; a++)
					{
						for (int b = j-1; b < j+3; b++)
						{
							if (Board[b][a] == 1)
							{
								std::cout << "Hit at (" << b + 1 << ", " << a + 1 << ")\n";
								numShips--;
							}
						}
					}
				}
			}
		}
		std::cout << "All the ships have been found\n";
	}

	// End of program
	std::cout << std::endl;
	system("PAUSE");
	return 0;
}

int AddShipx(int _w)
{
	int x = 0;

	std::cout << "Where would you like to put a ship (x,y)\nx = ";
	while (x < 1 || x > _w)
	{
		std::cin >> x;
		if (x < 1 || x > _w)
		{
			std::cout << "This is not a valid answer. Please try again.\n";
			std::cout << "x = ";
		}
	}
	return x - 1;
}

int AddShipy(int _l)
{
	int y = 0;
	std::cout << "y = ";
	while (y < 1 || y > _l)
	{
		std::cin >> y;
		if (y < 1 || y > _l)
		{
			std::cout << "This is not a valid answer. Please try again.\n";
			std::cout << "y = ";
		}
	}
	return y - 1;
}

void PrintBoard(int _w, int _l)
{
	int n = 0;
	std::cout << "  ";
	// Prints the x axis number line
	for (int i = 1; i < _l + 1; i++)
	{
		std::cout << " " << i;
	}
	// Prints the rest of the board
	for (int i = 0; i < _l; i++)
	{
		n++;
		std::cout << "\n" << n << " ";
		std::cout << "|0|";
		for (int j = 1; j < _w; j++)
		{
			std::cout << "0|";
		}
	}
	std::cout << std::endl;
}