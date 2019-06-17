#include "../src/file.h"
#include "../thirdparty/ctest.h"

CTEST(spellchecker, check){
    FILE *testfile = fopen("test.txt", "w+");
    fputs("first", testfile);
    fputs("secnd", testfile);
    fputs("therd", testfile);
    FILE *dict = fopen("dict.txt", "r+");
    FILE *out = fopen("temp.txt", "w+");
    checkFile(testfile, dict, out);

    fclose(out);
    out = fopen("temp.txt", "r+"); 

    char* word = malloc(sizeof(char*)*254);
    ASSERT_STR(fgets(word, 254, out), "first");
    ASSERT_STR(fgets(word, 254, out), "second");
    ASSERT_STR(fgets(word, 254, out), "third");
    free(word);

    fclose(out);
    fclose(dict);
    fclose(testfile);
    
    remove("temp.txt");
    remove("test.txt");
}
CTEST(spellchecker, read){
    FILE *testfile = fopen("test.txt", "w+");
    fputs("fourth\n", testfile);
    fputs("fifth\n", testfile);
    fputs("sixth\n", testfile);

    FILE* dict = fopen("dict.txt", "r+");
    readFile(testfile, dict);
    fclose(testfile); 

    char* word = malloc(sizeof(char*)*254);

    testfile = fopen("test.txt", "r+");
    ASSERT_STR(fgets(word, 254, testfile), "first");
    ASSERT_STR(fgets(word, 254, testfile), "second");
    ASSERT_STR(fgets(word, 254, testfile), "third");
    ASSERT_STR(fgets(word, 254, testfile), "fourth");
    ASSERT_STR(fgets(word, 254, testfile), "fifth");
    ASSERT_STR(fgets(word, 254, testfile), "sixth");
    free(word);
    fclose(testfile);
    remove("test.txt");
    fclose(dict);

    testfile = fopen("dict.txt", "r+");
    fputs("first", testfile);
    fputs("secnd", testfile);
    fputs("therd", testfile);
    fclose(testfile);
}