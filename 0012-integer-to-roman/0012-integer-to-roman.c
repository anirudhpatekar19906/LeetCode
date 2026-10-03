#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char* syms[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    char* result = (char*)malloc(16);
    result[0] = '\0';

    for (int i = 0; i < 13; i++) {
        while (num >= vals[i]) {
            strcat(result, syms[i]);
            num -= vals[i];
        }
    }
    return result;
}