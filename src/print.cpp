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

void give_up()
{
    puts("\n Тестирование окончено! ");
    printf("Количество баллов %d \n", score);
    rezult(score);
    cin.get();
}
int check_verb(struct verb correct, struct glag user, int count_attempt, int i)
{
    char button = 'y';
    if (strcmp(user.G1, correct.G1)) {
        printf("Первая форма глагола - неверно! Попробуйте ещё раз! \n");
        score--;
    } else {
        printf("Первая форма глагола - отлично! \n");
    }
    if (strcmp(user.G2, correct.G2)) {
        printf("Вторая форма глагола - неверно! Попробуйте ещё раз!\n");
        score--;
    } else {
        printf("Вторая форма глагола - отлично! \n");
    }
    if (strcmp(user.G3, correct.G3)) {
        printf("Третья форма глагола - неверно! Попробуйте ещё раз! \n");
        score--;
    } else {
        printf("Третья форма глагола - отлично! \n");
    }
    puts("\n Продолжить или сдаться? y/n");
    printf("%s \n", user.G1);
    printf("%s \n", user.G2);
    printf("%s \n", user.G3);
    scanf("%s", &button);
    if (count_attempt < 5) {
        count_attempt++;
        switch (button) {
        case 'y':
            test(slova[i], user, count_attempt, i, 0);
            break;
        case 'n':
            i = rand() % 100 + 1;
            test(slova[i], user, count_attempt, i, 0);
            score -= 5;
            break;
        default:
            puts(" error");
        }
    } else {
        puts("У вас закончились попытки.");
        // printf("poptka=%d\n",count_attempt);
        count_attempt = 1;
        verbs_next(correct, user, count_attempt, 0, 1);
    }
    return count_attempt;
}

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