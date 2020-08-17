/*
	Name: Kiely Moore
	Date: 2-25-2020
	Lab: #6
	Description: Phonebook; add and remove items; display contents
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//phonebook structure 
typedef struct
{
	char first[13];
	char last[21];
	char phone[14];

}entry;	

//function prototypes
void add(entry *, int);
int remov(entry *, int);
void display(entry *, int);

int main()
{
	int numStruct = 0; //used to keep count of # phonebook entries 
	int quit = 1; //set to zero to end the program	
	float expansion = 1; //used to keep track of number of 
	
	//initialize and allocate memory for phonebook
	entry *phoneBook;
	phoneBook = calloc(10,sizeof(entry));  	
	
	printf("%f\n",sizeof(entry));
	printf("%f\n",sizeof(phoneBook));
	
	printf("\n === PhoneBook === \n");
	
	do //The menu of the phone book
	{
		int choice;//the operation the user chooses
		printf("\n --- Menu ---\n 1) Add Entry\n 2) Remove Entry\n 3) Display Entries\n 0) Quit Program\nEnter Choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: //add entry to phonebook
				if((numStruct*sizeof(entry)) == sizeof(phoneBook)){
					expansion++;
					phoneBook = realloc(phoneBook,(10*expansion)*sizeof(entry));
				}	
				add(phoneBook, numStruct);
				numStruct++;
				break;
			
			case 2:
				if(remov(phoneBook, numStruct)) //returns 1 if entry was removed and zero if it failed
				{
					numStruct--;
					
					//reallocate memmory if there are 10 "empty spaces" in the phonebook
					if(sizeof(phoneBook) == (10*(expansion+1)*sizeof(entry))){
						expansion--;
						phoneBook = realloc(phoneBook,(10*expansion)*sizeof(entry));
					}
				}	
				break;
			
			case 3:
				if(numStruct == 0)
					printf("\nOops! Your PhoneBook is empty.\nTry adding some friends!\n");
				else
					display(phoneBook, numStruct); //display contents of phone book
				break;
			
			case 0: 
				quit = 0; //exit the program
				free(phoneBook);//frees the mem used for phoneBook
			default: break;
		}
	} while(quit);		
	printf("Goodbye!");
}

void add(entry *item, int numEntry)
{
	//temporary variables to pass value into phonebook
	char tempFirst[13];
	char tempLast[21];
	char tempPhone[11];
	
	//collect entry information
	printf("Enter First Name: ");
	scanf("%s", tempFirst);
	printf("Enter Last Name: ");
	scanf("%s", tempLast);
	printf("Enter Phone Number: ");
	scanf("%s", tempPhone);
	
	//copy over entry information
	strcpy(item[numEntry].first,tempFirst);
	strcpy(item[numEntry].last,tempLast);
	strcpy(item[numEntry].phone,tempPhone);
	
}

int remov(entry *item, int numEntry)
{
	char tempf[13];
	char templ[21];
	printf("First: ");
	scanf("%s",tempf);
	printf("Last: ");
	scanf("%s",templ);
	
	int i = 0;
	for(i;i<numEntry;i++)
	{
		int cmpf,cmpl;
		cmpf = strcmp(item[i].first,tempf);
		cmpl = strcmp(item[i].last,templ);
		if(cmpf==0 && cmpl==0)
		{
			int j = i;
			for(j;j<numEntry;j++)
			{
				strcpy(item[j].first, item[j+1].first);
				strcpy(item[j].last, item[j+1].last);
				strcpy(item[j].phone, item[j+1].phone);
			}
			return 1;
		}		
	}
	printf("\nOops! Contact does not exist.\n");
	return 0;
}

void display(entry *item, int numEntry)
{
	int i = 0;
	printf("\n[   Contact list   ]");
	for(i;i<numEntry;i++) //iterate through phonebook array and dispay contects
	{
		printf("\n> Contact %d", i+1);
		printf("\n  Name: %s %s",item[i].first,item[i].last);
		printf("\n  Phone #: %s\n",item[i].phone);	
	}
	printf("[                  ]\n");
}

