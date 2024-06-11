#include "cat.h"
int main(int argc, char *argv[]) {
  // все возможные опции
  bool flagB = false;
  bool flagE = false;
  bool bigE = false;
  bool flagN = false;
  bool flagS = false;
  bool flagT = false;
  bool bigT = false;

  bool errorFlag = false;  // флаг ошибки
  int i = 2;
  // находим опции в параметрах
  if (!strcmp(argv[1], "-b") || !strcmp(argv[1], "--number-nonblank")) {
    flagB = true;
  } else if (!strcmp(argv[1], "-e")) {
    flagE = true;
  } else if (!strcmp(argv[1], "-E")) {
    flagE = true;
    bigE = true;
  } else if (!strcmp(argv[1], "-n") || !strcmp(argv[1], "--number")) {
    flagN = true;
  } else if (!strcmp(argv[1], "-s") || !strcmp(argv[1], "--squeeze-blank")) {
    flagS = true;
  } else if (!strcmp(argv[1], "-t")) {
    flagT = true;
  } else if (!strcmp(argv[1], "-T")) {
    flagT = true;
    bigT = true;
  } else if (argv[1][0] == '-') {
    errorFlag = true;
    printf("illegal option -- %s\n", argv[i]);
  } else {
    i = 1;
  }
  // находим названия файлов в параметрах
  for (; errorFlag == false && argc > 1 && i < argc; i++) {
    // если параметр не является опцией
    FILE *f = fopen(argv[i], "r");
    if (f != NULL) {
      if (flagB) {
        printB(f);
      } else if (flagE) {
        printE(f, bigE);
      } else if (flagN) {
        printN(f);
      } else if (flagS) {
        printS(f);
      } else if (flagT) {
        printT(f, bigT);
      } else {
        print(f);
      }
    } else {
      printf("\nno such file - %s\n", argv[i]);
    }
    fclose(f);
  }
  return 0;
}
