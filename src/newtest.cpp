#include "header.h"
#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int new_test(const string fname_S2, const string fname_R)
{
    char button;
    fstream S(fname_S2, ios_base::out);
    fstream S1(fname_R, ios_base::out);
    printf("Программа обновлена! \n ");
    S.close();
    S1.close();
    return 0;
}