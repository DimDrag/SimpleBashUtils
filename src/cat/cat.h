#ifndef CAT_H
#define CAT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
typedef unsigned short bool;

void printS(FILE *f);
void printB(FILE *f);
void printN(FILE *f);
void printE(FILE *f, bool big);
void printT(FILE *f, bool big);
void print(FILE *f);
#endif