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

int potb(char *word, char *eq)
{
    char e;
    int reg;
    int i,k;
    char t[BUFSIZ];
    for (e = 'a';e <= 'z';e++) {
	if(strlen(word) < 2) {
	    t[0] = e;
	    t[1] = word[0];
	    t[2] = '\0';
	    if (raven(t, eq)) {
		return 1;
	    }
	    t[1] = e;
	    t[0] = word[0];
	    t[2] = '\0';
	    if (raven(t, eq)) {
		return 1;
	    }
	}
	for (reg = 0;reg < strlen(word)+1; reg++) {
	    for (i = 0; i < reg;i++) {
		t[i] = word[i];
		k = i + 1;
	    }
	    t[reg] = e;
	    for (i = reg; i < strlen(word);i++) {
		k = i+1;
		t[i+1] = word[i];
	    }
	    if (reg == strlen(word)) {
		k=reg;
	    }
	    t[k+1] ='\0';
	    if (raven(t,eq)) {
		return 1;
	    }
	}
    }
    return 0;
}

int razb(char *word, char *words[], char **w)
{
    int reg;
    int i,k,l,o;
    char t[BUFSIZ], m[BUFSIZ], f[BUFSIZ];
    for (reg = 1;reg < strlen(word)-1; reg++) {
	l=0;
	o=0;
	for (i = 0; i < reg;i++) {
	    t[i] = word[i];
	    f[i] = word[i];
	}
	f[reg] = ' ';
	for (i = reg; i < strlen(word);i++) {
	    m[o] = word[i];
	    k=i;
	    o++;
	    f[i+1] = word[i];
	}
	t[reg] ='\0';
	m[o] ='\0';
	f[k+2] ='\0';
	for (i = 0;i< length;i++) {
	    if (raven(t,words[i])) {
		l++;
		break;
	    }
	}
	for (i = 0;i< length;i++) {
	    if (raven(m,words[i])) {
		l++;
		break;
	    }
	}
	if(l==2) {
	    *w = f;
	    return 1;
	}
    }
    return 0;
}


int zamb(char *word, char *eq)
{
    char e;
    int reg;
    int i,k;
    char t[BUFSIZ];
    for (e = 'a';e <= 'z';e++) {
	for (reg = 0;reg < strlen(word); reg++) {
	    for (i = 0; i < strlen(word);i++) {
		t[i] = word[i];
		k=i;
	    }
	    t[reg] = e;
	    t[k+1] ='\0';
	    if (raven(t,eq)) {
		return 1;
	    }
	}
    }
    return 0;
}

int perb(char *word, char *eq)
{
    int reg;
    int i;
    char t[BUFSIZ];
    for (reg = 0;reg < strlen(word)-1; reg++) {
	for (i = 0; i < sizeof(word);i++) {
	    t[i] = word[i];
	}
	t[reg] = word[reg + 1];
	t[reg + 1] = word[reg];
	if (raven(t,eq)) {
	    return 1;
	}
    }
    return 0;
}

int SpellCheckerAuto(char *word, char *words[], char **ret) {
    int reg;
    char *w;
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
	if(potb(word, words[reg])) {
	    *ret = words[reg];
	    return 0;
	}
	if(perb(word, words[reg])) {
	    *ret = words[reg];
	    return 0;
	}
	if(zamb(word, words[reg])) {
	    *ret = words[reg];
	    return 0;
	}
    }
    if (razb(word, words, &w)) {
	*ret = w;
	return 0;
    }
    return 1;
}

int SpellCheckerHand(char *word, char *words[], char **ret) {
    int reg, j;
    int k = 0;
    char *u[BUFSIZ];
    for (reg = 0;reg < length; reg++) {
	if (raven(word, words[reg])) {
	    return 1;
	}
    }
    for (reg = 0;reg < length; reg++) {
	if(lishb(word, words[reg])) {
	    u[k] = words[reg];
	    k++;
	}
	if(potb(word, words[reg])) {
	    u[k] = words[reg];
	    k++;
	}
	if(perb(word, words[reg])) {
	    u[k] = words[reg];
	    k++;
	}
	if(zamb(word, words[reg])) {
	    u[k] = words[reg];
	    k++;
	}
	
    }
    if (k) {
	for (int i = 0;i < k;i++) {
	    printf("%d-%s\n", i, u[i]);
	}
	scanf("%d", &j);
	*ret = u[j];
	return 0;
    }
    char *w;
    if(razb(word, words, &w)) {
	*ret=w;
	return 0;
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
	if(SpellCheckerHand(word, words, &ret) < 1) {
	    printf(" %s ", ret);
	} else {
	    printf(" %s ", word);
	}
    }
    return 0;
}