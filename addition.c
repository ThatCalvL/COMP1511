//Calvin z5242094
//25/02/2020
//addition.c

#include<stdio.h>
int main(void) {
    int number1 = -1, number2 = -1;
    
    printf("Please enter two integers: ");
    scanf("%d %d", &number1, &number2);
    int total = number1 + number2;
    printf("%d + %d = %d\n", number1, number2, total);


    return 0;
}
