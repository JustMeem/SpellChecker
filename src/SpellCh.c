#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
//#include "SpellChecker.h"
char * words[] =
{
    "join",
    "oil",
    "home",
    "good",
    "go",
    "hello",
    "night",
    "right",
    "left",
    "run",
    "demon"
};
int length = sizeof(words)/sizeof(*words);

int raven(char *w1, char *w2) {
    while(*w1 || *w2) {
	if (tolower(*w1)!=tolower(*w2)) {
	    return 0;
	}
	w1++;
	w2++;
    }
    return 1;
}


int SpellChecker(char *word, char *words[]) {
    int reg;
    for (reg = 0;reg < length; reg++) {
	if (raven(word, words[reg])) {
	    return 0;
	}
    }
    return -1;
}
int  main () {
    int reg;
    char word[BUFSIZ];
    for (reg = 0;reg < length; reg++) {
	printf("%d%s\n",reg, words[reg]);
    }
    for(;;) {
	scanf("%s",word);
	if(SpellChecker(word,words) != 0) {
	    printf("Ochibka: %s\n", word);
	}
    }
    return 0;
}