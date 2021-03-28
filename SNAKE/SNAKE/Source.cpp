#include <iostream>
#include <conio.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, c, z, FruitX, FruitY, FruitXX, FruitYY, FruitXXX, FruitYYY, FruitYYYY, FruitXXXX, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton {STOP =0, LEFT, RIGHT, UP , DOWN};
eDirecton dir;
void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	FruitX = rand() % width;
	FruitY = rand() % height;
	FruitXX = rand() % height;
	FruitYY = rand() % width;
	FruitXXX = rand() % width;
	FruitYYY = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls");
	for (int i = 0; i < width+22; i++)
		cout << "#";
	cout << endl;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			//===================================================================================================================================
			//                                                            owoc normalny 
			else if (i == FruitY && j == FruitX)
				cout << "F";
			else 
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			
			}
			/*if (j == 0)
				cout << "";
			if (i == y && j == x)
				cout << "";
			//===================================================================================================================================
			//                                                               owoc x2
			else if (i == FruitYY && j == FruitXX)
			{
				cout << "D";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						print = true;
	
					}		
					
				}	

            }	
			*/
			if (j == 0)
				cout << "";
			if (j == y && i == x)
				cout << "";
			//===================================================================================================================================
            //                                                               owoc minus 10 punktow
			else if (i == FruitYYY && j == FruitXXX)
			{
				cout << "S";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						print = true;
	
					}		
				
				}	

            }	
			if (j == 0)
				cout << "";
			if (j == y && i == x)
				cout << "";
			//===================================================================================================================================
            //                                                               owoc speed
			else if (i == FruitYYYY && j == FruitXXXX)
			{
				cout << "M";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						print = true;
	
					}		
				
				}	

            }	
			cout << " ";

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width+22; i++)
		cout << "#";
	cout << endl;
	cout << "Wynik:" << score << endl;

}


void Input()
{
	if (_kbhit())
	{
		switch(_getch())
		{
		case 'a':
				dir = LEFT;
				break;
		case 'd':
				dir = RIGHT;
				break;
		case 'w':
				dir = UP;
				break;
		case 's':
				dir = DOWN;
				break;
		case 'x':
				gameOver = true;
				break;
		}
	}
}
void logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > width || x < 0 || y > height || y < 0)
		gameOver = true;
	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	
		if (x == FruitX && y == FruitY)
		{
		score += 10;
		FruitX = rand() % width;
		FruitY = rand() % height;
		nTail++;
        }

		/*if (x == FruitXX && y == FruitYY)
		{
			score += 20;
			FruitXX = rand() % width;
			FruitYY = rand() % height;
			nTail++, nTail++;
			
		}
		*/
		if (x == FruitXXX && y == FruitYYY)
		{
			score -= 10;
			FruitXXX = rand() % height;
			FruitYYY = rand() % width;
			nTail--;
		}
		if (x == FruitXXXX && y == FruitYYYY)
		{
			FruitXXXX = rand() % height;
			FruitYYYY = rand() % width;
		}

}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		logic();
	}



	return 0;
}