#include "SpellCh.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DICTNAME "dict1.txt"
#define COMCOUNT 2

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("only 1 argument required");
        return 1;
    }
    FILE* dictfile = fopen(DICTNAME, "r+");
    if (dictfile == NULL) {
        printf("dict file not found, requiered dictonary with name %s \n",
               DICTNAME);
        return -2;
    }
    FILE* src = fopen(argv[1], "r+");
    if (src == NULL) {
        printf("file not found\n");
        fclose(dictfile);
        return -1;
    }
    FILE* out = fopen("temp.txt", "w+");
    if (out == NULL) {
        printf("write file error\n");
        fclose(dictfile);
        return -1;
    }
    int buff = checkFile(src, dictfile, out);
    if (buff == 0) {
        remove(argv[1]);
        rename("temp.txt", argv[1]);
        return 0;
    } else if (buff == -1) {
        printf("memory error\n");
    } else {
        printf("word is oversized(words must be shorter than 254) \n");
    }
    fclose(dictfile);
    fclose(src);
    return 0;
}