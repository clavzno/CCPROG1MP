#include <windows.h> // for sleep()
#include <stdio.h>
#include <stdlib.h> // for flush(), system()
#include <time.h>	// for rand()

/* HEADER FILE FOR FUNCTIONS */

/* Includes:
0. [x] Loading Screen
1. [x] Title Screen
2. [x] Main Menu
3. Shop Screen
	1. [] Tycoon Meteor's Materials (Trapezohedron 35000-65000)
	2. [] Pulsian Restoratives (Phoenix Down 300-800, Elixir Essence 1000-1700)
	3. [] Archadian Luxuries (Platinum Ingot 4500-6000)
	4. [] Cid's Magical Escapades (Golden Materia 3000-5000)
	5. [] Gaian Gratitudes (Scarletite 5000-10000)
	6. [] Riches and Minerals of Spira (Adamantite 9500-20000 Dark Matter 22000-50000)
	7. [] Merchant of the Rift
	8. [x] Leave
4. Gameover Screen
5. Win Screen
6. Lose Screen
*/

/*********************************************************************************************/

/* When you leave a shop, day increases by 1, debt increases by 15% or (0.15) */
int nextday(int *day, int *debt) // CHECKED
{
	*day = *day + 1;
	*debt = *debt * 1.15 + 1;
	/* 15% more than 50000 is 57500 */
}

/* List of Shops */
// import all variables needed for shopdisplay and shopprice
void shoptycoon(int *nchoice, int *gilptr, int* pdptr, int* eeptr, int* piptr, int* gmptr, int* scptr, int* adptr, int* dmptr, int* trptr, int gilPD, int gilEE, int gilPI, int gilGM, int gilSC, int gilAD, int gilDM, int gilTR) // GO BACK HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int multiplier; // Multiplier for prices
	char buysell;	// for buy sell chaice
	char confirmbuy;
	char confirmsell;
	printf("You chose to go to Tycoon Meteor's Minerals");

	sleep(1);
	system("cls");

	do //dowhile for entire shop loop
	{
		shoppriceTycoon(int gilPD, int gilEE, int gilPI, int gilGM, int gilSC, int gilAD, int gilDM, int gilTR);
		shopdisplay(int *nchoice, int pdptr, int eeptr, int piptr, int gmptr, int scptr, int adptr, int dmptr, int trptr, int gilPD, int gilEE, int gilPI, int gilGM, int gilSC, int gilAD, int gilDM, int gilTR);
		printf("Your Choice: ");
		scanf("%d", nchoice);
		fflush(stdin);

		switch (nchoice):
			case 1:
				system("cls");
		printf("You chose Phoenix Down");
		sleep(1);
		system("cls");

		do //dowhile for buysell for each item
		{
			printf("Do you want to buy or sell Pheonix Down?");
			printf("[B] to buy, [S] to sell. [E] to exit and return to shop.");
			scanf("%c", &buysell);

			do //dowhile for looping buysell mechanism
			{
				if (buysell == 'B' || buysell == 'b')
				{
					printf("How many Phoenix Downs would you like to buy?\n");
					printf("Your choice: ")
					scanf("%d", multiplier);
					price = gilPD * multiplier;
					printf("Would you like to buy %d Phoenix Downs for %d gil? [Y]es or [N]o\n", multiplier, price);
					printf("Gil: %d\n", *gilptr);
					printf("On Hand: %d\n", *pdptr);
					printf("Your choice: ");
					scanf("%c", &confirmbuy);
					fflush(stdin);
					if (confirmbuy == 'Y' || confirmbuy == 'y')
					{
						printf("Transaction Confirmed.");
						*gil = *gil - price;
						pd = pd + multiplier;
						return 0;
					}
					else 
					{
						printf("Transaction Cancelled.")
						return 0;
					}
					
				}
				else if (buysell == 'S' || buysell == 's')
				{
					printf("How many Pheonix Downs would you like to sell?");
					printf("Gil: %d\n", *gilptr);
					printf("On Hand: %d\n", *pdptr);
					printf("Your choice: ");
				}
				else
					printf("Invalid option.");

			} while (buysell == 's' || buysell == 'S' || buysell == 'b' || buysell == 'B') //loop if choice is buy or sell
		} while (buysell !== 'e' || buysell !== 'E') //loop unless exit choice

			break; //break for case 1
	case 2:
		system("cls");
		printf("You chose to buy an Elixir Essence");
		printf("How many Elixir Essences would you like to buy?");
		scanf("%d", ee);
		price = ee * 1000;
		printf("You bought %d Elixir Essences for %d gil", ee, price);
		fflush(stdin);
		break;
	case 3:
		system("cls");
		printf("You chose to buy a Platinum Ingot");
		printf("How many Platinum Ingots would you like to buy?");
		scanf("%d", pi);
		price = pi * 4500;
		printf("You bought %d Platinum Ingots for %d gil", pi, price);
		fflush(stdin);
		break;
	case 4:
		system("cls");
		printf("You chose to buy Golden Materia");
		printf("How many Golden Materia would you like to buy?");
		scanf("%d", gm);
		price = gm * 3000;
		printf("You bought %d Golden Materia for %d gil", gm, price);
		fflush(stdin);
		break;
	case 5:
		system("cls");
		printf("You chose to buy a Scarletite");
		printf("How many Scarletites would you like to buy?");
		scanf("%d", sc);
		price = sc * 5000;
		printf("You bought %d Scarletites for %d gil", sc, price);
		fflush(stdin);
		break;
	case 6:
		system("cls");
		printf("You chose to buy an Adamantite");
		printf("How many Adamantites would you like to buy?");
		scanf("%d", ad);
		price = ad * 9500;
		printf("You bought %d Adamantites for %d gil", ad, price);
		fflush(stdin);
		break;
	case 7:
		system("cls");
		printf("You chose to buy Dark Matter");
		printf("How many Dark Matters would you like to buy?");
		scanf("%d", dm);
		price = dm * 22000;
		printf("You bought %d Dark Matters for %d gil", dm, price);
		fflush(stdin);
		break;
	case 8:
		system("cls");
		printf("You chose to buy a Trapezohedron");
		printf("How many Trapezohedrons would you like to buy?");
		scanf("%d", tr);
		price = tr * 35000;
		printf("You bought %d Trapezohedrons for %d gil", tr, price);
		fflush(stdin);
		break;
	case 9:
		system("cls");
		printf("You chose to leave");
		return 0;
	} while (nchoice != 9);
}

