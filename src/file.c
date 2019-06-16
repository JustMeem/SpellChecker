#include "file.h"


int readFIle(FILE* src, FILE* dictfile)
{
    Dict* dict = loadDict(dictfile);
    if (dict == NULL) {
        return -1;
    }
    char* word = malloc(sizeof(char) * 255);
    int i = 0;
    char buffer;
    while ((buffer = fgetc(src)) != EOF) {
        if (isalpha(buffer)) {
            if (i < 255)
                word[i++] = buffer;
            else
                return 1;
        } else {
            if (i == 0)
                continue;
            word[i] = '\0';
            popDict(dict, word);
            word = malloc(sizeof(char) * 255);
            if (word == NULL) {
                freeDict(dict);
                return -1;
            }
            i = 0;
        }
    }
    saveDict(dictfile, dict);
    freeDict(dict);
    return 0;
}

int checkFile(FILE* src, FILE* dictfile, FILE* out)
{
    Dict* dict = loadDict(dictfile);
    if (dict == NULL) {
        return -1;
    }
    char* word = malloc(sizeof(char) * 255);
    int i = 0;
    char buffer;
    while ((buffer = fgetc(src)) != EOF) {
        if (isalpha(buffer)) {
            if (i < 255)
                word[i++] = buffer;
            else
                return 1;
        } else {
            fputc(buffer, out);
            if (i == 0)
                continue;
            word[i] = '\0';
            SpellCheckerAuto(word, dict, &word);
            fputs(word, out);
            word = malloc(sizeof(char) * 255);
            if (word == NULL) {
                freeDict(dict);
                return -1;
            }
            i = 0;
        }
    }
    freeDict(dict);
    return 0;
}
