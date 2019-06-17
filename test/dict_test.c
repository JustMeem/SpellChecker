#include "../src/dict.h"
#include "../thirdparty/ctest.h"
#define PRINT_D(X) printf("%d\n", X)
#define PRINT_S(X) printf("%s\n", X)
/*
typedef struct Dict {
    int capacity;
    int size;
    char** words;
} Dict;
*/ 

CTEST(spellchecker, pop)
{
    char** words = malloc(sizeof(char*) * 3);
    Dict dict = {3, 0, words};

    for (int i = 0; i < 5; i++) {
        popDict(&dict, "word");
    }

    ASSERT_EQUAL(dict.size, 5);
    ASSERT_EQUAL(dict.capacity, 7);
    ASSERT_STR(dict.words[0], "word");
    ASSERT_STR(dict.words[1], "word");
    ASSERT_STR(dict.words[2], "word");
    ASSERT_STR(dict.words[3], "word");
    ASSERT_STR(dict.words[4], "word");

    free(words);
}
CTEST(spellchecker, load)
{
    Dict* dict = loadDict(fopen("dict.txt", "r+"));
    ASSERT_EQUAL(3,dict->size);
    ASSERT_STR("first", dict->words[0]);
    ASSERT_STR("second", dict->words[1]);
    ASSERT_STR("third", dict->words[2]);
}
CTEST(spellchecker, save)
{
    char* words[] = {"first", "second", "third"};
    // char** words = malloc(sizeof(char*)*3);
    Dict dict = {3, 3, words};
    FILE* testfile = fopen("test.txt", "w");

    saveDict(testfile, &dict);
    fclose(testfile);

    testfile = fopen("test.txt", "r+");
    char* word = malloc(sizeof(char*)*254);

    ASSERT_STR(fgets(word, 254, testfile), "first\n");
    ASSERT_STR(fgets(word, 254, testfile), "second\n");
    ASSERT_STR(fgets(word, 254, testfile), "third\n");
    free(word);
    fclose(testfile);
    remove("test.txt");
}