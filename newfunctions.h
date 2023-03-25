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
4. [] Gameover Screen
5. [] Win Screen
6. [] Lose Screen
*/

/*********************************************************************************************/

/* When you leave a shop, day increases by 1, debt increases by 15% or (0.15) */
int nextday(int *day, int *debt) // CHECKED
{
	*day = *day + 1;
	*debt = *debt * 1.15 + 1;
	/* 15% more than 50000 is 57500 */
}

