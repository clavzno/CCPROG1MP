#include <windows.h> // for Sleep()
#include <unistd.h>  // for sleep()
#include <stdio.h>
#include <stdlib.h> // for flush(), system(), for srand()
#include <time.h>   // for rand()

/*
Name: Jack Clavano (Angelica Therese I Clavano)
Class: CCPROG1 S18B
Date: 2022-12-13
Machine Project 1: Gilgamesh's Mega Gil Adventures
File name: newmain.c
Demo: 2022-12-15 @ 11:15am

51/100
82 first ho1

ccprog2 - read up on arrays and structures

Current Problems:
1. game does not end at 30 days [x]
2. game does not end when player chooses to exit [x]
3. when choosing item in shop, it repeats 2 times before acknowleddging choice [x]
4. buyorsell function does not work [x]
5. when item is sold out, makes all items sold out [x]
6. fix loop for returning back to shop after buying/selling []
6.1 when returning to shop, keep old values of items including sold out status []
7. Order of which items are sold out per day is the same []
    info: when you choose tycoon at the start, elixir is the first item to be sold out, etc.
8. When you don't have enough gil, it either returns to the main menu or repeats the buysell function []
9. shopmerchant() choices don't work []

TEST CASES
> buying when you don't have enough gil 
1 - brings you back to shop
2 - brings you back to shop
3 - brings you back to shop 
4 - 
5 - 
6 - 
7 - 
8 - 
9 - 
>9 -

> buying when you have enough gil
1 - 
2 - 
3 - 
4 -
5 - 
6 - 
7 - 
8 - 
9 - 
>9 - 


> selling item when item is unavailable
1 - brings you back to shop 
2 - brings you back to shop
3 - brings you back to main menu
4 - brings you back to main menu
5 - 
6 - 
7 - 
8 - 
9 - 
>9 - 



Personal Notes:
1. You cannot change the value of a switch statement through a case statement
2. You can pass functions as parameters

*/

/* This function is called every time a new day starts */
void newday(int *day, int *debt)
{
    *day = *day + 1;          // increment day every time you leave a shop
    *debt = *debt * 1.15 + 1; // increase debt by 15% every day
    /* 15% more than 50000 is 57500 */
}

/* This function is used only if the player doesn't choose to start a new game. Meant to display debt as 50000 */
void debtincrease(int *debt)
{
    *debt = *debt * 1.15 + 1;
}

/* This function is called at the start when the loading screen is done. If you choose to exit the game, it shows the gameover screen and exits the game */
void titlescreen(char *titlechoiceptr)
{
    printf("WELCOME TO GILGAMESH'S MEGA GIL ADVENTURES!\n");
    printf("\n");
    printf("start a new game [y] or exit [n]\n");
    scanf("%c", titlechoiceptr);
}

/* Checks if item is available */
int isavail()
{
    // srand(time(NULL)); // seed the random number generator

    int item_sold = 0; // 0 = not sold, 1 = sold

    // generate a random number between 0 and 100 (inclusive)
    int rand_num = rand() % 101;

    if (rand_num <= 30)
    {
        item_sold = 1;
    }

    return item_sold;
}

/* Fake loading screen */
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

