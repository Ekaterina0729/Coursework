#include "header.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

extern int score, count_verb;
extern struct verb slova[];

int test(
        struct verb correct,
        struct glag user,
        int count_attempt,
        int i,
        int count_rand)
{
    int next_verb, mark = 1, l = 0;
    struct glag g1;
    ifstream S2("./src/Slovar2.txt", ios_base::in);
    if (S2.is_open()) {
        while (!S2.eof()) {
            S2 >> slova[l].G1 >> slova[l].G2 >> slova[l].G3 >> slova[l].G4;
            if ((!strcmp(slova[l].G1, correct.G1))
                && (!strcmp(slova[l].G2, correct.G2))
                && (!strcmp(slova[l].G3, correct.G3))
                && (!strcmp(slova[l].G4, correct.G4))) {
                i = rand() % 100;
                count_rand++;
                if (count_rand < 300)
                    test(slova[i], g1, count_attempt, count_rand, i);
                else {
                    printf("Поздравляем! Ты выучил все глаголы!");
                    return 2;
                }
                l++;
            }
        }
    } else
        printf("Error open file");
    S2.close();
    printf("Глагол: %s \n ", correct.G4);
    printf("Введите три формы глагола \n ");

    if (strcmp(user.G1, correct.G1)) {
        printf("Первая форма глагола: \n ");
        scanf("%s", user.G1);
    }

    if (strcmp(user.G2, correct.G2)) {
        printf("Вторая форма глагола: \n ");
        scanf("%s", user.G2);
    }

    if (strcmp(user.G3, correct.G3)) {
        printf("Третья форма глагола: \n ");
        scanf("%s", user.G3);
    }
    if (!strcmp(user.G1, correct.G1) && !strcmp(user.G2, correct.G2)
        && !strcmp(user.G3, correct.G3)) {
        metka(correct.G1, correct.G2, correct.G3, correct.G4);
        // printf("Всё верно!Так держать! \n ");
        mark = 0;
        next_verb = verbs_next(correct, user, count_attempt, count_rand, 0);
        printf("next glagol_0=%d\n", next_verb);
    }
    return 1;
}
void metka(char G1[30], char G2[30], char G3[30], char G4[30])
{
    ofstream S("./src/Slovar2.txt", ios::app);
    S << G1 << " " << G2 << " " << G3 << " " << G4 << "\n";
    S.close();
}
