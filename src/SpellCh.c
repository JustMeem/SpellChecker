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

void regist(char *word)
{
    int reg;
    for (reg = 0;reg < sizeof(word); reg++) {
	if (reg > 0) {
	    word[reg] = tolower(word[reg]);
	}
    }
    printf("%s", word);
}
int lishb(char *word, char *eq)
{
    int reg, i,k;
    char t[BUFSIZ];
    for (reg = 0;reg < strlen(word); reg++) {
	for (i = 0; i < reg;i++) {
	    t[i] = word[i];
	}
	for (i = reg; i < strlen(word)-1;i++) {
	    k = i;
	    t[i] = word[i+1];
	}
	t[k+1] ='\0';
	if (raven(t,eq)) {
	    return 1;
	}
    }
    return 0;
}

int SpellChecker(char *word, char *words[], char **ret) {
    int reg;
    for (reg = 0;reg < length; reg++) {
	if (raven(word, words[reg])) {
	    return 1;
	}
    }
    for (reg = 0;reg < length; reg++) {
	if(lishb(word, words[reg])) {
	    *ret = words[reg];
	    return 0;
	}
    }
    return 1;
}
int  main () {
    int reg;
    char word[BUFSIZ];
    char *ret;
    for (reg = 0;reg < length; reg++) {
	printf("%d%s\n",reg, words[reg]);
    }
    for(;;) {
	scanf("%s",word);
	if(SpellChecker(word, words, &ret) < 1) {
	    printf(" %s ", ret);
	} else {
	    printf(" %s ", word);
	}
    }
    return 0;
}