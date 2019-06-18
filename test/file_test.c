#include "../src/file.h"
#include "../thirdparty/ctest.h"

CTEST(spellchecker, check)
{
    FILE* testfile = fopen("test.txt", "w+");
    fputs("first?!###!#@#!#!#@# secnd", testfile);
    FILE* dict = fopen("dict.txt", "r+");
    FILE* out = fopen("temp.txt", "w+");
    fclose(testfile);
    testfile = fopen("test.txt", "r+");
    checkFile(testfile, dict, out);

    fclose(out);
    out = fopen("temp.txt", "r+");
    char* word = malloc(sizeof(char*) * 254);

    ASSERT_STR(fgets(word, 254, out), "first?!###!#@#!#!#@# second");

}
