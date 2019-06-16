#include "../src/dict.h"
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
    Dict* dict = loadDict(fopen("dict.txt", "r"));

    ASSERT_EQUAL(dict->size, 3);
    ASSERT_STR(dict->words[0], "first");
    ASSERT_STR(dict->words[1], "second");
    ASSERT_STR(dict->words[2], "first");
}
CTEST(spellchecker, save)
{
    char* words[] = {"first, second, third"};
    // char** words = malloc(sizeof(char*)*3);
    Dict dict = {3, 3, words};
    FILE* testfile = fopen("test.txt", "w+");
    saveDict(testfile, &dict);
    fclose(testfile);

    testfile = fopen("test.txt", "r+");
    char* word;

    ASSERT_STR(fgets(word, 254, testfile), "first");
    ASSERT_STR(fgets(word, 254, testfile), "second");
    ASSERT_STR(fgets(word, 254, testfile), "third");
    fclose(testfile);
    remove("test.txt");
}