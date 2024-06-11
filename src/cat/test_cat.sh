for opt in b e n s t
do
    cat -$opt for_test_1.txt for_test_2.txt > cat_out.txt
    ./s21_cat -$opt for_test_1.txt for_test_2.txt > s21_cat_out.txt
    sm=$(diff cat_out.txt s21_cat_out.txt)
    if [$sm = ""];
        then echo $opt ok
    else
        echo $opt $sm
        open *out.txt
        exit
    fi
done
#--number-nonblank
opt=-number-nonblank
cat -b for_test_1.txt for_test_2.txt > cat_out.txt
./s21_cat -$opt for_test_1.txt for_test_2.txt > s21_cat_out.txt
sm=$(diff cat_out.txt s21_cat_out.txt)
if [$sm = ""];
    then echo $opt ok
else
    echo $opt $sm
    open *out.txt
    exit
fi
#--number
opt=-number
cat -n for_test_1.txt for_test_2.txt > cat_out.txt
./s21_cat -$opt for_test_1.txt for_test_2.txt > s21_cat_out.txt
sm=$(diff cat_out.txt s21_cat_out.txt)
if [$sm = ""];
    then echo $opt ok
else
    echo $opt $sm
    open *out.txt
    exit
fi
#--squeeze-blank
opt=-squeeze-blank
cat -s for_test_1.txt for_test_2.txt > cat_out.txt
./s21_cat -$opt for_test_1.txt for_test_2.txt > s21_cat_out.txt
sm=$(diff cat_out.txt s21_cat_out.txt)
if [$sm = ""];
    then echo $opt ok
else
    echo $opt $sm
    open *out.txt
    exit
fi