/* This function is called when you choose to go to a shop in mainmenu() */
int shopdisplay(int *onhandPDptr, int *onhandEEptr, int *onhandPIptr, int *onhandGMptr, int *onhandSCptr, int *onhandADptr, int *onhandDMptr, int *onhandTRptr, int gilPD, int gilEE, int gilPI, int gilGM, int gilSC, int gilAD, int gilDM, int gilTR) // to go back to
{
    int nchoice;
    int isitemavail = isavail();
    int isitemavail2 = isavail();
    int isitemavail3 = isavail();
    int isitemavail4 = isavail();
    int isitemavail5 = isavail();
    int isitemavail6 = isavail();
    int isitemavail7 = isavail();
    int isitemavail8 = isavail();

    int pricePD = gilPD * isitemavail;
    int priceEE = gilEE * isitemavail2;
    int pricePI = gilPI * isitemavail3;
    int priceGM = gilGM * isitemavail4;
    int priceSC = gilSC * isitemavail5;
    int priceAD = gilAD * isitemavail6;
    int priceDM = gilDM * isitemavail7;
    int priceTR = gilTR * isitemavail8;

    do
    {
        printf("************************************************************\n");
        printf("If item price = 0, item is unavailable\n");
        printf("Item                   On Hand        Price\n");
        printf("[1] Phoenix Down          %d           %d   \n", *onhandPDptr, pricePD);
        printf("[2] Elixir Essence        %d           %d   \n", *onhandEEptr, priceEE);
        printf("[3] Platinum Ingot        %d           %d   \n", *onhandPIptr, pricePI);
        printf("[4] Golden Materia        %d           %d   \n", *onhandGMptr, priceGM);
        printf("[5] Scarletite            %d           %d   \n", *onhandSCptr, priceSC);
        printf("[6] Adamantite            %d           %d   \n", *onhandADptr, priceAD);
        printf("[7] Darkmatter            %d           %d   \n", *onhandDMptr, priceDM);
        printf("[8] Trapezohedron         %d           %d   \n", *onhandTRptr, priceTR);
        printf("[9] Leave (Costs 1 Day)\n");
        printf("************************************************************\n");
        printf("\n");
        printf("Your Choice: ");
        scanf("%d", &nchoice);
        fflush(stdin);

        if (nchoice == 1 && pricePD == 0) // GROUP THIS ENTIRE THING
        {
            printf("Item is unavailable!");
        }
        else if (nchoice == 1 && pricePD > 0)
        {
            return nchoice; // dont put return 
        }
        else if (nchoice == 2 && priceEE == 0)
        {
            printf("Item is unavailable!");
        }
        else if (nchoice == 2 && priceEE > 0)
        {
            return nchoice;
        }
        else if (nchoice == 3 && pricePI == 0)
        {
            printf("Item is unavailable!");
        }
        else if (nchoice == 3 && pricePI > 0)
        {
            return nchoice;
        }
        else if (nchoice == 4 && priceGM == 0)
        {
            printf("Item is unavailable!");
        }
        else if (nchoice == 4 && priceGM > 0)
        {
            return nchoice;
        }
        else if (nchoice == 5 && priceSC == 0)
        {
            printf("Item is unavailable!");
        }
        else if (nchoice == 5 && priceSC > 0)
        {
            return nchoice;
        }
        else if (nchoice == 6 && priceAD == 0)
        {
            printf("Item is unavailable!");
        }
        else if (nchoice == 6 && priceAD > 0)
        {
            return nchoice;
        }
        else if (nchoice == 7 && priceDM == 0)
        {
            printf("Item is unavailable!");
        }
        else if (nchoice == 7 && priceDM > 0)
        {
            return nchoice;
        }
        else if (nchoice == 8 && priceTR == 0)
        {
            printf("Item is unavailable!");
        }
        else if (nchoice == 8 && priceTR > 0)
        {
            return nchoice;
        }
        else if (nchoice == 9)
        {
            return nchoice;
        }
        else
        {
            printf("Invalid choice!");
        }
    } while (nchoice != 9);
}

/* This function displays the buy or sell mechanism when the item is available */
int shopbuyorsell(int *onhandITEM, int priceITEM, int *gilptr) // works
{
    int buyorsell;
    int quantity = 0;
    int sold;
    system("cls");
    printf("Do you want to buy or sell the item?\n");
    printf("On hand [%d]\n", *onhandITEM);
    printf("Price [%d]\n", priceITEM);
    printf("Gil [%d]\n", *gilptr);
    printf("\n");
    printf("[1] Buy\n");
    printf("[2] Sell\n");
    scanf("%d", &buyorsell);

    switch (buyorsell)
    {
    case 1:
    {
        printf("You chose to buy\n");
        printf("How many do you want to buy?\n");
        scanf("%d", &quantity);
        fflush(stdin);

        if (quantity * priceITEM > *gilptr)
        {
            printf("You don't have enough gil! Returning back to shop.\n");
            sleep(1);
            sold = 0;
            return sold;
        }
        else
        {
            *onhandITEM = *onhandITEM + quantity;
            *gilptr = *gilptr - (priceITEM * quantity);
            printf("You bought %d items for %d. Returning back to shop.\n", quantity, priceITEM * quantity);
            sold = 1;
            sleep(1);
            return sold;
        }
    }
    case 2:
    {
        {
            printf("You chose to sell\n");
            printf("How many do you want to sell?\n");
            scanf("%d", &quantity);
            fflush(stdin);

            if (quantity > *onhandITEM)
            {
                printf("You don't have enough items! Returning back to shop.\n");
                sleep(1);
                sold = 0;
                return sold;
            }
            else
            {
                *onhandITEM = *onhandITEM - quantity;
                *gilptr = *gilptr + (priceITEM * quantity);
                printf("You sold %d items for %d. Returning back to shop.\n", quantity, priceITEM * quantity);
                sleep(1);
                sold = 1;
                return sold;
            }
        }
    }
    }
}

