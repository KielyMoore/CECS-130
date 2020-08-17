/*
	Christopher Moore
	4/16/2020
	Final Project
	1 player poker
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;


class cardDeck //class that represents a deck of cards.
{
	char cards[36][2]; // [~][0] = card num [~][1] = card suit
public:
	cardDeck(); //constructor
	void shuffle(); //randomize deck
	char *dealCard(int); //return a card form deck
};

cardDeck::cardDeck() //default constructor that fills the card array with all the cards
{
	int index = 0; //goes from 0 - 35
	for(int isuit = 0; isuit < 4; isuit++)
	{
		for(int inum = 0; inum < 9; inum++)
		{
			char ssuit, snum;
			switch(inum)
			{
				case 0: snum = '1'; break;
				case 1: snum = '2'; break;
				case 2: snum = '3'; break;
				case 3: snum = '4';	break;
				case 4: snum = '5'; break;
				case 5: snum = '6'; break;
				case 6: snum = '7'; break;
				case 7: snum = '8'; break;
				case 8: snum = '9'; break;	
			};
			switch(isuit)
			{
				case 0: ssuit = 'C'; break;
				case 1: ssuit = 'S'; break;
				case 2: ssuit = 'H'; break;
				case 3: ssuit = 'D'; break;
			};
			//place card in deck
			cards[index][0] = snum; 
			cards[index][1] = ssuit;
			index++;
		}
	}
}

void cardDeck::shuffle() //shuffle the deck in a random order
{
	cout << "...Shuffling deck..."	<< endl;
	srand(time(0));
	
	//swap each card with a random card in the deck
	for(int i = 0; i <36;i++)
	{
		int rand_index = rand() % 36;
		char temp_card[2];
		
		temp_card[0] = cards[i][0];
		temp_card[1] = cards[i][1];
		cards[i][0] = cards[rand_index][0];
		cards[i][1] = cards[rand_index][1];	
		cards[rand_index][0] = temp_card[0];
		cards[rand_index][1] = temp_card[1];  
	
	}
}

char *cardDeck::dealCard(int index) //return a card from the deck
{
	static char deal_out_card[2];
	deal_out_card[0] = cards[index][0];
	deal_out_card[1] = cards[index][1];
	return deal_out_card;
}

class player //Base class representing a card game player
{
protected:
	char hand[4][2]; //the players hand 
	int bank; //the players money
public:
	void displayHand();
	void addCard(char deal_in_card[2],int index)
	{
		hand[index][0] = deal_in_card[0]; 
		hand[index][1] = deal_in_card[1];
	}
	char *returnCard(int);
	int Bank(){return bank;} //Return value of bank
	void changeMoney(int money){bank+=money;}//adds specified number to bank
};

void player::displayHand() //displays the contents of the players hand 
{
	for (int i = 0; i < 4; i++)
	{
		cout << hand[i][0] << hand[i][1] << " ";
	}
	cout << endl;
}

char *player::returnCard(int index) //returns a card from hand array
{
	static char hand_out_card[2]; 
	hand_out_card[0] = hand[index][0]; //the card num
	hand_out_card[1] = hand[index][1]; //the card suit
	return hand_out_card; 
}

class pokerPlayer : public player //pokerPlayer class derived from player class
{
	int hands_played =0, bets_won =0, bets_lost =0;
public:
	pokerPlayer(){bank = 100;} //default constructor setting the player bank to $100
	void updateStats(bool,int);
	void displayStats();
	
};

void pokerPlayer::updateStats(bool win_true, int change) //update player stats at the end of each round
{
	hands_played++;
	if(win_true) bets_won++;
	else bets_lost++;
	changeMoney(change);
}

void pokerPlayer::displayStats() //display the player stats at the end of the game
{
	cout << "You played a total of " << hands_played << " hand(s)," << endl;
	cout << "of which you won " << bets_won << "," << endl;
	cout << "and lost " << bets_lost << "," << endl;
	cout << "but in the end, you ";
	int winnings = bank - 100;
	if (winnings > 0) cout << "won $" << winnings << endl;
	else if (winnings == 0) cout << "broke even" << endl;
	else cout << "lost $" << abs(winnings) <<endl;
}

int calcResult(pokerPlayer,bool*,int);
int toNum(char);

int main()
{
	cardDeck poker_deck;
	pokerPlayer user;
	bool game = true;
	
	cout << "Welcome to Single Player Poker!" << endl;
	cout << "You start the game with $100 worth of chips" << endl;
	cout << "Pay outs: " << endl;
	cout << "Pair     Two Pair  3 of a kind" << endl;
	cout << "1:1      100:1     150:1" << endl;
	cout << "straigt  flush     straigt flush   4 of a kind" << endl;
	cout << "200:1    250:1     300:1           400:1" << endl;
	cout << "=================================================" << endl;

	while(game)
	{
		int bet; //the amount of money bet by player 
		bool result; //true if player won hand, false if lost
		
		while(true) //loop until valid input
		{
			cout << "Place a bet (0 - " << user.Bank() << "): ";
			cin >> bet;
			if(bet >= 0 && bet <= user.Bank()) break;
		}
	
		cout << endl;
		poker_deck.shuffle();
		
		for(int j = 0; j < 4; j++) //deal cards into palyer hand
		{
			char *dealt_card = poker_deck.dealCard(j);
			user.addCard(dealt_card,j);
		}
		
		cout << "Here are your cards: " << endl;
		user.displayHand();	
		bet = calcResult(user, &result, bet); //determine the result of the hand and set bet to the ammount the player wins or loses	
		user.updateStats(result , bet); //update the stats of the game
		cout << endl;
		
		if(user.Bank() == 0) //game ends if the player has no money
		{
			cout << "You have no more money" << endl;
			break;
		}
		
		cout << "Current Balance: " << user.Bank() << endl;
		
		while(true) //loop until a valid input
		{
			char response;
			cout << "Play another hand (y/n): ";
			cin >> response;
			if(response == 'y' || response == 'Y') break;
			else if (response == 'n' || response == 'N') {game = false; break;}
		}
		
		
	}
    cout << "=================================================" << endl;
	user.displayStats(); //endgame message
	cout << "Thanks for playing!" << endl;
}

int calcResult(pokerPlayer pobj, bool *ptr_win, int player_bet)
{
	char player_hand[4][2]; //stores that player hand and allows us to maniplate it.
	char *temp_ptr; //adress for array card
	for(int k = 0; k<4;k++) //move cards into array
	{
		temp_ptr = pobj.returnCard(k);
		player_hand[k][0] = temp_ptr[0];
		player_hand[k][1] = temp_ptr[1];
	}
	
	//sort cards in ascending order
	bool sorted = false;
	char temp_card[2];
	while(!sorted)
	{
		bool swapped = false; //set to true if a swap has occured
		for(int x=0; x<3; x++) //iterate throug the hand
		{
			if(player_hand[x][0] > player_hand[x+1][0]) //swap cards if out of order 
			{
				swapped = true;
				temp_card[0] = player_hand[x][0];
				temp_card[1] = player_hand[x][1];
				player_hand[x][0] = player_hand[x+1][0];
				player_hand[x][1] = player_hand[x+1][1];
				player_hand[x+1][0] = temp_card[0];
				player_hand[x+1][1] = temp_card[1];
			}
		}
		if(!swapped) sorted = true; //if no swapping occured the hand is organized.
	}
	
	//check four of a kind
	if (player_hand[0][0] == player_hand[3][0]) 
	{
		cout << "You got four of a kind and won $" << player_bet * 400 << endl;
		*ptr_win = true;
		return player_bet * 400;
	}
	
	//check for three of a kind 
	if(player_hand[0][0] == player_hand[2][0] || player_hand[1][0] == player_hand[3][0]) 
	{
		cout << "You got three of a kind and won $" << player_bet * 150 << endl;
		*ptr_win = true;
		return player_bet * 150;
	}
	
	//check for two pair
	if(player_hand[0][0] == player_hand[1][0] && player_hand[2][0] == player_hand[3][0])
	{
		cout << "You got two pairs and won $" << player_bet * 100 << endl;
		*ptr_win = true;
		return player_bet * 100;
	}  
	
	//check for pair
	for(int i=0;i<3;i++)
	{
		if(player_hand[i][0] == player_hand[i+1][0])
		{
			cout << "You got a pair and won $" << player_bet << endl;
			*ptr_win = true;
			return player_bet;
		}
	}
	
	//check straight and flush
	bool flush = true;
	for (int f = 0; f<3; f++)
	{
		if(player_hand[f][1] != player_hand[3][1]) flush = false;
	} 
	
	bool straight = true;
	for (int s=0; s<3; s++)
	{
		if (toNum(player_hand[s+1][0]) - toNum(player_hand[s][0]) != 1) straight = false; 
	}
	
	if(straight && flush)
	{
		cout << "You got a straight flush and won $" << player_bet * 300 << endl;
		*ptr_win = true;
		return player_bet * 300;
	} 
	else if (flush) 
	{
		cout << "You got a flush and won $" << player_bet * 250 << endl;
		*ptr_win = true;
		return player_bet * 250;
	}
	else if (straight)
	{
		cout << "You got a straight and won $" << player_bet * 200 << endl;
		*ptr_win = true;
		return player_bet * 200;
	}
	
	//the palyer has nothing
	cout << "You got nothing and lost $" << player_bet << endl;
	*ptr_win = false;
	return -player_bet;
}

int toNum(char c)
{
	switch (c)
	{
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
	}
}


