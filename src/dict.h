#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dict {
    int capacity;
    int size;
    char** words;
} Dict;

int popDict(Dict* dict, char* str);
Dict* loadDict(FILE* savefile);
void freeDict(Dict* dict);