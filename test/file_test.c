#include "../src/file.h"
#include "../thirdparty/ctest.h"

/*
CTEST(spellchecker, check){
    FILE *testfile = fopen("test.txt", "w+");
    fputs("first?!###!#@#!#!#@# secnd", testfile);
    FILE *dict = fopen("dict.txt", "r+");
    FILE *out = fopen("temp.txt", "w+");
    fclose(testfile);
    testfile = fopen("test.txt", "r+");
    checkFile(testfile, dict, out);

    
    fclose(out);
    out = fopen("temp.txt", "r+"); 
    char* word = malloc(sizeof(char*)*254);
    
    ASSERT_STR(fgets(word, 254, out), "first?!###!#@#!#!#@# second");
    free(word);

    fclose(out);
    fclose(dict);
    fclose(testfile);

    remove("temp.txt");
    remove("test.txt");
} 
CTEST(spellchecker, read){
    FILE *testfile = fopen("temp.txt", "w+");
    fputs("fourth\nfifth\nsixth", testfile);

    FILE *dictfile = fopen("dict.txt", "r+");

    readFile(testfile, dictfile);
    fclose(testfile);
    fclose(dictfile);

    dictfile = fopen("dict.txt", "r+");
    char *s = malloc(sizeof(char) * 255);
    ASSERT_STR("first\n", fgets(s, 254, dictfile));
    ASSERT_STR("second\n", fgets(s, 254, dictfile));
    ASSERT_STR("third\n", fgets(s, 254, dictfile));
    ASSERT_STR("fourth\n", fgets(s, 254, dictfile));
    ASSERT_STR("fifth\n", fgets(s, 254, dictfile));
    ASSERT_STR("sixth\n", fgets(s, 254, dictfile));
    free(s);
    fclose(dictfile);

    dictfile = fopen("dict.txt", "w+");
    fputs("first\nsecond\nthird", dictfile);
    fclose(dictfile);
}*/