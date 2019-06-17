#include "../src/file.h"
#include "../thirdparty/ctest.h"
/* 
CTEST(spellchecker, read){
    FILE *dict = fopen("dict.txt", "r");
    FILE *src = fopen("words.txt", "r");
    
    readFile(src, dict);

    fclose(dict);
    dict = fopen("dict.txt", "r");

    char *str = malloc(sizeof(char) * 255);
    ASSERT_STR("first\n", fgets(str, 255, dict));
    ASSERT_STR("second\n", fgets(str, 255, dict));
    ASSERT_STR("third", fgets(str, 255, dict));
    ASSERT_STR("fourth\n", fgets(str, 255, dict));
    ASSERT_STR("fifth\n", fgets(str, 255, dict));
    ASSERT_STR("sixth\n", fgets(str, 255, dict));
    fclose(dict);
    dict = fopen("dict.txt", "w");
    fputs("first\nsecond\nthird", dict);
    
    fclose(dict);
    free(str);
}
*/
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
    
    fclose(out);
    fclose(dict);
    fclose(testfile);
    free(word);
}
