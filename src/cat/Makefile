FLAGS = -std=c11 -Wall -Werror -Wextra

OS = $(shell uname)
ifeq ($(OS), Darwin) # MAC
LEAK_CHECK = leaks -q --atExit -- ./s21_cat *.txt > s21_cat.txt
endif

ifeq ($(OS), Linux) # LINUX
LEAK_CHECK = valgrind -q --trace-children=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./s21_cat *.txt > s21_cat.txt
endif


all: s21_cat

s21_cat: clean
	gcc -c $(FLAGS) s21_cat.c
	gcc -o s21_cat *.o
	# make clean
	rm -rf *.o *cat.txt
	touch cat.txt s21_cat.txt

test: s21_cat
	# ./s21_cat werty
	# ./s21_cat werty qweqwertyu

	./s21_cat txt.txt > s21_cat.txt
	cat txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat txt2.txt > s21_cat.txt
	cat txt2.txt > cat.txt
	diff cat.txt s21_cat.txt
	
	./s21_cat txt3.txt > s21_cat.txt
	cat txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat txt2.txt txt3.txt > s21_cat.txt
	cat txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat t*.txt > s21_cat.txt
	cat t*.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat text.txt > s21_cat.txt
	cat text.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat txt.txt > s21_cat.txt
	cat txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat txt1.txt > s21_cat.txt
	cat txt1.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -b text.txt > s21_cat.txt
	cat -b text.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -b txt.txt > s21_cat.txt
	cat -b txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -b txt2.txt > s21_cat.txt
	cat -b txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -b txt3.txt > s21_cat.txt
	cat -b txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -b txt2.txt txt3.txt > s21_cat.txt
	cat -b txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -b txt1.txt > s21_cat.txt
	cat -b txt1.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -e text.txt > s21_cat.txt
	cat -e text.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -e txt.txt > s21_cat.txt
	cat -e txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -e txt2.txt > s21_cat.txt
	cat -e txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -e txt3.txt > s21_cat.txt
	cat -e txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -e txt2.txt txt3.txt > s21_cat.txt
	cat -e txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -e txt1.txt > s21_cat.txt
	cat -e txt1.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -n text.txt > s21_cat.txt
	cat -n text.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -n txt.txt > s21_cat.txt
	cat -n txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -n txt2.txt > s21_cat.txt
	cat -n txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -n txt3.txt > s21_cat.txt
	cat -n txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -n txt2.txt txt3.txt > s21_cat.txt
	cat -n txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -n txt1.txt > s21_cat.txt
	cat -n txt1.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -s text.txt > s21_cat.txt
	cat -s text.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -s txt.txt > s21_cat.txt
	cat -s txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -s txt2.txt > s21_cat.txt
	cat -s txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -s txt3.txt > s21_cat.txt
	cat -s txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -s txt2.txt txt3.txt > s21_cat.txt
	cat -s txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -s txt1.txt > s21_cat.txt
	cat -s txt1.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -t text.txt > s21_cat.txt
	cat -t text.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -t txt.txt > s21_cat.txt
	cat -t txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -t txt2.txt > s21_cat.txt
	cat -t txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -t txt3.txt > s21_cat.txt
	cat -t txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -t txt2.txt txt3.txt > s21_cat.txt
	cat -t txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -t txt1.txt > s21_cat.txt
	cat -t txt1.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -b text.txt > s21_cat.txt
	cat -b text.txt > cat.txt
	diff cat.txt s21_cat.txt

ifeq ($(OS), Darvin)
	./s21_cat -v txt.txt > s21_cat.txt
	cat -v txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -v txt2.txt > s21_cat.txt
	cat -v txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -v txt3.txt > s21_cat.txt
	cat -v txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -v txt2.txt txt3.txt > s21_cat.txt
	cat -v txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -v txt1.txt > s21_cat.txt
	cat -v txt1.txt > cat.txt
	diff cat.txt s21_cat.txt
