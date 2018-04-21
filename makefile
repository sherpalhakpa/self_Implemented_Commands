new_tail : new_tail.o
	gcc -o new_tail new_tail.o -lm

new_cat : new_cat.o
	gcc -o new_cat new_cat.o -lm

new_echo : new_echo.o
	gcc -o new_echo new_echo.o -lm

new_wc : new_wc.o
	gcc -o new_wc new_wc.o -lm

all : new_tail.o new_cat.o new_echo.o new_wc.o
	gcc -o new_tail new_tail.o -lm
	gcc -o new_cat new_cat.o -lm
	gcc -o new_echo new_echo.o -lm
	gcc -o new_wc new_wc.o -lm

new_tail.o : new_tail.c 
	gcc -O -Wall -c new_tail.c

new_cat.o : new_cat.c
	gcc -O -Wall -c new_cat.c

new_echo.o : new_echo.c
	gcc -O -Wall -c new_echo.c

new_wc.o : new_wc.c
	gcc -O -Wall -c new_wc.c


clean : 
	rm -f new_tail.o new_cat.o new_echo.o new_wc.o new_tail new_cat new_echo new_wc

