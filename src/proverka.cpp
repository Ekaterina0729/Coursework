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
        struct verb slova[100],
        struct glag user,
        int count_attempt,
        int i,
        int count_rand,
        int score)
{
    int next_verb, mark = 1;
    int l = 0;
    struct glag g1;
    ifstream S2("./src/Slovar2.txt", ios_base::in);
    if (S2.is_open()) {
        while (!S2.eof()) {
            S2 >> slova[l].G1 >> slova[l].G2 >> slova[l].G3 >> slova[l].G4;
            if ((!strcmp(slova[l].G1, slova[i].G1))
                && (!strcmp(slova[l].G2, slova[i].G2))
                && (!strcmp(slova[l].G3, slova[i].G3))
                && (!strcmp(slova[l].G4, slova[i].G4))) {
                i = rand() % 100;
                count_rand++;
                if (count_rand < 300)
                    test(slova, g1, count_attempt, count_rand, i,score);
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
    printf("Глагол: %s \n ", slova[i].G4);
    printf("Введите три формы глагола \n ");
gl1:
    if (strcmp(user.G1, slova[i].G1)) {
        printf("Первая форма глагола: \n ");
        scanf("%s", user.G1);
        if (data(user.G1) == 0) {
            goto gl1;
        }
    }
gl2:
    if (strcmp(user.G2, slova[i].G2)) {
        printf("Вторая форма глагола: \n ");
        scanf("%s", user.G2);
        if (data(user.G2) == 0) {
            goto gl2;
        }
    }
gl3:
    if (strcmp(user.G3, slova[i].G3)) {
        printf("Третья форма глагола: \n ");
        scanf("%s", user.G3);
        if (data(user.G3) == 0) {
            goto gl3;
        }
    }
    if (!strcmp(user.G1, slova[i].G1) && !strcmp(user.G2, slova[i].G2)
        && !strcmp(user.G3, slova[i].G3)) {
        metka(slova[i].G1, slova[i].G2, slova[i].G3, slova[i].G4);
        printf("Всё верно!Так держать! \n ");
        mark = 0;
        next_verb = verbs_next(slova, user, count_attempt, count_rand, 0,score);
    } else {
        mark = 1;
        next_verb = 1;
    }
    if (next_verb) {
        mark = 1;
        count_attempt = check_verb(slova, user, count_attempt, i,score);
    }
    count_verb = 1;
    score = 150;
    if (mark == 1)
        return 0;
    else
        return 1;
}
void metka(char G1[30], char G2[30], char G3[30], char G4[30])
{
    ofstream S("./src/Slovar2.txt", ios::app);
    S << G1 << " " << G2 << " " << G3 << " " << G4 << "\n";
    S.close();
}
