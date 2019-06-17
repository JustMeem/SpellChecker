#ifndef SPELLCH_H
#define SPELLCH_H

#include "dict.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int raven(char* w1, char* w2);
int lishb(char* word, char* eq);
int potb(char* word, char* eq);
int zamb(char* word, char* eq);
int perb(char* word, char* eq);
int razb(char* word, Dict* dict, char** w);
int SpellCheckerAuto(char* word, Dict* dict, char** ret);

#endif
