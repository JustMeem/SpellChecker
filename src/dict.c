#include "dict.h"
#define WORDSIZE 255


int popDict(Dict *dict, char* str){
    if(str == NULL)
        return 2;
    if(dict->size + 1 > dict->capacity){
        dict->capacity *= 2;
        dict->words = realloc(dict->words, dict->capacity);
        if(dict->words == NULL)
            return 1;
    }
    dict->words[dict->size++] = str;
    return 0;
}

Dict *loadDict(FILE *savefile){
    Dict *dict = malloc(sizeof(Dict));
    if(dict == NULL)
        return NULL;
    dict->words = malloc(sizeof(char*) * 10000);
    dict->capacity = 10000;
    dict->size = 0;
    if(dict->words = NULL){
        free(dict);
        return NULL;
    }
    char *word = malloc(sizeof(char) * WORDSIZE);
    while(fgetc(word, WORDSIZE, savefile)){
        popDict(dict, word);
        word = malloc(sizeof(char) * WORDSIZE);
    }
}
int saveDict(FILE *savefile, Dict *dict){
    for (size_t i = 0; i < dict->size; i++)
    {
        if(fputs(dict->words[i], savefile) == 0)
            return 1;
    }
    return 0;
}

void freeDict(Dict *dict){
    for (size_t i = 0; i < dict->size; i++)
    {
        free(dict->words[i]);
    }
    free(dict->words);
    free(dict);
}