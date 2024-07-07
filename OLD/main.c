#include <windows.h> // for sleep()
#include <stdio.h>
#include <stdlib.h> // for flush(), system()
#include <time.h>	// for rand()
#include "functions.h"

/*
Name: Jack Clavano
Class: CCPROG1 S18B
Date: 2022-11-25
Machine Project 1: Gilgamesh's Mega Gil Adventures
File name: main.c
*/

int main() /* Driver Code */
{
	/*********************************************************************************************/
	/* CHOICES */
	/* remember to reset to 0 and flush(stdin) */
	char cchoice; // for game
	int nchoice;
	char titlechoice;
	// int buysellchoice;

	/* pointers to above variables in order to edit directly */
	char *cchoiceptr;
	cchoiceptr = &cchoice; // for y/n
	int *nchoiceptr;
	nchoiceptr = &nchoice; // for 1-0
	char *titlechoiceptr;
	titlechoiceptr = &titlechoice; // for title screen choice
								   /* CHOICES END */

	/* ATM MECHANISM */
	int gilbank = 0;  // Gilgamesh starts off with 0 at the bank
	int transfer = 0; // number to be added or subtracted from gilbank and gil
					  /* ATM MECHANISM END*/

	/* MAIN VARIALBLES */
	int gil = 20000;
	int debt = 50000;
	int day = 1;
	int earned = 0; /* for total profit displayed at the end of the game */
	/* pointers for main variables */
	int *gilptr;
	gilptr = &gil;
	int *debtptr;
	debtptr = &debt;
	int *dayptr;
	dayptr = &day;
	int *gilbankptr;
	gilbankptr = &gilbank;
	int *earnedptr;
	earnedptr = &earned;
	/* MAIN VARIABLES END */

	/* SHOP PRICES */
	/* Prices for Items in the shop*/
	int gilPD, gilEE, gilPI, gilGM, gilSC, gilAD, gilDM, gilTR;
	/* Multiplier for Buying/Selling Items */
	int buyPD, buyEE, buyPI, buyGM, buySC, buyAD, buyDM, buyTR;
	/* If buying more than one, gilPD * buyPD. */
	/* Temp Prices if buying more than one, reset to 0 if bought */
	int tempPD, tempEE, tempPI, tempGM, tempSC, tempAD, tempDM, tempTR;
	/* SHOP PRICES END */

	/* INVENTORY */
	int pd, ee, pi, gm, sc, ad, dm, tr;
	/* on hand items amount whose worth depends on random num generator when entering shops*/
	pd = 0; // Phoenix Down
	ee = 0; // Elixir Essence
	pi = 0; // Platinum Ingot
	gm = 0; // Golden Materia
	sc = 0; // Scarletite
	ad = 0; // Adamantite
	dm = 0; // Dark Matter
	tr = 0; // Trapezohedron
	/* pointers for INVENTORY */
	int *pdptr; // Pheonix Down
	pdptr = &pd;
	int *eeptr; // Elixir Essence
	eeptr = &ee;
	int *piptr; // Platinum Ingot
	piptr = &pi;
	int *gmptr; // Golden Materia
	gmptr = &gm;
	int *scptr; // Scarletite
	scptr = &sc;
	int *adptr; // Adamantite
	adptr = &ad;
	int *dmptr; // Darkmatter
	dmptr = &dm;
	int *trptr; // Trapezohedron
	trptr = &tr;
	/* INVENTORY END */

	/*********************************************************************************************/
	/* display loading screen */
	loadingscreen();
	system("cls");
	/* display start prompt */
	titlescreen(cchoiceptr);

	/* main game start, main game loops if day is 1-30<31, or if choice is not ever 8 */
	do
	{
		switch (cchoice)
		{
		case 'y':
		{
			nextday(dayptr, debtptr);
			mainmenu(dayptr, gilptr, debtptr, nchoiceptr);

			switch (nchoice)
			{
			case '1':
			{
				system("cls");
				shoptycoon(nchoiceptr, gilptr, pdptr, eeptr, piptr, gmptr, scptr, adptr, dmptr, trptr, gilPD, gilEE, gilPI, gilGM, gilSC, gilAD, gilDM, gilTR);
				break;
			}
			case '2':
			{
				system("cls");
				shoppulsian();
				break;
			}
			case '3':
			{
				system("cls");
				shoparchadian();
				break;
			}
			case '4':
			{
				system("cls");
				shopcid();
				break;
			}
			case '5':
			{
				system("cls");
				shopgaian();
				break;
			}
			case '6':
			{
				system("cls");
				shopriches();
				break;
			}
			case '7':
			{
				system("cls");
				atm(nchoiceptr, dayptr, gilptr, debtptr, earnedptr, gilbankptr, transfer);
				break;
			}
			case '8':
			{
				system("cls");
				break;
				return 0;
			}
			}
		}
		case 'n':
			return 0;
		default:
			return 0;
		}
	} while (day < 31 || cchoice != 'y');
	/* Loop unless day reaches 30, choice is 8/Quit, or cchoice is n*/

	/* At the end of 30 days or choice is n/q to Quit, check if win or lose */
	if (debt <= 0)
		win(dayptr, gilptr, debtptr, earnedptr);
	else
		lose(dayptr, gilptr, debtptr, earnedptr);
}