/* This function stores and displays the randomly generated prices for Tycoon Meteor's Materials */
int shoptycoon(int *onhandPDptr, int *onhandEEptr, int *onhandPIptr, int *onhandGMptr, int *onhandSCptr, int *onhandADptr, int *onhandDMptr, int *onhandTRptr, int *gilptr)
{
    int shopchoice;
    int gilPD = 500 + (rand() % (500 - 1200));
    int gilEE = 1500 + (rand() % (1500 - 2100));
    int gilPI = 5000 + (rand() % (5000 - 7000));
    int gilGM = 3500 + (rand() % (3500 - 5500));
    int gilSC = 8000 + (rand() % (8000 - 12000));
    int gilAD = 15000 + (rand() % (15000 - 30000));
    int gilDM = 40000 + (rand() % (40000 - 70000));

    int gilTR = 35000 + (rand() % (35000 - 65000));
    // Trapezohedron 35000-65000
    printf("************************************************************\n");
    printf("WELCOME TO TYCOON METEOR'S MATERIALS!\n");
    shopchoice = shopdisplay(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilPD, gilEE, gilPI, gilGM, gilSC, gilAD, gilDM, gilTR);
    fflush(stdin);

    switch (shopchoice)
    {
    case 1: // Pheonix Down
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPDptr, gilPD, gilptr);
    case 2: // Elixir Essence
        system("cls");
        printf("\n");
        shopbuyorsell(onhandEEptr, gilEE, gilptr);
        break;
    case 3: // Platinum Ingot
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPIptr, gilPI, gilptr);
        break;
    case 4: // Golden Materia
        system("cls");
        printf("\n");
        shopbuyorsell(onhandGMptr, gilGM, gilptr);
        break;
    case 5: // Scarletite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandSCptr, gilSC, gilptr);
        break;
    case 6: // Adamantite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandADptr, gilAD, gilptr);
        break;
    case 7: // Darkmatter
        system("cls");
        printf("\n");
        shopbuyorsell(onhandDMptr, gilDM, gilptr);
        break;
    case 8: // Trapezohedron
        system("cls");
        printf("\n");
        shopbuyorsell(onhandTRptr, gilTR, gilptr);
        break;
    case 9:
        system("cls");
        printf("\n");
        printf("You have left the shop.\n");
        sleep(1);
        system("cls");
        return 0;
    }
}

/* This function stores and displays the randomly generated prices for Pulsian Restoratives */
int shoppulsian(int *onhandPDptr, int *onhandEEptr, int *onhandPIptr, int *onhandGMptr, int *onhandSCptr, int *onhandADptr, int *onhandDMptr, int *onhandTRptr, int *gilptr)
{
    int shopchoice;
    int gilPD = 500 + (rand() % (500 - 1200));
    // Pheonix Down 300-800
    int gilEE = 1000 + (rand() % (1000 - 1700));
    // Elixir Essence 1000-1700

    int gilPI = 5000 + (rand() % (5000 - 7000));
    int gilGM = 3500 + (rand() % (3500 - 5500));
    int gilSC = 8000 + (rand() % (8000 - 12000));
    int gilAD = 15000 + (rand() % (15000 - 30000));
    int gilDM = 40000 + (rand() % (40000 - 70000));
    int gilTR = 60000 + (rand() % (60000 - 90000));

    printf("************************************************************\n");
    printf("WELCOME TO PULSIAN RESTORATIVES!\n");
    shopchoice = shopdisplay(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilPD, gilEE, gilPI, gilGM, gilSC, gilAD, gilDM, gilTR);
    fflush(stdin);

    switch (shopchoice)
    {
    case 1: // Pheonix Down
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPDptr, gilPD, gilptr);
        break;
    case 2: // Elixir Essence
        system("cls");
        printf("\n");
        shopbuyorsell(onhandEEptr, gilEE, gilptr);
        break;
    case 3: // Platinum Ingot
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPIptr, gilPI, gilptr);
        break;
    case 4: // Golden Materia
        system("cls");
        printf("\n");
        shopbuyorsell(onhandGMptr, gilGM, gilptr);
        break;
    case 5: // Scarletite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandSCptr, gilSC, gilptr);
        break;
    case 6: // Adamantite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandADptr, gilAD, gilptr);
        break;
    case 7: // Darkmatter
        system("cls");
        printf("\n");
        shopbuyorsell(onhandDMptr, gilDM, gilptr);
        break;
    case 8: // Trapezohedron
        system("cls");
        printf("\n");
        shopbuyorsell(onhandTRptr, gilTR, gilptr);
        break;
    case 9:
        system("cls");
        printf("\n");
        printf("You have left the shop.\n");
        sleep(1);
        system("cls");
        return 0;
    }
}