endif

	./s21_cat text.txt txt2.txt > s21_cat.txt
	cat text.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat text.txt txt2.txt txt2.txt > s21_cat.txt
	cat text.txt txt2.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -b text.txt txt2.txt txt2.txt > s21_cat.txt
	cat -b text.txt txt2.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -e text.txt txt2.txt txt2.txt > s21_cat.txt
	cat -e text.txt txt2.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -n text.txt txt2.txt txt2.txt > s21_cat.txt
	cat -n text.txt txt2.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -s text.txt txt2.txt txt2.txt > s21_cat.txt
	cat -s text.txt txt2.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -t text.txt txt2.txt txt2.txt > s21_cat.txt
	cat -t text.txt txt2.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

ifeq ($(OS), Linux)
	./s21_cat -E text.txt > s21_cat.txt
	cat -E text.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -E txt.txt > s21_cat.txt
	cat -E txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -E txt1.txt > s21_cat.txt
	cat -E txt1.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -T text.txt > s21_cat.txt
	cat -T text.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -T txt.txt > s21_cat.txt
	cat -T txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -T txt1.txt > s21_cat.txt
	cat -T txt1.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number-nonblank text.txt > s21_cat.txt
	cat --number-nonblank text.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number-nonblank txt.txt > s21_cat.txt
	cat --number-nonblank txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number-nonblank txt1.txt > s21_cat.txt
	cat --number-nonblank txt1.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -E text.txt txt2.txt txt2.txt > s21_cat.txt
	cat -E text.txt txt2.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -T text.txt txt2.txt txt2.txt > s21_cat.txt
	cat -T text.txt txt2.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number-nonblank text.txt txt2.txt txt2.txt > s21_cat.txt
	cat --number-nonblank text.txt txt2.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt
	
	./s21_cat --number text.txt > s21_cat.txt
	cat --number text.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number txt.txt > s21_cat.txt
	cat --number txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number txt1.txt > s21_cat.txt
	cat --number txt1.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number text.txt txt2.txt txt2.txt > s21_cat.txt
	cat --number text.txt txt2.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --squeeze-blank text.txt > s21_cat.txt
	cat --squeeze-blank text.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --squeeze-blank txt.txt > s21_cat.txt
	cat --squeeze-blank txt.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --squeeze-blank txt1.txt > s21_cat.txt
	cat --squeeze-blank txt1.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --squeeze-blank text.txt txt2.txt txt2.txt > s21_cat.txt
	cat --squeeze-blank text.txt txt2.txt txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -E txt2.txt > s21_cat.txt
	cat -E txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -E txt3.txt > s21_cat.txt
	cat -E txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -E txt2.txt txt3.txt > s21_cat.txt
	cat -E txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -T txt2.txt > s21_cat.txt
	cat -T txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -T txt3.txt > s21_cat.txt
	cat -T txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat -T txt2.txt txt3.txt > s21_cat.txt
	cat -T txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number-nonblank txt2.txt > s21_cat.txt
	cat --number-nonblank txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number-nonblank txt3.txt > s21_cat.txt
	cat --number-nonblank txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number-nonblank txt2.txt txt3.txt > s21_cat.txt
	cat --number-nonblank txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number txt2.txt > s21_cat.txt
	cat --number txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number txt3.txt > s21_cat.txt
	cat --number txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --number txt2.txt txt3.txt > s21_cat.txt
	cat --number txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --squeeze-blank txt2.txt > s21_cat.txt
	cat --squeeze-blank txt2.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --squeeze-blank txt3.txt > s21_cat.txt
	cat --squeeze-blank txt3.txt > cat.txt
	diff cat.txt s21_cat.txt

	./s21_cat --squeeze-blank txt2.txt txt3.txt > s21_cat.txt
	cat --squeeze-blank txt2.txt txt3.txt > cat.txt
	diff cat.txt s21_cat.txt
endif
	rm -rf *.o *cat.txt
	touch cat.txt s21_cat.txt

CFILES = *.c
	
check: clean clean1
	gcc -c $(FLAGS) s21_cat.c
	gcc -o s21_cat *.o $(LIBS)
	$(LEAK_CHECK)
	cppcheck --check-config --enable=all --suppress=missingIncludeSystem $(CFILES)
	# cp ../materials/linters/CPPLINT.cfg .
	rm -rf *.o s21_cat.txt
	touch s21_cat.txt

style:
	python3 ../../materials/linters/cpplint.py --extension=c $(CFILES)

clean:
	rm -rf *.o *cat.txt
	touch cat.txt s21_cat.txt

clean1:
	rm -rf s21_cat
