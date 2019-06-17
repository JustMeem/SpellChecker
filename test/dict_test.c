#include "../src/dict.h"
#include "../thirdparty/ctest.h"

CTEST(spellchecker, pop)
{
    char** words = malloc(sizeof(char*) * 3);
    Dict *dict = malloc(sizeof(Dict));
    dict->capacity = 3;
    dict->size = 0;
    dict->words = words;

    for (int i = 0; i < 4; i++) {
        popDict(dict, "word");
    }


    ASSERT_EQUAL(dict->size, 4);
    ASSERT_EQUAL(dict->capacity, 7);
    ASSERT_STR(dict->words[0], "word");
    ASSERT_STR(dict->words[1], "word");
    ASSERT_STR(dict->words[2], "word");
    ASSERT_STR(dict->words[3], "word");

    free(words);
}
CTEST(spellchecker, load)
{
    FILE *f_dict = fopen("dict.txt", "r+");
    Dict* dict = loadDict(f_dict);
    ASSERT_EQUAL(3, dict->size);
    ASSERT_STR("first", dict->words[0]);
    ASSERT_STR("second", dict->words[1]);
    ASSERT_STR("third", dict->words[2]);
    fclose(f_dict);
}
