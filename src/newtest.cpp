#include "header.h"
#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int new_test(const string fname_S2, const string fname_R)
{
    char button;
    ofstream S(fname_S2, ios_base::trunc);
    ofstream S1(fname_R, ios_base::trunc);
    printf("Программа обновлена! \n ");
    S.close();
    S1.close();
    printf("\n Введите любой символ для выхода в меню ");
    scanf("%s", &button);
    return 0;
}
