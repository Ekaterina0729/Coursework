#include "header.h"
#include <ctime>
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
    printf("\n Хотите посмотреть словарь? y/n \n");
    scanf("%s", &button);
    switch (button) {
    case 'y':
        dictionary_learn_verb();
        return 0;
        break;
    case 'n':
        return 0;
        break;
    default:
        puts(" error");
    }
    S.close();
    return 0;
}