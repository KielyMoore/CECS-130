/*
	Name: Kiely Moore
	Lab #3
	Date: 01/21/2020
	Description: Simple Calculator Menu Capable of Different Opereations
*/ 

#include<stdio.h>

//Global variable that when set to false ends the program
int end_check = 1;

void calculator ()
{
	//defining all of the variables that will be used
	int choice = 0;
	
	//numbers of integer type for options 5 & 6
	int iNumber1 = 0;
	int iNumber2 = 0;
	
	//nunbers of float type for other options
	float fNumber1 = 0;
	float fNumber2 = 0;
	
	//used to store the result of operations
	int iResult = 0;
	float fResult = 0;

	//Print the Calculator Menu
	printf("\nCalculator Menu:\n");
	printf("(1) Addition\n");
	printf("(2) Subtraction\n");
	printf("(3) Multiplication\n");
	printf("(4) Division\n");
	printf("(5) Modulus (integers only)\n");
	printf("(6) Test if prime (integers only)\n");
	printf("(7) Exit\n");
	
	printf("\nChoose an operation: ");
	scanf("%d", &choice);
	
	//option 7 ends the program so we must check first if the user has chosen it. 
	if(choice == 7)
	{
		end_check = 0;
		return; 	
	} 
	
	//Option 6 only needs one integer, easiest to check for it right away. 
	if(choice == 6)
	{
		int isPrime = 1;
		int prime = 0;
		printf("Enter Number: ");
		scanf("%d", &prime);
		
		//loops through the numbers before the prime number to see if it is divisble by any of them
		int i;
		for(i = 2; i < prime; i+=1)
		{
			int remainder = prime % i;
			if (remainder == 0) 
			{
				printf("not prime: %d x %d = %d\n", i, prime/i, prime);
				isPrime = 0;
				break;
			} 
		}
		if(isPrime) printf("The number is Prime\n");
		return;
	}		
	
	//options 5 is integer only. 
	//So depending on user choice, the value entered is assigned to a variable of appropriate type
	printf("Enter the first Number: ");	
	if(choice == 5)
	{
		scanf("%d", &iNumber1);
	} 
	else
	{
		scanf("%f", &fNumber1);
	}

	printf("Enter the second Number: ");
	if(choice == 5)
	{
		scanf("%d", &iNumber2);
	} 
	else
	{
		scanf("%f", &fNumber2);
	}


	//Executes chosen operation on the input numbers. 
	switch(choice)
	{
		//Addition
		case 1: fResult = fNumber1 + fNumber2;
				printf("%.2f + %.2f = %.2f\n", fNumber1, fNumber2, fResult);
				break;
		//Subtraction	
		case 2: fResult = fNumber1 - fNumber2;
				printf("%.2f - %.2f = %.2f\n", fNumber1, fNumber2, fResult);
				break;
		//Multiplication
		case 3: fResult = fNumber1 * fNumber2;
				printf("%.2f x %.2f = %.2f\n", fNumber1, fNumber2, fResult);
				break;
		//Division
		case 4: fResult = fNumber1 / fNumber2;
				printf("%.2f / %.2f = %.2f\n", fNumber1, fNumber2, fResult);
				break;
		//Modulus
		case 5: iResult = iNumber1 % iNumber2;
				printf("The remainder is: %d\n", iResult);
				break;
	}	
}

int main ()
{
	//Loops untile the user enter 7
	while(end_check)
	{
		calculator();
	}
	printf("Goodbye.");
}
