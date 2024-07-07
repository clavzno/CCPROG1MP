#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_random_number(void) {
    // seed the random number generator
    // generate a random number between 0 and 10 (inclusive)
    int rand_num = rand() % 11;
    return rand_num;
}

int main(void) {
    int num1 = generate_random_number();
    int num2 = generate_random_number();
    int num3 = generate_random_number();

    printf("num1 = %d, num2 = %d, num3 = %d\n", num1, num2, num3);

    return 0;
}
