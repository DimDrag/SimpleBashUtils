all: s21_cat

s21_cat:
	gcc -std=c11 -Wall -Werror -Wextra cat.c cat.h main.c -o s21_cat

test: s21_cat
	chmod +rwx test_cat.sh
	bash test_cat.sh

clean:
	rm -rf *.o
	rm -rf s21_cat

rebuild: clean s21_cat
