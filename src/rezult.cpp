#include "header.h"
#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int rezult(int score)
{
    char button;
    ofstream S("./src/Rezultat.txt", ios_base::app);
    float rez;
    rez = score * 100 / 150;
    S << rez;
    printf("\n Результат вашего тестирвания %.1f процентов \n", rez);
    rez = 0;
    S.close();
    return 0;
}