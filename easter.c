#include <stdio.h>
int main(void) {
    int year = 0;
    printf("Enter year: ");
    scanf("%d", &year);
    int a = year % 19;
    int b = year / 100;
    int c = year % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a + 11 * h + 22 * l) / 451;
    int EasterMonth = (h + l - 7 * m + 114) / 31;  //[3=March, 4=April]
    int p = (h + l - 7 * m + 114) % 31;
    int EasterDate = p + 1;     //(date in Easter Month)

    if (EasterMonth == 1) {
        printf("Easter is January %d in %d. \n", EasterDate, year);
    } else if (EasterMonth == 2) {
        printf("Easter is Feburary %d in %d. \n", EasterDate, year);
    }else if (EasterMonth ==3)  {
        printf("Easter is March %d in %d. \n", EasterDate, year);
    }else if (EasterMonth == 4) {
        printf("Easter is April %d in %d. \n", EasterDate, year);
    }else if (EasterMonth == 5) {
        printf("Easter is May %d in %d. \n", EasterDate, year);
    }else if (EasterMonth == 6) {
        printf("Easter is June %d in %d. \n", EasterDate, year);
    }else if (EasterMonth == 7) {
        printf("Easter is July %d in %d. \n", EasterDate, year);
    }else if (EasterMonth == 8) {
        printf("Easter is August %d in %d. \n", EasterDate, year);
    }else if (EasterMonth == 9) {
        printf("Easter is September %d in %d. \n", EasterDate, year);
    }else if (EasterMonth == 10) {
        printf("Easter is Ocotober %d in %d. \n", EasterDate, year);
    }else if (EasterMonth == 11) {
        printf("Easter is November %d in %d. \n", EasterDate, year);
    }else if (EasterMonth == 12) {
        printf("Easter is December %d in %d. \n", EasterDate, year);
    } else {
        printf("Please reenter the year: ");
        scanf("%d", &year);
    }

    return 0;
}
