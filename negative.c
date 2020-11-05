// negative
//25/02/2020
// Calvin z5242094

#include<stdio.h>

int main(void) {
    
    int number;
    scanf("%d", &number);
    if (number > 0) {
        printf("You have entered a positive number.\n");
    } else if (number < 0) {
        printf("Don't be so negative!\n");
    } else {
        printf("You have entered zero.\n");
    }
    return 0;
}
