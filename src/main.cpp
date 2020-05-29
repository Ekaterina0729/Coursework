#include "header.h"
#include <ctime>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int score = 150;
struct verb slova[100];

int main()
{
    int i = 0, button;
    int count_attempt = 1;
    struct glag g1;
    srand(time(0));
    setlocale(LC_ALL, "Rus");
    while (1) {
        i = rand() % 100 + 1;
        read_verb("./src/Slovar.txt",slova);
        puts("__________________\n");
        puts(" 1 Начать тест");
        puts(" 2 Словарь");
        puts(" 3 Начать заново");
        puts(" 4 Результат");
        puts(" 0 Закончить");
        puts("__________________\n");
        scanf("%d", &button);
        switch (button) {
        case 1:
            test(slova, g1, count_attempt, i, 0,score);
            break;
        case 2:
            dictionary(slova);
            break;
        case 3:
            new_test("./src/Slovar2.txt", "./src/Rezultat.txt");
            break;
        case 4:
            rezult(score,slova);
            break;
        case 0:
            return 0;
        default:
            puts(" error");
        }
    }
    return 0;
}
