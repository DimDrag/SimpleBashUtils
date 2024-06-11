all: s21_grep

s21_grep:
	gcc -std=c11 -Wall -Werror -Wextra grep.c grep.h main.c -o s21_grep

test: s21_grep
	chmod +rwx test_grep.sh
	bash test_grep.sh

leaks: s21_grep
	leaks -atExit -- ./s21_grep -e 5 -f for_test_1.txt for_test_2.txt

clean:
	rm -rf *.o
	rm -rf s21_grep

rebuild: clean s21_grep
