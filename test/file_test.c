#include "../src/file.h"

CTEST(spellchecker, check){
    FILE *testfile = fopen("test.txt", "w+");
    fputs("first", testfile);
    fputs("secnd", testfile);
    fputs("therd", testfile);
    FILE *dict = fopen("dict.txt", "r+");
    FILE *out = fopen("temp.txt", "w+");
    checkFile(testfile, dict, out);

    char* word;

    ASSERT_STR(fgets(word, 254, out), "first");
    ASSERT_STR(fgets(word, 254, out), "second");
    ASSERT_STR(fgets(word, 254, out), "third");

    
    fclose(out);
    fclose(dict);
    fclose(testfile);
    remove("temp.txt");
    remove("test.txt");
}
CTEST(spellchecker, read){
    FILE *testfile = fopen("test.txt", "w+");
    fputs("fourth", testfile);
    fputs("fifth", testfile);
    fputs("sixth", testfile);
    
    FILE* dict = fopen("dict.txt", "r+");
    readFile(testfile, dict);
    fclose(testfile); 

    char* word;

    ASSERT_STR(fgets(word, 254, testfile), "first");
    ASSERT_STR(fgets(word, 254, testfile), "second");
    ASSERT_STR(fgets(word, 254, testfile), "third");
    ASSERT_STR(fgets(word, 254, testfile), "fourth");
    ASSERT_STR(fgets(word, 254, testfile), "fifth");
    ASSERT_STR(fgets(word, 254, testfile), "sixth");
    fclose(testfile);
    remove("test.txt");
    fclose(dict);

    FILE *testfile = fopen("dict.txt", "r+");
    fputs("first", testfile);
    fputs("secnd", testfile);
    fputs("therd", testfile);
}