#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "SpellCh.h"

char  *words[]= {
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

int  main () {
    int reg;
    char word[BUFSIZ];
    char *ret;
    Dict dict ={sizeof(words), length, words};
    for (reg = 0;reg < dict.size; reg++) {
	printf("%d%s\n",reg, words[reg]);
    }
    for(;;) {
	scanf("%s",word);
	if(SpellCheckerAuto(word, &dict, &ret)) {
	    printf(" %s ", ret);
	} else {
	    printf(" %s ", word);
	}
    }
    return 0;
}