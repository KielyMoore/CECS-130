/*
	Name: Kiely Moore
	Lab #5
	Date: 2/4/2020
	Description: Short story generator that incorporates user entered strings
		and randomly genrates alternate story elements	
*/

#include <stdio.h>

//Function definitions
void generateTask();
void favoriteColor();
void capitolAssyria();
void unladenSwallow();

int main()
{
	//Creating empty character arrays for user's strings
	char name[12] = {'\0'};
	int filler =0;
	
	printf("What is your name? "); 
	scanf("%s", name);
	
	printf("You are sir %s, One of the Knights of the Round Table. You aid Arthur, son of Uther Pendragon,\n", name);
	printf("King of the Britons, defeator of the Saxons, sovereign of all England, in his quest for the Holy Grail.\n");
	printf("It has been a long and arduous journey and you have faced many challenges,\nlike ");
	
	generateTask(); //Random scene form the movie
	
	printf("\nYou have discovered that the Grail rests in the Castle Aarrggh, the final obstacle between you and the grail");
	printf("\nis the bridge of death. You approach the bridge and the Bridge keeper speaks:\n");
	printf("\"Stop! Who approacheth the Bridge of Death must answer me these questions three, ere the other side he see.\"");
	
	printf("\n\n\"Ask me the questions, bridgekeeper. I'm not afraid.\"");
	
	printf("\n\n\"What is your name?\"");
	
	printf("\n\n\"Sir %s of Camelot.\"", name);
	
	printf("\n\n\"What is your quest?\"");
	
	printf("\n\n\"To seek the Holy Grail.\"");
	
	//ask a random final question
	srand(time(NULL));
	int question_num = rand() % 3;
	switch (question_num)
	{
		case 0:
			favoriteColor(name);
			break;
		case 1:
			capitolAssyria();
			break;
		case 2:
			unladenSwallow();
			break;
	}

	printf("\nSo ends the tale of Sir %s of Camelot.",name);

}

void generateTask()
{
	//Picks a random scene form the movie to add to the story
	srand(time(NULL));
	int randNum = (rand() % 9);
	
	switch (randNum)
	{
		case 0: 
			printf("a knight who refuses to loose despite his lack of limbs.");
			break;
		case 1: 
			printf("peasants who formed an anarcho-syndicalist commune.");
			break;
		case 2: 
			printf("the French.");
			break;
		case 3: 
			printf("great peril in the Castle Anthrax."); //naughty Zoot
			break;
		case 4: 
			printf("an indecicive three headed Knight.");
			break;
		case 5: 
			printf("nights with a tendency to say Ni repetitively.");
			break;
		case 6: 
			printf("saving a beautiful and melodius... errr... Prince?.");
			break;
		case 7: 
			printf("a killer rabbit with a mean streak.");
			break;
		case 8: 
			printf("a horribly animated dragon.");
			break;
	}
	
}

void favoriteColor()
{
	char color[12] = {"\0"};
	char blue[12] = "blue";
	
	printf("\n\n\"What is your favorite color?\" ");
	scanf("%s", color);
	
	//converts every character in the color string to lowercase
	int i = 0;
	for(i; i<11;i++)
	{
		color[i] = tolower(color[i]);
	}
	
	//The correct answer is blue
	if(strcmp(color,blue))
	{
		printf("\nYou hesitate, \"Blue. No, %s! Auuuuuuuugh\"",color);
		printf("\nYou go sailing of the bridge of death to your demise");
	}
	else
	{
		printf("\n\"Blue\" you answer confidently.");
		printf("\n\n\"Right. Off you go.\"");
		printf("\n\n\"Oh. Thank you, thank you very much.\"");
		printf("\nYou pass the bridge in triumph on you way to finish your quest!");
		printf("\nBut before you could meet back up with your fellow knights,");
		printf("\nYou are aprehended by the authorities in an ongoing ivestigation");
		printf("\nof the murder of a famous historian at the end of scene 8.");
	}
}

void capitolAssyria()
{
	char answer[20] = {"\0"};
	char assur[20] = {"assur"}; //the capitol of Assyria
	
	printf("\n\n\"What is the capitol of Assyria?\" ");
	scanf("%s", answer);
	
	//converts every character in the answer string to lowercase
	int i = 0;
	for(i; i<19;i++)
	{
		answer[i] = tolower(answer[i]);
	}
	
	if(strcmp(answer,assur))
	{
		printf("\nYou stand there confused, \"I don't know that! Auuuuuuugh!\"");
		printf("\nYou go sailing of the bridge of death to your demise");
	}
	else
	{
		printf("\nYou weren't supposed to get that right. Theres no senario for this in the movie.");
		printf("\nYou've made a right mess of things. What am I supposed to do? Make something up?");
		printf("\nThats it! I\'m ending the story here.");
	}
}

void unladenSwallow()
{
	char objection[36] = {"\0"};
	char correct[36] = {"is it an african or european swallow"}; //You have to know these things when your king
	
	printf("\n\n\"What is the air-speed velocity of an unladen swallow?\" ");
	char temp;
	scanf("%c",&temp);
	scanf("%[^\n]", objection);;
	
	//converts every character in the answer string to lowercase
	int i = 0;
	for(i; i<35;i++)
	{
		objection[i] = tolower(objection[i]);
	}
	
	if(strcmp(objection,correct))
	{
		printf("\nYou stand there confused, \"I don't know that! Auuuuuuugh!\"");
		printf("\nYou go sailing of the bridge of death to your demise");
	}
	else
	{
		printf("\nThe bridge keeper looks puzzled and says, \"I-- I don't know that. Auuuuuuugh!\"");
		printf("\nThe bridge keeper goes sailing into the air of the bridge of death and you may safely");
		printf("\npass to the other side of the bridge. You make it to Castle Aarrggh to find it overun with");
		printf("\nthe fench! As you assult the castle the police arrive stop production and arrest everyone.");
	}
}

