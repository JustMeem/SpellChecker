#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <dict.h>

int readFile(FILE* src, FILE* dictfile);
int checkFile(FILE* src, FILE* dictfile, FILE* out);