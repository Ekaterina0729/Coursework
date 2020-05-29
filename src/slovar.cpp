#include "header.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

extern struct verb v1;
extern struct verb slova[];

using namespace std;
int read_verb(const string name)
{
    int i=0;
    ifstream S(name, ios_base::in);
    if (S.is_open()) {
        while (!S.eof()) {
            S >> slova[i].G1 >> slova[i].G2 >> slova[i].G3 >> slova[i].G4;
            i++;
        }
    } else
    {
        printf("\n Error open file \n");
        return 1;
    }
    S.close();
    return i;
}