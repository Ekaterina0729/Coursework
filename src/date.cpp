#include "header.h"
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int data(char* g)
{
    int i = 0;
    while (g[i] < 30) {
        if (g[i] < 'a' || g[i] > 'z') {
            printf("Ошибка. Неверный формат.\nМожно вводить "
                    "только строчные буквы латинского "
                    "алфавита.\n\n");
            return 0;
        i++;
    }
    return 1;
}