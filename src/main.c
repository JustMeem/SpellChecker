#include "SpellCh.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DICTNAME "dict.txt"
#define COMCOUNT 2

char* commandList[] = {"read", "check"};

int command(char* str)
{
    for (int i = 0; i < COMCOUNT; i++) {
        if (strcmp(str, commandList[i]) == 0)
            return i;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("only 3 arguments required");
        return 1;
    }
    FILE* dictfile = fopen(DICTNAME, "r+");
    if (dictfile == NULL) {
        printf("dict file not found, requiered dictonary with name %s \n",
               DICTNAME);
        return -2;
    }
    FILE* src = fopen(argv[3], "r+");
    if (src == NULL) {
        printf("file not found\n");
        fclose(dictfile);
        return -1;
    }
    switch (command(argv[2])) {
    case 1: // read
        readFile(src, dictfile);
        fclose(dictfile);
        fclose(src);
        return 0;
    case 2:; // check
        FILE* out = fopen("temp.txt", "w+");
        if (out == NULL) {
            printf("write file error\n");
            fclose(dictfile);
            return -1;
        }
        int buff = checkFile(src, dictfile, out);
        if (buff == 0) {
            remove(DICTNAME);
            rename("temp.txt", DICTNAME);
            return 0;
        } else if (buff == -1) {
            printf("memory error\n");
        } else {
            printf("word is oversized(words must be shorter than 254) \n");
        }
        fclose(dictfile);
        fclose(src);
        return -1;
    default:
        printf("not found command %s\n", argv[2]);
        fclose(dictfile);
        return 2;
    }
}