#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SpellCh.h"
#include "dict.h"
#define DICTNAME "dict.txt"
#define COMCOUNT 2


extern char * commandList[] = {
    "read",
    "check"
};

int readFIle(FILE *src, FILE *dictfile){
    Dict *dict = loadDict(dictfile);
    if(dict == NULL){
        return -1;
    }
    char *word = malloc(sizeof(char)*255);
    int i = 0;
    char buffer;
    while((buffer = fgetc(src)) != EOF){
        if(isalpha(buffer)){
            if(i < 255)
                word[i++] = buffer;
            else
                return 1;
        }else{
            if(i == 0)
                continue;
            word[i] = '\0';
            popDict(dict, word);
            word = malloc(sizeof(char)*255);
            if(word == NULL){
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

int checkFile(FILE *src, FILE *dictfile, FILE *out){
    Dict *dict = loadDict(dictfile);
    if(dict == NULL){
        return -1;
    }
    char *word = malloc(sizeof(char)*255);
    int i = 0;
    char buffer;
    while((buffer = fgetc(src)) != EOF){
        if(isalpha(buffer)){
            if(i < 255)
                word[i++] = buffer;
            else
                return 1;
        }else{
            fputc(buffer, out);
            if(i == 0)
                continue;
            word[i] = '\0';
            SpellCheckerAuto(word, dict, &word);
            fputs(word, out);
            word = malloc(sizeof(char)*255);
            if(word == NULL){
                freeDict(dict);
                return -1;
            }
            i = 0;
        }
    }
    freeDict(dict);
    return 0;
}

int command(char *str){
    for(int i = 0; i < COMCOUNT; i++){
        if(strcmp(str, commandList[i]) == 0)
            return i;
    }
    return -1;
}

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("only 3 arguments required");
        return 1;
    }
    FILE *dictfile = fopen(DICTNAME, "r+");
    if(dictfile == NULL){
        printf("dict file not found, requiered dictonary with name %s \n", DICTNAME);
        return -2;
    }

    switch (command(argv[2]))
    {
    case 1: //read
        FILE *src = fopen(argv[3], "r");
        if(src == NULL){
            printf("file not found\n");
            fclose(dictfile);
            return -1;
        }
        return 0;
    case 2: //check
        FILE *src = fopen(argv[3], "r+");
        FILE *out = fopen("temp.txt", "w");
        if(out == NULL){
            printf("write file error\n");
            fclose(dictfile);
            return -1;
        }
        if(src == NULL){
            printf("file not found\n");
            fclose(dictfile);
            return -1;
        }
        int buff = checkFile(src, dictfile, out);
        if(buff == 0){
            remove(DICTNAME);
            rename("temp.txt", DICTNAME);
            return 0;
        }else if (buff == -1)
        {
            printf("memory error\n");
        }else
        {
            printf("word is oversized(words must be shorter than 254) \n");
        }
        return -1;
    default:
        printf("not found command %s\n", argv[2]);
        fclose(dictfile);
        return 2;
    }
}