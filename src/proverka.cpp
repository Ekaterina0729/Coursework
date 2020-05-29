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
    int next_verb, mark = 1;
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
    return 1;
}