/* This function stores and displays the randomly generated prices for Archadian Luxuries */
int shoparchadian(int *onhandPDptr, int *onhandEEptr, int *onhandPIptr, int *onhandGMptr, int *onhandSCptr, int *onhandADptr, int *onhandDMptr, int *onhandTRptr, int *gilptr)
{
    int shopchoice;
    int gilPD = 500 + (rand() % (500 - 1200));
    int gilEE = 1500 + (rand() % (1500 - 2100));

    int gilPI = 4500 + (rand() % (4500 - 6000));
    // Platinum Ingot 4500-6000

    int gilGM = 3500 + (rand() % (3500 - 5500));
    int gilSC = 8000 + (rand() % (8000 - 12000));
    int gilAD = 15000 + (rand() % (15000 - 30000));
    int gilDM = 40000 + (rand() % (40000 - 70000));
    int gilTR = 60000 + (rand() % (60000 - 90000));
    printf("************************************************************\n");
    printf("WELCOME TO ARCHADIAN LUXURIES!\n");
    shopchoice = shopdisplay(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilPD, gilEE, gilPI, gilGM, gilSC, gilAD, gilDM, gilTR);
    fflush(stdin);

    switch (shopchoice)
    {
    case 1: // Pheonix Down
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPDptr, gilPD, gilptr);
        break;
    case 2: // Elixir Essence
        system("cls");
        printf("\n");
        shopbuyorsell(onhandEEptr, gilEE, gilptr);
        break;
    case 3: // Platinum Ingot
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPIptr, gilPI, gilptr);
        break;
    case 4: // Golden Materia
        system("cls");
        printf("\n");
        shopbuyorsell(onhandGMptr, gilGM, gilptr);
        break;
    case 5: // Scarletite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandSCptr, gilSC, gilptr);
        break;
    case 6: // Adamantite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandADptr, gilAD, gilptr);
        break;
    case 7: // Darkmatter
        system("cls");
        printf("\n");
        shopbuyorsell(onhandDMptr, gilDM, gilptr);
        break;
    case 8: // Trapezohedron
        system("cls");
        printf("\n");
        shopbuyorsell(onhandTRptr, gilTR, gilptr);
        break;
    case 9:
        system("cls");
        printf("\n");
        printf("You have left the shop.\n");
        sleep(1);
        system("cls");
        return 0;
    }
}

/* This function stores and displays the randomly generated prices for Cid's Magical Escapades */
int shopcid(int *onhandPDptr, int *onhandEEptr, int *onhandPIptr, int *onhandGMptr, int *onhandSCptr, int *onhandADptr, int *onhandDMptr, int *onhandTRptr, int *gilptr)
{
    int shopchoice;

    int gilPD = 500 + (rand() % (500 - 1200));
    int gilEE = 1500 + (rand() % (1500 - 2100));
    int gilPI = 5000 + (rand() % (5000 - 7000));

    int gilGM = 3000 + (rand() % (3000 - 5000));
    // Golden Materia 3000-5000

    int gilSC = 8000 + (rand() % (8000 - 12000));
    int gilAD = 15000 + (rand() % (15000 - 30000));
    int gilDM = 40000 + (rand() % (40000 - 70000));
    int gilTR = 60000 + (rand() % (60000 - 90000));
    printf("************************************************************\n");
    printf("WELCOME TO CID'S MAGICAL ESCAPADES!\n");
    shopchoice = shopdisplay(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilPD, gilEE, gilPI, gilGM, gilSC, gilAD, gilDM, gilTR);
    fflush(stdin);

    switch (shopchoice)
    {
    case 1: // Pheonix Down
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPDptr, gilPD, gilptr);
        break;
    case 2: // Elixir Essence
        system("cls");
        printf("\n");
        shopbuyorsell(onhandEEptr, gilEE, gilptr);
        break;
    case 3: // Platinum Ingot
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPIptr, gilPI, gilptr);
        break;
    case 4: // Golden Materia
        system("cls");
        printf("\n");
        shopbuyorsell(onhandGMptr, gilGM, gilptr);
        break;
    case 5: // Scarletite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandSCptr, gilSC, gilptr);
        break;
    case 6: // Adamantite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandADptr, gilAD, gilptr);
        break;
    case 7: // Darkmatter
        system("cls");
        printf("\n");
        shopbuyorsell(onhandDMptr, gilDM, gilptr);
        break;
    case 8: // Trapezohedron
        system("cls");
        printf("\n");
        shopbuyorsell(onhandTRptr, gilTR, gilptr);
        break;
    case 9:
        system("cls");
        printf("\n");
        printf("You have left the shop.\n");
        sleep(1);
        system("cls");
        return 0;
    }
}