void shoppulsian()
{
	printf("You chose to go to Pulsian Restoratives");
	sleep(1);
	system("cls");
}

void shoparchadian()
{
	printf("You chose to go to Archadian Luxuries");
	sleep(1);
	system("cls");
}

void shopcid()
{
	printf("You chose to go to Cid's Magical Escapades");
	sleep(1);
	system("cls");
}

void shopgaian()
{
	printf("You chose to go to Gaian Gratitudes");
	sleep(1);
	system("cls");
}

void shopriches()
{
	printf("You chose to go to Riches and Minerals of Spira");
	sleep(1);
	system("cls");
}

/* Extra: Loading Screen */
void loadingscreen()
{
	int i, j, a;

	printf("Loading");

	for (i = 0; i <= 6; i++)
	{
		for (j = 0; sleep(1); j++)
			j = a;
		printf(".");
	}
	printf("\n");
}

/* Shop Functions */
// GO BACK HERE!!!!!!!!!!!!!!!!!!!!!!!
// num choice, on hand, prices
void shopdisplay(int *nchoice, int pd, int ee, int pi, int gm, int sc, int ad, int dm, int tr, int gilPD, int gilEE, int gilPI, int gilGM, int gilSC, int gilAD, int gilDM, int gilTR)
{
	printf("Item                   On Hand        Price\n");
	printf("[1] Phoenix Down          %d           %d   \n", pd, gilPD);
	printf("[2] Elixir Essence        %d           %d   \n", ee, gilEE);
	printf("[3] Platinum Ingot        %d           %d   \n", pi, gilPI);
	printf("[4] Golden Materia        %d           %d   \n", gm, gilGM);
	printf("[5] Scarletite            %d           %d   \n", sc, gilSC);
	printf("[6] Adamantite            %d           %d   \n", ad, gilAD);
	printf("[7] Darkmatter            %d           %d   \n", dm, gilDM);
	printf("[8] Trapezohedron         %d           %d   \n", tr, gilTR);
	printf("[9] Leave (Costs 1 Day)\n");

	printf("Your Choice: ");
	scanf("%d", &nchoice);
}

