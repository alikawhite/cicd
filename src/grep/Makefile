FLAGS = -Wall -Werror -Wextra

OS = $(shell uname)
ifeq ($(OS), Darwin) # MAC
LEAK_CHECK = leaks -q --atExit -- ./s21_grep
endif

ifeq ($(OS), Linux) # LINUX
LEAK_CHECK = valgrind -q --trace-children=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./s21_grep
endif


all: s21_grep

s21_grep: clean
	gcc -c $(FLAGS) s21_grep.c
	gcc -o s21_grep *.o
	# make clean
	rm -rf *.o *grep.txt
	touch grep.txt s21_grep.txt

# build & run test
test: s21_grep
	
	# ./s21_grep werty
	# ./s21_grep werty qweqwertyu

	# ./s21_grep > s21_grep.txt
	# grep > grep.txt
	# diff grep.txt s21_grep.txt

	# ./s21_grep "[q-s][a-z]" t*.txt > s21_grep.txt
	# grep "[q-s][a-z]" t*.txt > grep.txt
	# diff grep.txt s21_grep.txt

	./s21_grep "qwer" text.txt txt2.txt > s21_grep.txt
	grep "qwer" text.txt txt2.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep "qwer" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep "qwer" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep "qwer" text.txt > s21_grep.txt
	grep "qwer" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep "wer" txt1.txt > s21_grep.txt
	grep "wer" txt1.txt > grep.txt
	diff grep.txt s21_grep.txt

	# ./s21_grep -e "[q-s][a-z]" t*.txt > s21_grep.txt
	# grep -e "[q-s][a-z]" t*.txt > grep.txt
	# diff grep.txt s21_grep.txt

	./s21_grep -e "qwer" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -e "qwer" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -e "qwer" text.txt > s21_grep.txt
	grep -e "qwer" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	# ./s21_grep -i "[q-s][a-z]" t*.txt > s21_grep.txt
	# grep -i "[q-s][a-z]" t*.txt > grep.txt
	# diff grep.txt s21_grep.txt

	./s21_grep -i "qwer" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -i "qwer" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -i "qwer" text.txt > s21_grep.txt
	grep -i "qwer" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	# ./s21_grep -v "[q-s][a-z]" t*.txt > s21_grep.txt
	# grep -v "[q-s][a-z]" t*.txt > grep.txt
	# diff grep.txt s21_grep.txt

	./s21_grep -v "qwer" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -v "qwer" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -v "qwer" text.txt > s21_grep.txt
	grep -v "qwer" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	# ./s21_grep -c "[q-s][a-z]" t*.txt > s21_grep.txt
	# grep -c "[q-s][a-z]" t*.txt > grep.txt
	# diff grep.txt s21_grep.txt

	./s21_grep -c "qwer" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -c "qwer" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -c "qwer" text.txt > s21_grep.txt
	grep -c "qwer" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	# ./s21_grep -l "[q-s][a-z]" t*.txt > s21_grep.txt
	# grep -l "[q-s][a-z]" t*.txt > grep.txt
	# diff grep.txt s21_grep.txt

	./s21_grep -l "qwer" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -l "qwer" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -l "qwer" text.txt > s21_grep.txt
	grep -l "qwer" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	# ./s21_grep -n "[q-s][a-z]" t*.txt > s21_grep.txt
	# grep -n "[q-s][a-z]" t*.txt > grep.txt
	# diff grep.txt s21_grep.txt

	./s21_grep -n "qwer" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -n "qwer" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -n "qwer" text.txt > s21_grep.txt
	grep -n "qwer" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	# ./s21_grep "[q-s][a-z]erty" t*.txt > s21_grep.txt
	# grep "[q-s][a-z]erty" t*.txt > grep.txt
	# diff grep.txt s21_grep.txt

	./s21_grep "qweR" text.txt txt2.txt > s21_grep.txt
	grep "qweR" text.txt txt2.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep "qweR" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep "qweR" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep "qweR" text.txt > s21_grep.txt
	grep "qweR" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep "weR" txt1.txt > s21_grep.txt
	grep "weR" txt1.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -e "qweR" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -e "qweR" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -e "qweR" text.txt > s21_grep.txt
	grep -e "qweR" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -i "qweR" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -i "qweR" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -i "qweR" text.txt > s21_grep.txt
	grep -i "qweR" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -v "qweR" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -v "qweR" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -v "qweR" text.txt > s21_grep.txt
	grep -v "qweR" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -c "qweR" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -c "qweR" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -c "qweR" text.txt > s21_grep.txt
	grep -c "qweR" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -l "qweR" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -l "qweR" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -l "qweR" text.txt > s21_grep.txt
	grep -l "qweR" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -n "qweR" text.txt txt2.txt txt3.txt txt3.txt > s21_grep.txt
	grep -n "qweR" text.txt txt2.txt txt3.txt txt3.txt > grep.txt
	diff grep.txt s21_grep.txt

	./s21_grep -n "qweR" text.txt > s21_grep.txt
	grep -n "qweR" text.txt > grep.txt
	diff grep.txt s21_grep.txt

	rm -rf *.o *grep.txt
	touch grep.txt s21_grep.txt

# test1:
# 	gcc -c $(FLAGS) s21_grep.c
# 	gcc -o s21_grep *.o $(LIBS)
# 	./s21_grep text.txt > s21_grep.txt
# 	grep text.txt > grep.txt
# 	def s21_grep.txt grep.txt

# standart
CFILES = *.c
	
check: clean
	gcc -c $(FLAGS) s21_grep.c
	gcc -o s21_grep *.o
	$(LEAK_CHECK) * t*.txt > s21_grep.txt
	$(LEAK_CHECK) -e * t*.txt > s21_grep.txt
	$(LEAK_CHECK) -i * t*.txt > s21_grep.txt
	$(LEAK_CHECK) -v "qw" te*.txt > s21_grep.txt
	$(LEAK_CHECK) -c * t*.txt > s21_grep.txt
	$(LEAK_CHECK) -l * t*.txt > s21_grep.txt
	$(LEAK_CHECK) -n * t*.txt > s21_grep.txt
	cppcheck --check-config --enable=all --suppress=missingIncludeSystem $(CFILES)
	# cp ../materials/linters/CPPLINT.cfg .
	rm -rf *.o s21_grep.txt
	touch s21_grep.txt

style:
	python3 ../../materials/linters/cpplint.py --extension=c $(CFILES)

clean:
	rm -rf *.o *grep.txt
	touch grep.txt s21_grep.txt
	# :> grep.txt
	# :> s21_grep.txt

clean1:
	rm -rf s21_grep
