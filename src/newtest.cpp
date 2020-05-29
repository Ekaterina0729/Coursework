#include "header.h"
#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int new_test(const string fname_S2, const string fname_R)
{
    if (S.is_open() && S1.is_open())
    {
        printf("Программа обновлена! \n ");
        S.close();
        S1.close();
    }
    else{
        printf("\n Error open file \n");
        return 1;
    }
    return 0;
}