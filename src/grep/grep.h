#ifndef GREP_H
#define GREP_H
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
typedef unsigned short bool;

typedef struct GrepOptions {
  // перечень опций
  bool flagE;
  bool flagI;
  bool flagV;
  bool flagC;
  bool flagL;
  bool flagN;
  bool flagH;
  bool flagS;
  bool flagF;
  bool flagO;

  // массив для хранения шаблонов для опции -e
  int* templates;
  int number_of_templates;

  // массив для хранения навания файлов для опции -f
  int* file_names_F;
  int number_of_files_F;
} GrepOptions;

void initGrepOptions(GrepOptions* gr);
void destruct(GrepOptions* gr);
void addTemplate(GrepOptions* gr, int num_of_argv);
void addFileName(GrepOptions* gr, int num_of_argv);
void search(FILE* f, GrepOptions gr, bool several, char* argv[], int filename);
#endif
