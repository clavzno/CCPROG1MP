//2024
#include <stdio.h>

int game(int day, int gil, int debt){
    return 0;
}

int main() {
    int day = 0;
    int gil = 20000;
    int debt = 50000;
    char gameOngoing;

    printf("WELCOME TO\nGILGAMESH'S MEGA GIL ADVENTURES!");
    printf(" Would you like to start a new game? (y/n): ");
    scanf("%c", &gameOngoing);

    while(day < 30 || gameOngoing != 'n') {
        game(day, gil, debt);
    }

    return 0;
}