/* This function stores and displays the randomly generated prices for Gaian Gratitudes */
int shopgaian(int *onhandPDptr, int *onhandEEptr, int *onhandPIptr, int *onhandGMptr, int *onhandSCptr, int *onhandADptr, int *onhandDMptr, int *onhandTRptr, int *gilptr)
{
    int shopchoice;

    int gilPD = 500 + (rand() % (500 - 1200));
    int gilEE = 1500 + (rand() % (1500 - 2100));
    int gilPI = 5000 + (rand() % (5000 - 7000));
    int gilGM = 3500 + (rand() % (3500 - 5500));

    int gilSC = 5000 + (rand() % (5000 - 10000));
    // Scarletite 5000 - 10000

    int gilAD = 15000 + (rand() % (15000 - 30000));
    int gilDM = 40000 + (rand() % (40000 - 70000));
    int gilTR = 60000 + (rand() % (60000 - 90000));
    printf("************************************************************\n");
    printf("WELCOME TO GAIAN GRATITUDES!\n");
    shopchoice = shopdisplay(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilPD, gilEE, gilPI, gilGM, gilSC, gilAD, gilDM, gilTR);
    fflush(stdin);

    switch (shopchoice)
    {
    case 1: // Pheonix Down
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPDptr, gilPD, gilptr);
        break;
    case 2: // Elixir Essence
        system("cls");
        printf("\n");
        shopbuyorsell(onhandEEptr, gilEE, gilptr);
        break;
    case 3: // Platinum Ingot
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPIptr, gilPI, gilptr);
        break;
    case 4: // Golden Materia
        system("cls");
        printf("\n");
        shopbuyorsell(onhandGMptr, gilGM, gilptr);
        break;
    case 5: // Scarletite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandSCptr, gilSC, gilptr);
        break;
    case 6: // Adamantite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandADptr, gilAD, gilptr);
        break;
    case 7: // Darkmatter
        system("cls");
        printf("\n");
        shopbuyorsell(onhandDMptr, gilDM, gilptr);
        break;
    case 8: // Trapezohedron
        system("cls");
        printf("\n");
        shopbuyorsell(onhandTRptr, gilTR, gilptr);
        break;
    case 9:
        system("cls");
        printf("\n");
        printf("You have left the shop.\n");
        sleep(1);
        system("cls");
        return 0;
    }
}

/* This function stores and displays the randomly generated prices for Riches and Minerals of Spira */
int shopriches(int *onhandPDptr, int *onhandEEptr, int *onhandPIptr, int *onhandGMptr, int *onhandSCptr, int *onhandADptr, int *onhandDMptr, int *onhandTRptr, int *gilptr)
{
    int shopchoice;

    int gilPD = 500 + (rand() % (500 - 1200));
    int gilEE = 1500 + (rand() % (1500 - 2100));
    int gilPI = 5000 + (rand() % (5000 - 7000));
    int gilGM = 3500 + (rand() % (3500 - 5500));
    int gilSC = 8000 + (rand() % (8000 - 12000));

    int gilAD = 9500 + (rand() % (9500 - 20000));
    // Adamantite 9500-20000
    int gilDM = 22000 + (rand() % (22000 - 50000));
    // Dark Matter 22000- 50000

    int gilTR = 60000 + (rand() % (60000 - 90000));
    printf("************************************************************\n");
    printf("WELCOME TO  RICHES AND MINERALS OF SPIRA!\n");
    shopchoice = shopdisplay(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilPD, gilEE, gilPI, gilGM, gilSC, gilAD, gilDM, gilTR);
    fflush(stdin);

    switch (shopchoice)
    {
    case 1: // Pheonix Down
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPDptr, gilPD, gilptr);
        break;
    case 2: // Elixir Essence
        system("cls");
        printf("\n");
        shopbuyorsell(onhandEEptr, gilEE, gilptr);
        break;
    case 3: // Platinum Ingot
        system("cls");
        printf("\n");
        shopbuyorsell(onhandPIptr, gilPI, gilptr);
        break;
    case 4: // Golden Materia
        system("cls");
        printf("\n");
        shopbuyorsell(onhandGMptr, gilGM, gilptr);
        break;
    case 5: // Scarletite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandSCptr, gilSC, gilptr);
        break;
    case 6: // Adamantite
        system("cls");
        printf("\n");
        shopbuyorsell(onhandADptr, gilAD, gilptr);
        break;
    case 7: // Darkmatter
        system("cls");
        printf("\n");
        shopbuyorsell(onhandDMptr, gilDM, gilptr);
        break;
    case 8: // Trapezohedron
        system("cls");
        printf("\n");
        shopbuyorsell(onhandTRptr, gilTR, gilptr);
        break;
    case 9:
        system("cls");
        printf("\n");
        printf("You have left the shop.\n");
        sleep(1);
        system("cls");
        return 0;
    }
}

