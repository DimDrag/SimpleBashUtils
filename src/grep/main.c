#include "grep.h"
int main(int argc, char* argv[]) {
  GrepOptions gr;
  initGrepOptions(&gr);
  bool stopOptionsFlag = false;
  bool errorFlag = false;
  // находим опции в параметрах
  int i;
  for (i = 1; !errorFlag && !stopOptionsFlag && argc > 1 && i < argc; i++) {
    bool this_is_option = false;
    // локальные опции
    bool flagE = false;
    bool flagI = false;
    bool flagV = false;
    bool flagC = false;
    bool flagL = false;
    bool flagN = false;
    bool flagH = false;
    bool flagS = false;
    bool flagF = false;
    bool flagO = false;
    if (argv[i][0] == '-') {
      this_is_option = true;
      for (int j = 1; errorFlag == false && argv[i][j] != '\0'; j++) {
        if (argv[i][j] == 'e') {
          flagE = true;
        } else if (argv[i][j] == 'i') {
          flagI = true;
        } else if (argv[i][j] == 'v') {
          flagV = true;
        } else if (argv[i][j] == 'c') {
          flagC = true;
        } else if (argv[i][j] == 'l') {
          flagL = true;
        } else if (argv[i][j] == 'n') {
          flagN = true;
        } else if (argv[i][j] == 'h') {
          flagH = true;
        } else if (argv[i][j] == 's') {
          flagS = true;
        } else if (argv[i][j] == 'f') {
          flagF = true;
        } else if (argv[i][j] == 'o') {
          flagO = true;
        } else {
          errorFlag = true;
          printf("illegal option -- %c\n", argv[i][j]);
        }
      }
    }
    if (flagF || flagE) {
      if (flagF && flagE) {
        printf("option error\n");
      } else if (flagF) {
        addFileName(&gr, ++i);
      } else if (flagE) {
        addTemplate(&gr, ++i);
      }
    } else if (!this_is_option) {
      stopOptionsFlag = true;
      i--;
    }
    gr.flagE = (gr.flagE + flagE) % 2;
    gr.flagI = (gr.flagI + flagI) % 2;
    gr.flagV = (gr.flagV + flagV) % 2;
    gr.flagC = (gr.flagC + flagC) % 2;
    gr.flagL = (gr.flagL + flagL) % 2;
    gr.flagN = (gr.flagN + flagN) % 2;
    gr.flagH = (gr.flagH + flagH) % 2;
    gr.flagS = (gr.flagS + flagS) % 2;
    gr.flagF = (gr.flagF + flagF) % 2;
    gr.flagO = (gr.flagO + flagO) % 2;
  }
  // если не было опции -е, берём шаблон из аргументов напрямую
  if (!gr.flagE && !gr.flagF) {
    addTemplate(&gr, i++);
  }
  // флаг означающий что поиск будет происходить по нескольким файлам
  bool several = false;
  if (argc - i > 1) {
    several = true;
  }
  // находим названия файлов в параметрах
  for (; errorFlag == false && argc > 1 && i < argc; i++) {
    // если параметр не является опцией
    FILE* f = fopen(argv[i], "r");
    if (f != NULL) {
      search(f, gr, several, argv, i);
    } else {
      if (!gr.flagS) {
        printf("no such file - %s\n", argv[i]);
      }
    }
    fclose(f);
  }
  destruct(&gr);
  return 0;
}
