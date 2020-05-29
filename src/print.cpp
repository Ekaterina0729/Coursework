#include "header.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

extern int count_verb, score;

extern struct verb slova[];

int verbs_next(
        struct verb correct,
        struct glag user,
        int count_attempt,
        int count_rand,
        int y)
{
    char button = 'n';
    int i, next_verb = 1;
    if (count_verb < 11) {
        count_verb++;
        printf("glagol=%d\n", count_verb);
        puts("\n Продолжить или сдаться? y/n");
        scanf("%s", &button);
        switch (button) {
        case 'y':
            i = rand() % 100 + 1;
            test(slova[i], user, count_attempt, i, count_rand);
            break;
        case 'n':
            score = score - ((11 - count_verb) * 15);
            give_up();
            next_verb = 0;
            return next_verb;
            break;
        default:
            puts(" error");
        }
    } else {
        give_up();
        if (y == 1)
            next_verb = 0;
    }
    return next_verb;
}