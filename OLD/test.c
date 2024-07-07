#include <stdio.h>
#include <unistd.h>

/* This function displays the buy or sell mechanism when the item is available */
int shopbuyorsell(int *onhandITEM, int priceITEM, int *gilptr) //works
{
    printf("You are in the buy or sell function\n");
    int buyorsell;
    int quantity = 0;
    system("cls");
    printf("Do you want to buy or sell the item?\n");
    printf("On hand [%d]\n", *onhandITEM);
    printf("Price [%d]\n", priceITEM);
    printf("Gil [%d]\n", *gilptr);
    printf("\n");
    printf("[1] Buy\n");
    printf("[2] Sell\n");
    scanf("%d", &buyorsell);

    do
    {
        if (buyorsell == 1)
        {
            printf("You chose to buy\n");
            printf("How many do you want to buy?\n");
            scanf("%d", &quantity);
            fflush(stdin);
            printf("You chose to buy %d items", quantity);

            if (quantity * priceITEM > *gilptr)
            {
                printf("You don't have enough gil!\n");
                break;
            }
            else
            {
                *onhandITEM = *onhandITEM + quantity;
                *gilptr = *gilptr - (priceITEM * quantity);
                printf("You bought %d items for %d\n", quantity, priceITEM * quantity);
                break;
            }
        }
        else if (buyorsell == 2)
        {
            printf("You chose to sell\n");
            printf("How many do you want to sell?\n");
            scanf("%d", &quantity);
            fflush(stdin);
            printf("You chose to sell %d items", quantity);

            if (quantity > *onhandITEM)
            {
                printf("You don't have enough items!\n");
                break;
            }
            else
            {
                *onhandITEM = *onhandITEM - quantity;
                *gilptr = *gilptr + (priceITEM * quantity);
                printf("You sold %d items for %d\n", quantity, priceITEM * quantity);
                break;
            }
        }
        else
        {
            printf("Invalid choice!\n");
        }
    } while (buyorsell != 1 || buyorsell != 2);
}

int main()
{

    int onhandITEM = 0;
    int *onhandITEMptr;
    onhandITEMptr = &onhandITEM;
    int priceITEM = 541;
    int gil = 20000;
    int *gilptr;
    gilptr = &gil;
    int buyorsell;

    buyorsell = shopbuyorsell(onhandITEMptr, priceITEM, gilptr);
}


        if (nchoice == 1 && pricePD == 0) //GROUP THIS ENTIRE THING
        {
            printf("Item is unavailable!");
        }
        else if (nchoice == 1 && pricePD > 0)
        {
            return nchoice;
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