/* This function is called when the deposit gil choice is chosen */
int depositgil(int *gilptr, int *gilbankptr)
{
    int depositgil;
    printf("You chose to deposit gil.\n");
    sleep(1);
    system("cls");
    printf("How much gil would you like to deposit?\n");
    printf("\n");
    printf("Your Choice: ");
    fflush(stdin);
    scanf("%d", &depositgil);

    if (depositgil > *gilptr)
    {
        printf("You do not have enough gil to deposit.\n");
        sleep(1);
        system("cls");
        return 0;
    }
    else
    {
        *gilptr -= depositgil;
        *gilbankptr += depositgil;
        printf("You have deposited %d gil.\n", depositgil);
        sleep(1);
        system("cls");
        return 0;
    }
}

/* This function is called when the withdraw gil choice is chosen */
int withdrawgil(int *gilptr, int *gilbankptr)
{
    int withdrawgil;
    printf("You chose to withdraw gil.\n");
    sleep(1);
    system("cls");
    printf("How much gil would you like to withdraw?\n");
    printf("\n");
    printf("Your Choice: ");
    fflush(stdin);
    scanf("%d", &withdrawgil);

    if (withdrawgil > *gilbankptr)
    {
        printf("You do not have enough gil to withdraw.\n");
        sleep(1);
        system("cls");
        return 0;
    }
    else
    {
        *gilptr += withdrawgil;
        *gilbankptr -= withdrawgil;
        printf("You have withdrawn %d gil.\n", withdrawgil);
        sleep(1);
        system("cls");
        return 0;
    }
}

/* This function is called when the payoff debt choice is chosen */
int payoffdebt(int *debtptr, int *gilptr, int *gilbankptr)
{
    int payoffdebt;
    int bankorwallet;
    printf("You chose to pay off your debt.\n");
    sleep(1);
    system("cls");
    printf("How much gil would you like to pay off?\n");
    printf("You have %d gil in your wallet and %d gil in your bank.\n", *gilptr, *gilbankptr);
    printf("\n");
    printf("Your Choice: ");
    fflush(stdin);
    scanf("%d", &payoffdebt);

    printf("Do you want to use the gil in your wallet or your bank?\n");
    printf("[1] Wallet\n");
    printf("[2] Bank\n");
    printf("\n");
    printf("Your Choice: ");
    fflush(stdin);
    scanf("%d", &bankorwallet);

    switch (bankorwallet)
    {
    case 1:
        if (payoffdebt > *gilptr)
        {
            printf("You do not have enough gil to pay off your debt.\n");
            sleep(1);
            system("cls");
            return 0;
        }
        else
        {
            *gilptr -= payoffdebt;
            *debtptr -= payoffdebt;
            printf("You have paid off %d gil of your debt.\n", payoffdebt);
            sleep(1);
            system("cls");
            return 0;
        }
    case 2:
        if (payoffdebt > *gilbankptr)
        {
            printf("You do not have enough gil to pay off your debt.\n");
            sleep(1);
            system("cls");
            return 0;
        }
        else
        {
            *gilbankptr -= payoffdebt;
            *debtptr -= payoffdebt;
            printf("You have paid off %d gil of your debt.\n", payoffdebt);
            sleep(1);
            system("cls");
            return 0;
        }
    }
}

/* This function is called when the ask for loan choice is chosen */
int askforloan(int *gilptr, int *debtptr)
{
    int askforloan;
    printf("You chose to ask for a loan.\n");
    sleep(1);
    system("cls");
    printf("How much gil would you like to ask for?\n");
    printf("\n");
    printf("Your Choice: ");
    fflush(stdin);
    scanf("%d", &askforloan);

    *gilptr -= askforloan;
    *debtptr += askforloan;
    printf("You have asked for %d gil making your debt worth %d gil.\n", askforloan, *debtptr);
    sleep(1);
    system("cls");
    return 0;
}

