#include "file.h"

int checkFile(FILE* src, FILE* dictfile, FILE* out)
{
    Dict* dict = loadDict(dictfile);
    if (dict == NULL) {
        return -1;
    }
    char* word = malloc(sizeof(char) * 255);
    char* wout = malloc(sizeof(char) * 255);
    int i = 0;
    char buffer;
    while (1) {
        buffer = fgetc(src);
        if (isalpha(buffer)) {
            if (i < 255)
                word[i++] = buffer;
            else
                return 1;
        } else {
            if (i != 0) {
                word[i] = '\0';
                if (SpellCheckerAuto(word, dict, &wout)) {
                    fputs(wout, out);
                } else
                    fputs(word, out);
                i = 0;
            }
            if (buffer != EOF)
                fputc(buffer, out);
            else
                break;
        }
    }
    free(wout);
    free(word);
    freeDict(dict);
    return 0;
}
