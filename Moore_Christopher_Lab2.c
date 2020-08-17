/*
	Name: Kiely Moore
	Lab #2
	Date: 01/14/2020
	Description: Foriegn Currency Exchage
*/

#include<stdio.h>
#include<ctype.h>

int main()
{
	//Defining Conversion factors as Constants
	//Underscore denotes "converting to" 
	//ex: USD_GBP is US Dollars to Great British Pound
	const float USD_GBP = 0.77;
	const float USD_CAD = 1.31;
	const float USD_EUR = 0.90;
	const float USD_AUD = 1.45;
	const float USD_NZD = 1.51;
	
	const float GBP_CAD = 1.70;
	const float GBP_EUR = 1.17;
	const float GBP_AUD = 1.89;
	const float GBP_NZD = 1.97;
	
	const float CAD_EUR = 0.69;
	const float CAD_AUD = 1.11;
	const float CAD_NZD = 1.16;
	
	const float EUR_AUD = 1.61;
	const float EUR_NZD = 1.68;
	
	const float AUD_NZD = 1.04;
	
	//Getting the conversion ammount
	float amnt = 0;
	printf("Enter ammount to Exchange: ");
	scanf("%f", &amnt);
	
	//Creating the table
	printf("\n\t USD \t GPB \t CAD \t EUR \t AUD \t NZD");
	
	printf("\n USD \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f"
	,amnt,amnt/USD_GBP,amnt/USD_CAD,amnt/USD_EUR,amnt/USD_AUD,amnt/USD_NZD);
	
	printf("\n GBP \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f"
	,amnt*USD_GBP,amnt,amnt/GBP_CAD,amnt/GBP_EUR,amnt/GBP_AUD,amnt/GBP_NZD);
	
	printf("\n CAD \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f"
	,amnt*USD_CAD,amnt*GBP_CAD,amnt,amnt/CAD_EUR,amnt/CAD_AUD,amnt/CAD_NZD);
	
	printf("\n EUR \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f"
	,amnt*USD_EUR,amnt*GBP_EUR,amnt*CAD_EUR,amnt,amnt/EUR_AUD,amnt/EUR_NZD);
	
	printf("\n AUD \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f"
	,amnt*USD_AUD,amnt*GBP_AUD,amnt*CAD_AUD,amnt*EUR_AUD,amnt,amnt/AUD_NZD);

	printf("\n NZD \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f \t %4.2f"
	,amnt*USD_NZD,amnt*GBP_NZD,amnt*CAD_NZD,amnt*EUR_NZD,amnt*AUD_NZD,amnt);
}
