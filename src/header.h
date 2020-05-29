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
int read_verb(const string name,struct verb slova[100]);
int test(
        struct verb slova[100],
        struct glag user,
        int count_attempt,
        int i,
        int count_rand,
        int score);
void metka(char G1[30], char G2[30], char G3[30], char G4[30]);
int data(char* g);
void dictionary(struct verb slova[100]);
void dictionary_learn_verb(struct verb slova[100]);
int verbs_next(
        struct verb slova[100],
        struct glag user,
        int count_attempt,
        int count_rand,
        int y,
        int score);
int check_verb(
        struct verb slova[100],
        struct glag user,
        int count_attempt,
        int i,
        int score);
int rezult(int score, struct verb slova[100]);
int new_test(const string fname_S2, const string fname_R);
void give_up(struct verb slova[100] ,int score);
#endif
