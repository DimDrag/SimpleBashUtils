grep 5 for_test_1.txt > grep_out.txt
./s21_grep 5 for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="no options"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -i -o -e 51 for_test_1.txt > grep_out.txt
./s21_grep -i -o -e 51 for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-i -o -e 51"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -i -o -e 51 -f for_test_2.txt for_test_1.txt > grep_out.txt
./s21_grep -i -o -e 51 -f for_test_2.txt for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-i -o -e 51 -f for_test_2.txt"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -o -i -c -l -e 1 -e 51 -e f for_test_1.txt > grep_out.txt
./s21_grep -o -i -c -l -e 1 -e 51 -e f for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-o -i -c -l -e 1 -e 51 -e f for_test_1.txt"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -e 1 -e 51 -o -e f -i -c for_test_1.txt > grep_out.txt
./s21_grep -e 1 -e 51 -o -e f -i -c for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-e 1 -e 51 -o -e f -i -c"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -e 1 -e 51 -o -e f -i -l for_test_1.txt > grep_out.txt
./s21_grep -e 1 -e 51 -o -e f -i -l for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-e 1 -e 51 -o -e f -i -l"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -i -o -e 51 -n -f for_test_2.txt for_test_1.txt > grep_out.txt
./s21_grep -i -o -e 51 -n -f for_test_2.txt for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-i -o -e 51 -n -f for_test_2.txt"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

#все те же тесты, только с комбинированными опциями
grep -ioe 51 for_test_1.txt > grep_out.txt
./s21_grep -ioe 51 for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-ioe 51"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -ioe 51 -f for_test_2.txt for_test_1.txt > grep_out.txt
./s21_grep -ioe 51 -f for_test_2.txt for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-ioe 51 -f for_test_2.txt"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -oicle 1 -e 51 -e f for_test_1.txt > grep_out.txt
./s21_grep -oicle 1 -e 51 -e f for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-oicle 1 -e 51 -e f"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -e 1 -e 51 -o -ice f for_test_1.txt > grep_out.txt
./s21_grep -e 1 -e 51 -o -ice f for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-e 1 -e 51 -o -ice f"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -e 1 -e 51 -o -ile f for_test_1.txt > grep_out.txt
./s21_grep -e 1 -e 51 -o -ile f for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-e 1 -e 51 -o -ile f"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -inoe 51 -f for_test_2.txt for_test_1.txt > grep_out.txt
./s21_grep -inoe 51 -f for_test_2.txt for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-inoe 51 -f for_test_2.txt"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -v 5 for_test_2.txt > grep_out.txt
./s21_grep -v 5 for_test_2.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-v 5"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -h 5 for_test_2.txt for_test_1.txt > grep_out.txt
./s21_grep -h 5 for_test_2.txt for_test_1.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-h 5"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi

grep -s -e 5 0.txt > grep_out.txt
./s21_grep -s -e 5 0.txt > s21_grep_out.txt
sm=$(diff grep_out.txt s21_grep_out.txt)
opt="-s -e 5 0.txt"
if [$sm = ""];
    then echo ok $opt
else
    echo $opt $sm
    open *out.txt
    exit
fi