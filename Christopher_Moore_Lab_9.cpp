/*
	Name: Christopher K. Moore
	Date: 3/20/2020
	Description: 1 player tic-tac-toe utilizing C++ classes 
*/

#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//function prototypes
int winCheck(char );
void userTurn(char );
void compTurn(char );


class  gameBoard 
{	
	public:
		char slots[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; //Used to store where X's and O's have been placed
			 
		void display() //displays the gameboard to console 
		{
			cout << endl << "    A   B   C " << endl;
			int y = 0;
			for(y; y < 3; y++)
			{
				cout << " " << y + 1 << "  ";
				int x = 0;
				for(x; x < 3; x++)
				{
					cout << slots[y][x];
					if (x < 2) cout << " | ";
				}
				cout << endl;
				if (y < 2) cout << "   ===|===|===" << endl;
			}
			cout << endl;
		}	
};

gameBoard board;

int main ()
{
	
	bool gameContinue = true; //gets set to false one a player wins or its a draw
	char user, comp; //holds each players character X or O
	int turns = 0; //counts the number of turns played in the game;
	
	cout << endl << " Welcome to Tic-Tac-Toe" << endl;
	
	//decide player character
	cout<<" Do you want to be X's or O's? (X/O): ";
	while(true)
	{
		cin >> user;
		user = toupper(user);
		
		if(user == 'X')
		{
			comp = 'O';
			break;
		}
		else if(user == 'O')
		{
			comp = 'X';
			break;
		}
		else
		{
			cout << " Input Invalid. (X/O): ";
		}
	
	}
	
	board.display();
	
	//decide game order
	srand(time(0));
	int order = rand() % 2;
	if(order == 0)
		cout << " You go first" << endl;
	else
		cout << " Computer goes first" << endl;
		
	while(true) //Loop of the game of tic-tac-toe;
	{ 	
		if(order == 0) //user goes first
		{
			userTurn(user); turns++;
			if (winCheck(user)) 
			{
				cout << " You Win!";
				break;	
			}
			else if(turns == 9)
			{
				cout <<" Its a Draw";
				break;
			}
			compTurn(comp); turns++;
			if(winCheck(comp))
			{
				cout << " Sorry, You loose.";
				break;
			}
			
		} 
		else //computer goes first
		{
			compTurn(comp); turns++;
			if (winCheck(comp))
			{
				cout << " Sorry, You loose.";
				break; 
			}
			else if(turns == 9)
			{
				cout << " Its a Draw.";
				break;
			} 
			userTurn(user); turns++;
			if (winCheck(user))
			{
				cout << " You Win!";
				break; 
			}
		}
		
	}
	
}

int winCheck(char player)
{
	//array indexes
	int row, col;
	//win directions 
	int vert = 0;
	int horiz = 0;
	
	//check vertical
	for(row = 0; row < 3; row++)
	{
		for(col = 0; col < 3; col++)
		{
			if(board.slots[row][col] == player) vert++;
		}
		if(vert == 3) return 1;
		else vert = 0;
	}
	
	//check horizontal 
	for(col = 0; col < 3; col++)
	{
		for(row = 0; row < 3; row++)
		{
			if(board.slots[row][col] == player) horiz++;
		}
		if(horiz == 3) return 1;
		else horiz = 0;
	}
	
	//Check diagonals
	if(board.slots[1][1] == player)
	{
		if(board.slots[0][0] == player && board.slots[2][2] == player) return 1;
		else if (board.slots[0][2] == player && board.slots[2][0] == player) return 1;
	}
	
	return 0;
}

void userTurn(char character)
{
	int row, col;
	char c;
	bool end_turn = false;
	do
	{	
		while(true) //loop until valid input;
		{
			cout << " Pick Column: ";
			cin >> c;
			c = toupper(c);
			if(c == 'A' || c == 'B' || c== 'C') break;
			else cout << " Invalid input" << endl;
		}
		
		while(true) //loop until valid input 
		{
			cout << " Pick Row: ";
			cin >> row;
			if(row == 1 || row == 2 || row == 3) break;
			else cout << " Invaild input" << endl;
		}
		row--;
		
		switch(c) //turn character input to index
		{
			case 'A': col = 0; break;
			case 'B': col = 1; break;
			case 'C': col = 2; break;
		}
		
		//ends turn if spot chosen is valid
		if (board.slots[row][col] != ' ') cout << "Spot already Filled" << endl;
		else end_turn = true;
		
	}while(!end_turn);
	
	//update the game board
	board.slots[row][col] = character;
	board.display(); 	
}

void compTurn(char character)
{
	int rand_row, rand_col; //randomized indexes
	
	while(true) //loop until a vaild spot is chosen
	{
		rand_row = rand() % 3;
		rand_col = rand() % 3;
		if(board.slots[rand_row][rand_col] == ' ') break;
	}
	
	//update the game board
	board.slots[rand_row][rand_col] = character;
	board.display();
}












