#include "header.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

extern struct verb v1;
extern struct verb slova[];

using namespace std;
int read_verb(const string name,struct verb slova[100])
{
    int i = 0;
    ifstream S(name, ios_base::in);
        if (S.is_open()) {
        while (!S.eof()) {
            S >> slova[i].G1 >> slova[i].G2 >> slova[i].G3 >> slova[i].G4;
            i++;
        }
    } else {
        printf("\n Error open file \n");
        return 1;
    }
    S.close();
    return i;
}
void dictionary(struct verb slova[100])
{
    int i = 0;
    char button;
    for (i = 0; i < 100; i++) {
        printf("  %10s  %10s  %10s %10s \n",
               slova[i].G1,
               slova[i].G2,
               slova[i].G3,
               slova[i].G4);
    }
    printf("\n Введите любой символ для выхода в меню \n");
    scanf("%s", &button);
}
void dictionary_learn_verb(struct verb slova[100])
{
    int i = 0;
    char button;

    int j = read_verb("./src/Slovar2.txt",slova);
    j--;
    if (j == 0)
        printf("\nВы не выучили ни одного глагола!\n");
    for (i = 0; i < j; i++) {
        printf("  %10s  %10s  %10s %10s \n",
               slova[i].G1,
               slova[i].G2,
               slova[i].G3,
               slova[i].G4);
    }
    printf("\n Введите любой символ для выхода в меню \n");
    scanf("%s", &button);
}
