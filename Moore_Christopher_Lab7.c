/*
	Name: Kiely Moore
	Date: 2-29-2020
	Lab: #7
	Description: Phonebook; added features of alphabetical sorting,
	             number lookup on name, random friend selection,
	             and deletion of whole contact list
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
void alphabetSort(entry *, int);
void pickRandom(entry *, int);
void nameToLower(char []);
void swap(entry *,int);

int main()
{
	int numStruct = 0; //used to keep count of # phonebook entries 
	int quit = 1; //set to zero to end the program	
	int expansion = 1; //used to keep track of number of 
	

	//initialize and allocate memory for phonebook
	int entry_size = sizeof(entry);
	entry *phoneBook = calloc(10,entry_size); 
		
	
	printf("\n === PhoneBook === \n");
	
	do //The menu of the phone book
	{
		int pbsize = sizeof(phoneBook);
		
		int choice;//the operation the user chooses
		printf("\n --- Menu ---\n");
		printf(" 1) Add Entry\n");
		printf(" 2) Remove Entry\n");
		printf(" 3) Display Entries\n");
		printf(" 4) Sort Contacts Alphabetically\n");
		printf(" 5) Pick a random Friend\n");
		printf(" 6) Clear Contacts\n");
		printf(" 0) Quit Program\nEnter Choice: ");
		scanf("%d", &choice);;
		
		switch(choice)
		{
			case 1: //add entry to phonebook
				
				if((numStruct*entry_size) == pbsize) // reallocates mem if needed, add ten "empty contacts"
				{
					expansion++;
					entry * newPhoneBook = realloc(phoneBook,(10*expansion)*entry_size);//creates a new phonebook of expanded mem
					
					int index = 0;
					for(index; index<numStruct;index++)//copys old phonebook into the new one
					{
						strcpy(newPhoneBook[index].first,phoneBook[index].first);
						strcpy(newPhoneBook[index].last,phoneBook[index].last);
						strcpy(newPhoneBook[index].phone,phoneBook[index].phone);
					}
					phoneBook = newPhoneBook;
					free(newPhoneBook); 
				}	
				
				add(phoneBook, numStruct);
				numStruct++;
				printf("\nContact Added\n");
				break;
			
			case 2: //remove entry from phoneBook
				if(numStruct == 0)
					printf("\nOops! Your PhoneBook is empty.\nTry adding some friends!\n");
				else
				{
					if(remov(phoneBook, numStruct)) //returns 1 if entry was removed and zero if it failed
					{
						printf("\nContact Removed\n");
						numStruct--;
						
						//reallocate memmory if there are 10 "empty spaces" in the phonebook
						if(pbsize == (10*(expansion+1)*entry_size))
						{
							expansion--;
							entry *newPhoneBook = realloc(phoneBook,(10*expansion)*entry_size); //creates new entry structure with less mem
							
							int index=0;
							for(index; index<numStruct;index++)//copys old phonebook into new one
							{
								strcpy(newPhoneBook[index].first,phoneBook[index].first);
								strcpy(newPhoneBook[index].last,phoneBook[index].last);
								strcpy(newPhoneBook[index].phone,phoneBook[index].phone);
							}
							phoneBook = newPhoneBook;
							free(newPhoneBook); 
						}
					}	
				}	
				break;
			
			case 3: // Display contents of phonebook
				if(numStruct == 0)
					printf("\nOops! Your PhoneBook is empty.\nTry adding some friends!\n");
				else
					display(phoneBook, numStruct); //display contents of phone book
				break;
			
			case 4: //Alphabetically sort phonebook
				if(numStruct == 0)
					printf("\nOops! Your PhoneBook is empty.\nTry adding some friends!\n");
				else
				{
					alphabetSort(phoneBook, numStruct); //sort list alphabetically
					display(phoneBook, numStruct); //display phone book after sorting
					printf("\nContacts Sorted\n");
				}
				break;
			
			case 5: //pick random entry in phone book and show it to the user
				if(numStruct == 0)
					printf("\nOops! Your PhoneBook is empty.\nTry adding some friends!\n");
				else
					pickRandom(phoneBook, numStruct); //return a random contact
				break;
			
			case 6: //clear contents of phonebook
				if(numStruct == 0)
					printf("\nOops! Your PhoneBook is empty.\nTry adding some friends!\n");
				else
				{
					//frees mem of old phone book and defines a new one. 
					free(phoneBook);
					entry *phoneBook = calloc(10, entry_size);
					
					//reset all global variables
					numStruct = 0;
					expansion = 1;
					
					printf("\nPhoneBook has been cleared.\n");
				}
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
	//Temporary variables for moving items in array
	char tempf[13];
	char templ[21];
	
	printf("First Name: ");
	scanf("%s",tempf);
	printf("Last Name: ");
	scanf("%s",templ);
	
	//turns the string into all lower case;
	nameToLower(tempf);
	nameToLower(templ);
	
	int i = 0;
	for(i;i<numEntry;i++)
	{
		//variable to store names from phonebook so that
		//we can change them without affect the item in phonebook
		char contactf[13];
		char contactl[21];
		strcpy(contactf,item[i].first);
		strcpy(contactl,item[i].last);
		
		//set all letter to lower case
		nameToLower(contactf);
		nameToLower(contactl);
		
		int cmpf,cmpl;
		cmpf = strcmp(contactf,tempf);
		cmpl = strcmp(contactl,templ);
		
		if(cmpf==0 && cmpl==0) //checks if first name and last name are the same
		{
			int j = i;
			for(j;j<numEntry-1;j++)
			{
				//moves every item one index down in array
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

void alphabetSort(entry *item, int numEntry) 
{
	//iterate through phone book
	int iter = 0;
	for(iter;iter<numEntry;iter++)
	{
		int index = 0;
		
		for(index;index<numEntry-1;index++)
		{
			
			//if the entries have the same last name we order it by firstname
			int cmp = strcmp(item[index].last,item[index+1].last);
			if(cmp == 0)
			{
				//compares letters in the first names of the current item and the one after it
				int firstlet = 0;
				for(firstlet; firstlet < 13; firstlet++)
				{
					char curr_init = item[index].first[firstlet];
					curr_init = tolower(curr_init);
					char comp_init = item[index+1].first[firstlet];
					comp_init = tolower(comp_init);
					
					if(curr_init > comp_init)
					{
						//swaps item of place index with the one after it
						swap(item,index);
					}
				}
			}
			else
			{
				//comares the last names of the entries
				int lastlet = 0;
				for(lastlet; lastlet<21; lastlet++)
				{
					char curr_init = item[index].last[lastlet];
					curr_init = tolower(curr_init);	
					char comp_init = item[index+1].last[lastlet];
					comp_init = tolower(comp_init);
					
					if(curr_init > comp_init)
					{
						//swaps item of place index with the one after it
						swap(item,index); 
					}
				}	
				
			}
		}
	}
}

void pickRandom(entry *item, int numEntry)
{
	//generate a random number in the range of indexes in phonebook
	srand(time(NULL));
	int randNum = rand()%numEntry;
	
	//display ranomly chosen entry
	printf("\nGive this contact a Call:\n");
	printf("%s %s\n",item[randNum].first,item[randNum].last);
	printf("%s\n",item[randNum].phone);
	
}

void nameToLower(char string[])
{		
	int length, index;
	length = strlen(string);
	
	for(index = 0; index<length; index++)
	{
		string[index] = tolower(string[index]);
	}
}

void swap(entry *item, int index)
{
	//temporary variables for storing member data
	char temp_first[13];
	char temp_last[21];
	char temp_phone[14];
			
	strcpy(temp_first,item[index].first);
	strcpy(temp_last,item[index].last);
	strcpy(temp_phone,item[index].phone);

	strcpy(item[index].first,item[index+1].first);
	strcpy(item[index].last,item[index+1].last);
	strcpy(item[index].phone,item[index+1].phone);

	strcpy(item[index+1].first, temp_first);
	strcpy(item[index+1].last, temp_last);
	strcpy(item[index+1].phone, temp_phone);
}
