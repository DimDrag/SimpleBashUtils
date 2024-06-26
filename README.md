# SimpleBashUtils

This is my implementation of cat and grep utilities

## Introduction

### cat Usage

`cat [OPTION] [FILE]...`

### cat Options

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | numbers only non-empty lines |
| 2 | -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $  |
| 3 | -n (GNU: --number) | number all output lines |
| 4 | -s (GNU: --squeeze-blank) | squeeze multiple adjacent blank lines |
| 5 | -t implies -v (GNU: -T the same, but without implying -v) | but also display tabs as ^I  |

### grep Usage

`grep [options] template [file_name]`

### grep Options

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -e | pattern |
| 2 | -i | Ignore uppercase vs. lowercase  |
| 3 | -v | Invert match |
| 4 | -c | Output count of matching lines only |
| 5 | -l | Output matching files only  |
| 6 | -n | Precede each matching line with a line number |
| 7 | -h | Output matching lines without preceding them by file names |
| 8 | -s | Suppress error messages about nonexistent or unreadable files |
| 9 | -f file | Take regexes from a file |
| 10 | -o | Output the matched parts of a matching line |


## More info

- Both programs are developed in C language of C11 standard using gcc compiler
- Program code follows Google style
- Grep supports flag pair combinations
- Input via stdin is not supported