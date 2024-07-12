/**
 * STATUS: UNFINISHED
 * @author: Jack Clavano
 * @date: 2024-07-08
 * CCPROG1 Limitations:     Need to create at least 3 functions, no global variables,
 *      break only allowed in switch statements, no goto and continue. Arrays, Strings, and
 *      Struct usage not required but allowed. Pointer usage required.
 * CCPROG1 Bonus:           Random battles, background music, random events, etc.
 * CITRAP Cleanup:          Includes arrays and struct usage.
 */
#include <stdio.h>     // FOR: i/o, structs
#include <time.h>      // FOR: rand()
#include <string.h>    // FOR: string manipulation
#include "functions.h" // user-defined functions required for the game

#define MAX_STRING_LEN 50

typedef struct
{
    int pheonixDown;
    int exixirEssence;
    int platinumIngot;
    int goldenMateria;
    int scarletite;
    int adamantite;
    int darkMatter;
    int trapezohedron;
} userInventory;

typedef struct
{
    char name[MAX_STRING_LEN];
    userInventory inventory;
} player;

int game(int day, int gil, int debt)
{
    return 0;
}

int main()
{
    int day = 0;
    int gil = 0;
    int debt = 0;
    char gameOngoing = 'y';
    player p;

    char *shopNames[] = {"Tycoon Meteor's Minerals", "Pulsian Restoratives", "Archadian Luxuries", "Cid's Magical Escapades", "Gaian Gratitudes", "Riches and Minerals of Spira", "Merchant of the Rift"};

    printf("WELCOME TO GILGAMESH'S MEGA GIL ADVENTURES!");
    printf(" Would you like to start a new game? (y/n): ");
    scanf("%c", &gameOngoing);

    // keep game running until 30 days have passed or user quits
    if (gameOngoing == 'y') {
        while (day <= 30 && gameOngoing != 'n') {
            game(day, gil, debt);
        }
    }
    return 0; // exit program
}

/**
 * Introduction Screen
 * Main Menu Screen (Main Rift)
 * Shop Screen - buy/sell items
 * Merchant of the Rift - deposit/withdraw/paydebt/askloan
 *
 * End Game: Quit game/completes 30 days of transactions
 */