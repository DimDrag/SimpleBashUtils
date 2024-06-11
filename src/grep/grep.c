#include "grep.h"
void initGrepOptions(GrepOptions* gr) {
  gr->flagE = false;
  gr->flagI = false;
  gr->flagV = false;
  gr->flagC = false;
  gr->flagL = false;
  gr->flagN = false;
  gr->flagH = false;
  gr->flagS = false;
  gr->flagF = false;
  gr->flagO = false;
  gr->templates = NULL;
  gr->number_of_templates = 0;
  gr->file_names_F = NULL;
  gr->number_of_files_F = 0;
}
void destruct(GrepOptions* gr) {
  free(gr->templates);
  free(gr->file_names_F);
}

void addTemplate(GrepOptions* gr, int num_of_argv) {
  if (gr->templates == NULL) {
    gr->templates = (int*)calloc(1, sizeof(int));
    gr->templates[gr->number_of_templates] = num_of_argv;
    gr->number_of_templates++;
  } else {
    gr->templates[gr->number_of_templates] = num_of_argv;
    gr->number_of_templates++;
    gr->templates =
        realloc(gr->templates, sizeof(int) * (gr->number_of_templates));
  }
}
void addFileName(GrepOptions* gr, int num_of_argv) {
  if (gr->file_names_F == NULL) {
    gr->file_names_F = (int*)calloc(1, sizeof(int));
    gr->file_names_F[gr->number_of_files_F] = num_of_argv;
    gr->number_of_files_F++;
  } else {
    gr->file_names_F[gr->number_of_files_F] = num_of_argv;
    gr->number_of_files_F++;
    gr->file_names_F =
        realloc(gr->file_names_F, sizeof(int) * (gr->number_of_files_F));
  }
}

void search(FILE* f, GrepOptions gr, bool several, char* argv[], int filename) {
  several *= (1 - gr.flagH);
  // флаг для компиляции функции regcomp
  int flag_num;
  if (gr.flagI) {
    flag_num = REG_ICASE;
  } else {
    flag_num = REG_NOSUB;
  }
  char str[1024];
  int c_option_counter = 0;
  int string_counter = 0;
  bool one_match = false;
  bool errorFlag = false;

  while (!errorFlag && fgets(str, 1024, f) != NULL) {
    bool alreadyPrinted = false;
    string_counter++;
    bool template_match = false;
    // обрабатываем все шаблоны, полученные через опцию -e или просто через
    // аргумент
    for (int i = 0; !errorFlag && i < gr.number_of_templates; i++) {
      regex_t rg;
      if (regcomp(&rg, argv[gr.templates[i]], flag_num) != 0) {
        errorFlag = true;
        printf("regular expressions compile error\n");
      }
      if (!errorFlag) {
        if (regexec(&rg, str, 0, 0, 0) == 0) {
          if (gr.flagO && !gr.flagL && !gr.flagC) {
            if (gr.flagN && !alreadyPrinted) {
              printf("%d:", string_counter);
              alreadyPrinted = true;
            }
            printf("%s\n", argv[gr.templates[i]]);
          }
          template_match = true;
        }
      }
      regfree(&rg);
    }
    // обрабатываем все шаблоны, полученные через опцию -f
    for (int i = 0; !errorFlag && i < gr.number_of_files_F; i++) {
      // пробуем открыть файл
      FILE* f = fopen(argv[gr.file_names_F[i]], "r");
      if (f == NULL) {
        errorFlag = true;
        if (!gr.flagS) {
          printf("%s: No such file or directory\n", argv[gr.file_names_F[i]]);
        }
      } else {
        // получаем все шаблоны из файла
        char template[1024];
        while (!errorFlag && fgets(template, 1024, f) != NULL) {
          // нужно убрать символ переноса строки
          for (int i = 0; i < 1024; i++) {
            if (template[i] == '\n') {
              template[i] = 0;
            }
          }
          regex_t rg;
          if (regcomp(&rg, template, flag_num) != 0) {
            errorFlag = true;
            printf("regular expressions compile error\n");
          }
          if (!errorFlag) {
            if (regexec(&rg, str, 0, 0, 0) == 0) {
              if (gr.flagO && !gr.flagL && !gr.flagC) {
                if (gr.flagN && !alreadyPrinted) {
                  printf("%d:", string_counter);
                  alreadyPrinted = true;
                }
                printf("%s\n", template);
              }
              template_match = true;
            }
          }
          regfree(&rg);
        }
      }
    }
    if (!errorFlag &&
        ((gr.flagV && !template_match) || (!gr.flagV && template_match))) {
      one_match = true;
      if (gr.flagC) {
        c_option_counter++;
      } else if (!gr.flagL) {
        if (!gr.flagO) {
          if (several) {
            printf("%s:", argv[filename]);
          }
          if (gr.flagN) {
            printf("%d:", string_counter);
          }
          if (!gr.flagO) {
            for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
              printf("%c", str[i]);
            }
          }
          printf("\n");
        }
      }
    }
  }
  if (!errorFlag) {
    if (gr.flagC) {
      if (several) {
        printf("%s:", argv[filename]);
      }
      if (gr.flagL) {
        printf("%d\n", one_match);
      } else {
        printf("%d\n", c_option_counter);
      }
    }
    if (gr.flagL && one_match) {
      printf("%s\n", argv[filename]);
    }
  }
}