/* This function is called when you choose to go to the merchant. Also acts as an ATM machine */
int shopmerchant(int *dayptr, int *gilptr, int *debtptr, int *earnedgilptr, int *gilbankptr)
{
    int merchantchoice;
    printf("You chose to go to the Merchant of the Rift\n");
    sleep(1);
    system("cls");
    printf("Merchant of the Rift: Are you ready to pay your debt?\n");
    printf("\n");
    printf("[1] Deposit Gil\t\t\t\tDay: #%d\n", *dayptr);
    printf("[2] Withdraw Gil\t\t\tGil: %d\n", *gilptr);
    printf("[3] Pay off Debt\t\t\tDebt: %d\n", *debtptr);
    printf("[4] Ask for Additional Loan\n");
    printf("[5] Leave (Costs 1 day)\n");
    printf("\n");
    printf("Your Choice: ");
    fflush(stdin);
    scanf("%d", merchantchoice);

    switch (merchantchoice)
    {
    case 1:
    {
        Printf("You chose to deposit gil.");
        depositgil(gilptr, gilbankptr);
    }
    case 2:
    {
        Printf("You chose to withdraw gil.");
        withdrawgil(gilptr, gilbankptr);
    }
    case 3:
    {
        Printf("You chose to pay off debt.");
        payoffdebt(debtptr, gilptr, gilbankptr);
    }
    case 4:
    {
        Printf("You chose to ask for a loan.");
        askforloan(gilptr, debtptr);
    }
    case 5:
    {
        system("cls");
        printf("\n");
        printf("You have left the Merchant of the Rift.\n");
        sleep(1);
        system("cls");
        return 0;
    }
    }
}


/* This function is called when you end up with 0 debt */
void winscreen(int *debtptr, int *gilptr, int *earnedgilptr, int *dayptr)
{
    printf("CONGRATULATIONS! YOU HAVE PAID YOUR DEBT WITHIN 30 DAYS!");
    printf("Remaining Debt		[%d]\n", *debtptr);
    printf("Remaining Gil		[%d]\n", *gilptr);
    printf("Total Profit		[%d]\n", *earnedgilptr);
    printf("Total Days	    	[%d]\n", *dayptr);
    printf("\n");
    printf("Gilgamesh: I am now free of debt unlike you!\n");
}

/* This function is called when you exit the game without repaying debt or go through all 30 days and still have more than 0 debt */
void losescreen(int *debtptr, int *gilptr, int *earnedgilptr, int *dayptr)
{
    printf("GAME OVER!\n");
    printf("YOU LOST THE GAME AND HAVE FAILED TO PAY YOUR DEBT!\n");
    printf("Remaining Debt		[%d]\n", *debtptr);
    printf("Remaining Gil		[%d]\n", *gilptr);
    printf("Total Profit		[%d]\n", *earnedgilptr);
    printf("Total Days	    	[%d]\n", *dayptr);
    printf("\n");
    printf("Gilgamesh: I am still in heavy debt much like the masses!\n");
}

