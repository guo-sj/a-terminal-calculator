#include <stdio.h>
#include "calc.h"

/* baseconv: base conversion */
void baseconv(double num, int base, char result[])
{
    switch (base) {
        case BINARY:
            dec2bin(num, result);
            break;

        case OCTAL:
            dec2oct(num, result);
            break;

        case HEXADECIMAL:
            dec2hex(num, result);
            break;

        default:
            printf("baseconv: error base: %d\n", base);
            break;
    }
}

/* dec2bin: decimal to binary */
void dec2bin(double num, char result[])
{
    ;
}

/* dec2oct: decimal to octal */
void dec2oct(double num, char result[])
{
    ;
}

/* dec2hex: decimal to hexadecimal */
void dec2hex(double num, char result[])
{
    ;
}
