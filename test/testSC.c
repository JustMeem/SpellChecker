#include "../src/SpellCh.h"
#include "../thirdparty/ctest.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* words[] = {"join",
                 "oil",
                 "home",
                 "good",
                 "go",
                 "hello",
                 "night",
                 "right",
                 "left",
                 "run",
                 "demon"};
int length = sizeof(words) / sizeof(*words);

CTEST(spellchecker, auto)
{
    char* word[] = {"jon", "john", "joiin", "joni", "gohome", "join", "jnnn"};
    char* ret;

    Dict dict = {sizeof(words), length, words};

    int c2 = 0;
    int c4 = 0;
    int c6 = 0;
    int c8 = 0;
    int c10 = 0;
    int c12 = 0;
    int c14 = 0;

    int c1 = SpellCheckerAuto(word[0], &dict, &ret);
    if (strcmp(ret, "join") == 0) {
        c2 = 1;
    }
    int c3 = SpellCheckerAuto(word[1], &dict, &ret);
    if (strcmp(ret, "join") == 0) {
        c4 = 1;
    }
    int c5 = SpellCheckerAuto(word[2], &dict, &ret);
    if (strcmp(ret, "join") == 0) {
        c6 = 1;
    }
    int c7 = SpellCheckerAuto(word[3], &dict, &ret);
    if (strcmp(ret, "join") == 0) {
        c8 = 1;
    }
    int c9 = SpellCheckerAuto(word[4], &dict, &ret);
    if (strcmp(ret, "go home") == 0) {
        c10 = 1;
    }
    int c11 = SpellCheckerAuto(word[5], &dict, &ret);
    if (strcmp(ret, "join") != 0) {
        c12 = 1;
    }
    int c13 = SpellCheckerAuto(word[6], &dict, &ret);
    if (strcmp(ret, "join") != 0) {
        c14 = 1;
    }

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 1;
    const int exp10 = 1;
    const int exp11 = 0;
    const int exp12 = 1;
    const int exp13 = 0;
    const int exp14 = 1;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
    ASSERT_EQUAL(exp11, c11);
    ASSERT_EQUAL(exp12, c12);
    ASSERT_EQUAL(exp13, c13);
    ASSERT_EQUAL(exp14, c14);
}
/*
CTEST(spellchecker, hand)
{
    char *word[] = {
        "jon",
        "john",
        "joiin",
        "joni",
        "gohome",
        "join",
        "jnnn"
    };
    char *ret;

    Dict dict ={sizeof(words), length, words};

    int c2 = 0;
    int c4 = 0;
    int c6 = 0;
    int c8 = 0;
    int c10 = 0;
    int c12 = 0;
    int c14 = 0;

    int c1 = SpellCheckerHand(word[0], &dict, &ret);
    if (strcmp(ret, "join")==0) {
        c2 = 1;
    }
    int c3 =SpellCheckerHand(word[1], &dict, &ret);
    if (strcmp(ret, "join")==0) {
        c4 = 1;
    }
    int c5 =SpellCheckerHand(word[2], &dict, &ret);
    if (strcmp(ret, "join")==0) {
        c6 = 1;
    }
    int c7 =SpellCheckerHand(word[3], &dict, &ret);
    if (strcmp(ret, "join")==0) {
        c8 = 1;
    }
    int c9 =SpellCheckerHand(word[4], &dict, &ret);
    if (strcmp(ret, "go home")==0) {
        c10 = 1;
    }
    int c11 =SpellCheckerHand(word[5], &dict, &ret);
    if (strcmp(ret, "join")!=0) {
        c12 = 1;
    }
    int c13 =SpellCheckerHand(word[6], &dict, &ret);
    if (strcmp(ret, "join")!=0) {
        c14 = 1;
    }
    

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 1;
    const int exp10 = 1;
    const int exp11 = 0;
    const int exp12 = 1;
    const int exp13 = 0;
    const int exp14 = 1;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
    ASSERT_EQUAL(exp11, c11);
    ASSERT_EQUAL(exp12, c12);
    ASSERT_EQUAL(exp13, c13);
    ASSERT_EQUAL(exp14, c14);
}
*/
CTEST(spellchecker, razb)
{
    char* word[] = {"gohome", "go home", "homego", "hemego", "h6mego"};
    char* ret;

    Dict dict = {sizeof(words), length, words};

    int c2 = 0;
    int c4 = 0;
    int c6 = 0;
    int c8 = 0;
    int c10 = 0;

    int c1 = razb(word[0], &dict, &ret);
    if (strcmp(ret, "go home") == 0) {
        c2 = 1;
    }
    int c3 = razb(word[1], &dict, &ret);
    if (strcmp(ret, "go home") != 0) {
        c4 = 1;
    }
    int c5 = razb(word[2], &dict, &ret);
    if (strcmp(ret, "home go") == 0) {
        c6 = 1;
    }
    int c7 = razb(word[3], &dict, &ret);
    if (strcmp(ret, "home go") != 0) {
        c8 = 1;
    }
    int c9 = razb(word[4], &dict, &ret);
    if (strcmp(ret, "home go") != 0) {
        c10 = 1;
    }

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 0;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 1;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
}
CTEST(spellchecker, potb)
{
    char* word[] = {
            "jon",
            "joi",
            "oin",
            "heo",
            "j7n",
    };

    int c1 = potb(word[0], words[0]);
    int c2 = potb(word[1], words[0]);
    int c3 = potb(word[2], words[0]);
    int c4 = potb(word[3], words[0]);
    int c5 = potb(word[4], words[0]);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 0;
    const int exp5 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
}
CTEST(spellchecker, lishb)
{
    char* word[] = {
            "joinq",
            "hjoin",
            "joyin",
            "joiiin",
            "jo7in",
    };

    int c1 = lishb(word[0], words[0]);
    int c2 = lishb(word[1], words[0]);
    int c3 = lishb(word[2], words[0]);
    int c4 = lishb(word[3], words[0]);
    int c5 = lishb(word[4], words[0]);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 0;
    const int exp5 = 1;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
}
CTEST(spellchecker, zamb)
{
    char* word[] = {
            "joir",
            "hoin",
            "jyin",
            "jion",
            "j7in",
    };

    int c1 = zamb(word[0], words[0]);
    int c2 = zamb(word[1], words[0]);
    int c3 = zamb(word[2], words[0]);
    int c4 = zamb(word[3], words[0]);
    int c5 = zamb(word[4], words[0]);
    printf(" %d ", c5);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 0;
    const int exp5 = 1;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
}
CTEST(spellchecker, perb)
{
    char* word[] = {
            "joni",
            "ojin",
            "jion",
            "ojni",
            "7jin",
    };

    int c1 = perb(word[0], words[0]);
    int c2 = perb(word[1], words[0]);
    int c3 = perb(word[2], words[0]);
    int c4 = perb(word[3], words[0]);
    int c5 = perb(word[4], words[0]);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 0;
    const int exp5 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
}
CTEST(spellchecker, raven)
{
    char* word[] = {
            "join",
            "Join",
            "JoIn",
            "jon",
            "jon7",
    };

    int c1 = raven(word[0], words[0]);
    int c2 = raven(word[1], words[0]);
    int c3 = raven(word[2], words[0]);
    int c4 = raven(word[3], words[0]);
    int c5 = raven(word[4], words[0]);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 0;
    const int exp5 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
}
