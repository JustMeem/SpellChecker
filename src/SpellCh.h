#ifndef SPELLCH_H
#define SPELLCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct Dict{
    int capacity;
    int size;
    char** words;
}Dict;

int editsc(char *word, char *eq, int y);
int raven(char *w1, char *w2);
int lishb(char *word, char *eq, int y);
int potb(char *word, char *eq, int y);
int zamb(char *word, char *eq, int y);
int perb(char *word, char *eq, int y);
int razb(char *word, Dict *dict, char **w);
int SpellCheckerAuto(char *word, Dict *dict, char **ret);
int SpellCheckerHand(char *word, Dict *dict, char **ret);

#endif