/* This function displays the main menu when you start a new game and will be looped until you choose to exit. Includes choices to go to the shops */
int mainmenu(int *dayptr, int *debtptr, int *gilptr, char *titlechoiceptr, int *menuchoiceptr, int *earnedgilptr, int *gilbankptr)
{
    /******INVENTORY START******/
    int onhandPD, onhandEE, onhandPI, onhandGM, onhandSC, onhandAD, onhandDM, onhandTR;
    onhandPD = 0; // Phoenix Down
    int *onhandPDptr;
    onhandPDptr = &onhandPD;
    onhandEE = 0; // Elixir Essence
    int *onhandEEptr;
    onhandEEptr = &onhandEE;
    onhandPI = 0; // Platinum Ingot
    int *onhandPIptr;
    onhandPIptr = &onhandPI;
    onhandGM = 0; // Golden Materia
    int *onhandGMptr;
    onhandGMptr = &onhandGM;
    onhandSC = 0; // Scarletite
    int *onhandSCptr;
    onhandSCptr = &onhandSC;
    onhandAD = 0; // Adamantite
    int *onhandADptr;
    onhandADptr = &onhandAD;
    onhandDM = 0; // Dark Matter
    int *onhandDMptr;
    onhandDMptr = &onhandDM;
    onhandTR = 0; // Trapezohedron
    int *onhandTRptr;
    onhandTRptr = &onhandTR;
    /******INVENTORY END******/

    do
    {
        system("cls");
        newday(dayptr, debtptr);
        printf("Gilgamesh: Where should my travels take me to?\n\n");
        printf("[1] Tycoon Meteor's Minerals\t\t\tDay: #%d\n", *dayptr);
        printf("[2] Pulsian Restoratives\t\t\tGil: %d\n", *gilptr);
        printf("[3] Archadian Luxuries\t\t\t\tDebt: %d\n", *debtptr);
        printf("[4] Cid's Magical Escapades\n");
        printf("[5] Gaian Gratitudes\t\t\t\t[8] Quit Game\n");
        printf("[6] Riches and Minerals of Spira\n");
        printf("[7] Go see the Merchant of the Rift\n");
        printf("\n");
        printf("Your Choice: ");
        fflush(stdin);
        scanf("%d", menuchoiceptr);

        switch (*menuchoiceptr)
        {
        case 1:
        {
            printf("You have chosen to visit Tycoon Meteor's Minerals.\n");
            sleep(1);
            system("cls");
            do
            {
                shoptycoon(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilptr);
            } while (shoptycoon(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilptr) == 1);
            break;
        }
        case 2:
        {
            printf("You have chosen to visit Pulsian Restoratives.\n");
            sleep(1);
            system("cls");
            shoppulsian(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilptr);
            break;
        }
        case 3:
        {
            printf("You have chosen to visit Archadian Luxuries.\n");
            sleep(1);
            system("cls");
            shoparchadian(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilptr);
            break;
        }
        case 4:
        {
            printf("You have chosen to visit Cid's Magical Escapades.\n");
            sleep(1);
            system("cls");
            shopcid(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilptr);
            break;
        }
        case 5:
        {
            printf("You have chosen to visit Gaian Gratitudes.\n");
            sleep(1);
            system("cls");
            shopgaian(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilptr);
            break;
        }
        case 6:
        {
            printf("You have chosen to visit Riches and Minerals of Spira.\n");
            sleep(1);
            system("cls");
            shopriches(onhandPDptr, onhandEEptr, onhandPIptr, onhandGMptr, onhandSCptr, onhandADptr, onhandDMptr, onhandTRptr, gilptr);
            break;
        }
        case 7:
        {
            printf("You have chosen to visit the Merchant of the Rift.\n");
            sleep(1);
            system("cls");
            shopmerchant(dayptr, gilptr, debtptr, earnedgilptr, gilbankptr);
            break;
        }
        case 8:
        {
            printf("You have chosen to quit the game.\n");
            // printf("menuchoiceptr = %d", *menuchoiceptr);
            sleep(1);
            system("cls");
            break;
        }
        }

    } while (*menuchoiceptr != 8 && *dayptr <= 29);
}

/* Driver Code. Personal Nest limit = 3 */
int main()
{
    /****************/
    int day = 0; // is updated by newday()
    int *dayptr;
    dayptr = &day;
    int debt = 43478; // is updated by newday()
    int *debtptr;
    debtptr = &debt;
    int gil = 20000; // is updated by shop functions and atm functions
    int *gilptr;
    gilptr = &gil;
    int earnedgil = 0; // is updated by shop functions and atm functions and displayed in winscreen() or losescreen()
    int *earnedgilptr;
    earnedgilptr = &earnedgil;
    int gilbank;
    int *gilbankptr;
    gilbankptr = &gilbank;
    char titlechoice;
    char *titlechoiceptr;
    titlechoiceptr = &titlechoice; // for switch statement following titlescreen();
    int menuchoice;
    int *menuchoiceptr;
    menuchoiceptr = &menuchoice;
    /****************/

    loadingscreen();
    system("cls");
    titlescreen(titlechoiceptr);
    fflush(stdin);

    switch (titlechoice)
    {
    case 'y':
    case 'Y':
    {
        system("cls");
        mainmenu(dayptr, debtptr, gilptr, titlechoiceptr, menuchoiceptr, earnedgilptr, gilbankptr);
        break;
    }
    case 'n':
    case 'N':
    {
        printf("You have chosen to quit the game.\n");
        break;
    }
    }

    if (debt > 0 && day > 0)
    {
        losescreen(debtptr, gilptr, earnedgilptr, dayptr);
    }
    else if (debt > 0 && day == 0)
    {
        debtincrease(debtptr);
        losescreen(debtptr, gilptr, earnedgilptr, dayptr);
    }
    else
    {
        winscreen(debtptr, gilptr, earnedgilptr, dayptr);
    }

    return 0;
}