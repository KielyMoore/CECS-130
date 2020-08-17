/*
	Name: Kiely Moore
	Lab #4
	Date: 01/28/2020
	Description: Modifying lab 3 to use more functions and adding three more
	operations to the calculator
*/ 


#include<stdio.h>

//Global variable that when set to false ends the program
int end_check = 1;

void addition(float num1, float num2)
{
	float result;
	result = num1 + num2;
	printf("%.2f + %.2f = %.2f\n",num1,num2,result);
	return;
}

void subtraction(float num1, float num2)
{
	float result;
	result = num1 - num2;
	printf("%.2f - %.2f = %.2f\n",num1,num2,result);
	return;
}

void multiplication(float num1, float num2)
{
	float result;
	result = num1 * num2;
	printf("%.2f x %.2f = %.2f\n",num1,num2,result);
	return;
}

void division(float num1, float num2)
{
	float result;
	result = num1 / num2;
	printf("%.2f / %.2f = %.2f\n",num1,num2,result);
	return;
}

void modulus(int num1, int num2)
{
	int result;
	result = num1 % num2;
	printf("%d %% %d = %d\n",num1,num2,result);
	return;
}

void primeTest(int prime)
{
	//Stays true if the condition in the loop is never true. 
	int isPrime = 1;	
	//loops through the numbers before the prime number to see if it is divisble by any of them
	int i;
	for(i = 2; i < prime; i++)
	{
		int remainder = prime % i;
		if (remainder == 0) 
		{
			printf("not prime: %d x %d = %d\n", i, prime/i, prime);
			isPrime = 0;
			break;
		} 
	}
	//prints depending on the value of isPrime
	if(isPrime) printf("The number is Prime\n");
	return;
}

void power(float base, float exponent)
{
	//result must start at 1 because any number raied to the power of 0 is 1
	float result = 1;
	int i;
	//iterates a number of times eaqual to the value of variable exponent
	for(i = 0; i < exponent; i++) result *= base;
	printf("%.2f ^ %.2f = %.2f\n",base,exponent,result);
	return;
}

void factorial(int num)
{
	//if result is initialized at 0 the final result would be 0; 0x0=0
	int result = 1;
	int i;
	for(i = 2; i <= num; i++)
	{
		result *= i;
	}
	printf("%d! = %d\n",num,result);
	return;
}

void fibonacci (int index)
{
	//Array to hold the values of the Fibonacci sequence
	int sequence[100];
	//We must initialize the first two values to calculate the rest. 
	sequence[0] = 0;
	sequence[1] = 1;
	
	int i;
	for (i = 2; i < 100; i++)
	{
		//the next digit of the fibonnacci sequence is the sum of the previous two digits
		sequence[i] = sequence[i-2] + sequence[i-1];
	}	
	printf("The %d digit of fibonacci is %d\n",index,sequence[index-1]);
	return;
}

void calculator ()
{
	//used to store user choice
	int choice = 0;
	
	//numbers of integer type for options 5 & 6
	int iNumber1 = 0;
	int iNumber2 = 0;
	
	//nunbers of float type for other options
	float fNumber1 = 0;
	float fNumber2 = 0;

	//Print the Calculator Menu
	printf("\nCalculator Menu:\n");
	printf("(1) Addition\n");
	printf("(2) Subtraction\n");
	printf("(3) Multiplication\n");
	printf("(4) Division\n");
	printf("(5) Modulus (integers only)\n");
	printf("(6) Test if prime (integers only)\n");
	printf("(7) Factorial (integers only)\n");
	printf("(8) Power\n");
	printf("(9) Fibonacci sequence (100 max)\n");
	printf("(0) Exit\n");
	printf("\nChoose an operation: ");
	scanf("%d", &choice);
	
	//option 0 ends the program so we must check first if the user has chosen it. 
	if(choice == 0)
	{
		end_check = 0;
		return; 	
	} 
	
	//Option 9 is a unique option. easiest to get it out of the way first. 
	if (choice == 9)
	{
		printf("Enter what digit of Fibonacci you want: ");
		scanf("%d", &iNumber1);
		fibonacci(iNumber1);	
		return; 
	}
	
	//Option 6 and 7 only needs one integer, easiest to check for it right away. 
	if(choice == 6 || choice == 7)
	{
		printf("Enter Number: ");
		scanf("%d", &iNumber1);
		if (choice == 6) primeTest(iNumber1);
		else factorial(iNumber1);
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
		case 1:	addition(fNumber1,fNumber2);
				break;
		//Subtraction	
		case 2: subtraction(fNumber1,fNumber2);
				break;
		//Multiplication
		case 3: multiplication(fNumber1,fNumber2);
				break;
		//Division
		case 4: division(fNumber1,fNumber2);
				break;
		//Modulus
		case 5: modulus(iNumber1,iNumber2);
				break;
		//Power
		case 8: power(fNumber1,fNumber2);
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