/* Checks if Item is available */
int isavail()
{
	int avail;
	avail = rand() % 10 + 1;
	if (avail >= 3)
		return 1;
	else
		return 0;
}

void shoppriceTycoon(int gilPD, int gilEE, int gilPI, int gilGM, int gilSC, int gilAD, int gilDM, int gilTR)
{
	gilPD = 500 + (rand() % (500 - 1200));
	gilEE = 1500 + (rand() % (1500 - 2100));
	gilPI = 5000 + (rand() % (5000 - 7000));
	gilGM = 3500 + (rand() % (3500 - 5500));
	gilSC = 8000 + (rand() % (8000 - 12000));
	gilAD = 15000 + (rand() % (15000 - 30000));
	gilDM = 40000 + (rand() % (40000 - 70000));

	gilTR = 35000 + (rand() % (35000 - 65000));
	// Trapezohedron 35000-65000
}

void shoppricePulsian(int gilPD, int gilEE, int gilPI, int gilGM, int gilSC, int gilAD, int gilDM, int gilTR)
{
	gilPD = 500 + (rand() % (500 - 1200));
	// Pheonix Down 300-800
	gilEE = 1000 + (rand() % (1000 - 1700));
	// Elixir Essence 1000-1700

	gilPI = 5000 + (rand() % (5000 - 7000));
	gilGM = 3500 + (rand() % (3500 - 5500));
	gilSC = 8000 + (rand() % (8000 - 12000));
	gilAD = 15000 + (rand() % (15000 - 30000));
	gilDM = 40000 + (rand() % (40000 - 70000));
	gilTR = 60000 + (rand() % (60000 - 90000));
}

void shoppriceArchadian(int gilPD, int gilEE, int gilPI, int gilGM, int gilSC, int gilAD, int gilDM, int gilTR)
{
	gilPD = 500 + (rand() % (500 - 1200));
	gilEE = 1500 + (rand() % (1500 - 2100));

	gilPI = 4500 + (rand() % (4500 - 6000));
	// Platinum Ingot 4500-6000

	gilGM = 3500 + (rand() % (3500 - 5500));
	gilSC = 8000 + (rand() % (8000 - 12000));
	gilAD = 15000 + (rand() % (15000 - 30000));
	gilDM = 40000 + (rand() % (40000 - 70000));
	gilTR = 60000 + (rand() % (60000 - 90000));
}

void shoppriceCid(int gilPD, int gilEE, int gilPI, int gilGM, int gilSC, int gilAD, int gilDM, int gilTR)
{
	gilPD = 500 + (rand() % (500 - 1200));
	gilEE = 1500 + (rand() % (1500 - 2100));
	gilPI = 5000 + (rand() % (5000 - 7000));

	gilGM = 3000 + (rand() % (3000 - 5000));
	// Golden Materia 3000-5000

	gilSC = 8000 + (rand() % (8000 - 12000));
	gilAD = 15000 + (rand() % (15000 - 30000));
	gilDM = 40000 + (rand() % (40000 - 70000));
	gilTR = 60000 + (rand() % (60000 - 90000));
}

