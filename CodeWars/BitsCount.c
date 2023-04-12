#include <limits.h>
#include <stdint.h>
#include <stdio.h>

char countBits(unsigned value)
{
    char counter = 0;
    for (char i = 0; i < (char) sizeof(unsigned) * CHAR_BIT; i++)
        if ((value & 1 << i) != 0) counter++;

    return counter;
}


int main(void)
{
    char size1 = countBits(0b10000000000000000000000000000000);
    char size2 = countBits(0b11000000000000000000000000000000);
    char size3 = countBits(0b11100000000000000000000000000000);
    char size4 = countBits(0b11110000000000000000000000000000);
    char size5 = countBits(0b11111000000000000000000000000000);
    char size6 = countBits(0b11111100000000000000000000000000);
    char size7 = countBits(0b11111110000000000000000000000000);
    char size8 = countBits(0b11111111000000000000000000000000);
    char size9 = countBits(0b11111111100000000000000000000000);
    char size10 = countBits(0b11111111100000000000000000010000);


    printf("bitsCount on %s = %d", "0b10000000000000000000000000000000", size1 );
    printf("bitsCount on %s = %d", "0b11000000000000000000000000000000", size2 );
    printf("bitsCount on %s = %d", "0b11100000000000000000000000000000", size3 );
    printf("bitsCount on %s = %d", "0b11110000000000000000000000000000", size4 );
    printf("bitsCount on %s = %d", "0b11111000000000000000000000000000", size5 );
    printf("bitsCount on %s = %d", "0b11111100000000000000000000000000", size6 );
    printf("bitsCount on %s = %d", "0b11111110000000000000000000000000", size7 );
    printf("bitsCount on %s = %d", "0b11111111000000000000000000000000", size8 );
    printf("bitsCount on %s = %d", "0b11111111100000000000000000000000", size9 );
    printf("bitsCount on %s = %d\"", "0b11111111100000000000000000010000", size10);


}
