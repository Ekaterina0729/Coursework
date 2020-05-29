#include <ctime>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char button;
    srand(time(0));
    setlocale(LC_ALL, "Rus");
    while (1) {
        puts(" 1 Начать тест");
        puts(" 2 Словарь");
        puts(" 3 Начать заново ");
        puts(" 4 Результат ");
        puts(" 0 Закончить");
        scanf("%d", &button);
        switch (button) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            return 0;
        default:
            puts(" error");
        }
    }
    return 0;
}