void shoppriceGaian(int gilPD, int gilEE, int gilPI, int gilGM, int gilSC, int gilAD, int gilDM, int gilTR)
{
	gilPD = 500 + (rand() % (500 - 1200));
	gilEE = 1500 + (rand() % (1500 - 2100));
	gilPI = 5000 + (rand() % (5000 - 7000));
	gilGM = 3500 + (rand() % (3500 - 5500));

	gilSC = 5000 + (rand() % (5000 - 10000));
	// Scarletite 5000 - 10000

	gilAD = 15000 + (rand() % (15000 - 30000));
	gilDM = 40000 + (rand() % (40000 - 70000));
	gilTR = 60000 + (rand() % (60000 - 90000));
}

void shoppriceRiches(int gilPD, int gilEE, int gilPI, int gilGM, int gilSC, int gilAD, int gilDM, int gilTR)
{
	gilPD = 500 + (rand() % (500 - 1200));
	gilEE = 1500 + (rand() % (1500 - 2100));
	gilPI = 5000 + (rand() % (5000 - 7000));
	gilGM = 3500 + (rand() % (3500 - 5500));
	gilSC = 8000 + (rand() % (8000 - 12000));

	gilAD = 9500 + (rand() % (9500 - 20000));
	// Adamantite 9500-20000
	gilDM = 22000 + (rand() % (22000 - 50000));
	// Dark Matter 22000- 50000

	gilTR = 60000 + (rand() % (60000 - 90000));
}

/* Title Screen */
void titlescreen(char *cchoiceptr)
{
	printf("WELCOME TO GILGAMESH'S MEGA GIL ADVENTURES!\n");
	printf("\n");
	printf("start a new game [y] or exit [n]\n");
	scanf("%c", cchoiceptr);
}

/* Main Menu */
void mainmenu(int *day, int *gil, int *debt, char *cchoice)
{
	nextday(day);
	printf("Gilgamesh: Where should my travels take me to?\n\n");
	printf("[1] Tycoon Meteor's Minerals\t\t\tDay: #%d\n", day);
	printf("[2] Pulsian Restoratives\t\t\tGil: %d\n", gil);
	printf("[3] Archadian Luxuries\t\t\t\tDebt: %d\n", debt);
	printf("[4] Cid's Magical Escapades\n");
	printf("[5] Gaian Gratitudes\t\t\t\t[8] Quit Game\n");
	printf("[6] Riches and Minerals of Spira\n");
	printf("[7] Go see the Merchant of the Rift\n");
	printf("\n");
	printf("Your Choice: ");
	scanf("%d", cchoice);
	fflush(stdin);
}

/* Merchant of the Rift */
void atm(int *nchoice, int *day, int *gil, int *debt, int *earned, int *gilbank, int transfer)
{
	printf("You chose to go to the Merchant of the Rift");
	sleep(1);
	system("cls");
	printf("day is %d", *day);
	printf("gil is %d", *gil);
	printf("debt is at %d", *debt);
	printf("you earned %d", *earned);
	printf("stored %d in the bank", *gilbank);
}

void win(int *day, int *gil, int *debt, int *earned)
{
	printf("CONGRATULATIONS! YOU HAVE PAID YOUR DEBT WITHIN 30 DAYS!");
	printf("Remaining Debt		[%d]\n", *debt);
	printf("Remaining Gil		[%d]\n", *gil);
	printf("Total Profit		[%d]\n", *earned");
	printf("Total Days	    	[%d]\n", *day);
}

void lose(int *debt, int *gil, int *earned, int *day)
{
	printf("GAME OVER");
	sleep(1);
	system("cls");
	printf("GAME OVER");
	sleep(1);
	system("cls");
	printf("GAME OVER");
	sleep(1);
	system("cls");

	printf("YOU LOST THE GAME AND HAVE FAILED TO PAY YOUR DEBT!\n");
	printf("Remaining Debt		[%d]\n", *debt);
	printf("Remaining Gil		[%d]\n", *gil);
	printf("Total Profit		[%d]\n", *earned");
	printf("Total Days	    	[%d]\n", *day);
}
