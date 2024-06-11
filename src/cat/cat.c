#include "cat.h"
void printS(FILE *f) {
  bool empty_strings_start = false;
  char prev = -1;
  for (char cur = fgetc(f); cur != EOF; cur = fgetc(f)) {
    if (cur != EOF) {
      if (cur == prev && prev == '\n') {
        empty_strings_start = true;
      }
      if (cur != '\n') {
        if (prev == '\n') {
          if (empty_strings_start) {
            empty_strings_start = false;
            printf("\n\n");
          } else {
            printf("\n");
          }
        }
        printf("%c", cur);
      }
      prev = cur;
    }
  }

  if (empty_strings_start) {
    printf("\n");
  }
}

void printB(FILE *f) {
  char cur = fgetc(f);
  if (cur != EOF) {
    int cur_str_num = 1;
    if (cur != '\n') {
      printf("%6d\t%c", cur_str_num++, cur);
    }
    char prev = cur;
    for (cur = fgetc(f); cur != EOF; cur = fgetc(f)) {
      if (prev == '\n') {
        if (cur != '\n') {
          printf("%6d\t%c", cur_str_num++, cur);
        } else {
          printf("%c", cur);
        }
      } else {
        printf("%c", cur);
      }
      prev = cur;
    }
  }
}
void printN(FILE *f) {
  int cur_str_num = 1;
  bool first = true;
  for (char cur = fgetc(f); cur != EOF; cur = fgetc(f)) {
    if (cur != EOF) {
      if (first || cur == '\n') {
        if (first) {
          printf("%6d\t%c", cur_str_num, cur);
        } else {
          printf("\n%6d\t", cur_str_num);
        }
        cur_str_num++;
      } else {
        printf("%c", cur);
      }
      first = false;
    }
  }
}
void printE(FILE *f, bool big) {
  for (char cur = fgetc(f); cur != EOF; cur = fgetc(f)) {
    if (cur != EOF) {
      if (cur == '\n') {
        printf("$\n");
      } else if (cur == '\t') {
        printf("\t");
      } else if (!big) {
        if ((int)cur < 32) {
          printf("^%c", (char)((int)cur + 64));
        } else if ((int)cur == 127) {
          printf("^?");
        } else {
          printf("%c", cur);
        }
      }
    }
  }
}
void printT(FILE *f, bool big) {
  for (char cur = fgetc(f); cur != EOF; cur = fgetc(f)) {
    if (cur != EOF) {
      if (cur == '\t') {
        printf("^I");
      } else if (cur == '\n') {
        printf("\n");
      } else if (!big) {
        if ((int)cur < 32) {
          printf("^%c", (char)((int)cur + 64));
        } else if ((int)cur == 127) {
          printf("^?");
        } else {
          printf("%c", cur);
        }
      }
    }
  }
}
void print(FILE *f) {
  for (char cur = fgetc(f); cur != EOF; cur = fgetc(f)) {
    if (cur != EOF) {
      printf("%c", cur);
    }
  }
}
