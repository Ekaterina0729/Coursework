#ifndef CURS_H
#define CURS_H

#include <ctime>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct verb {
    char G1[100];
    char G2[100];
    char G3[100];
    char G4[100];
};
struct glag {
    char G1[100];
    char G2[100];
    char G3[100];
};
int read_verb(const string name);
int test(
        struct verb correct,
        struct glag user,
        int count_attempt,
        int i,
        int count_rand);
void metka(char G1[30], char G2[30], char G3[30], char G4[30]);
#endif