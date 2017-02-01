# Makefile

all: houseofpizza houseoftires

houseofpizza: houseofpizza.c mathhelper.c mathhelper.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o houseofpizza houseofpizza.c mathhelper.c -lcs50 -lm

houseoftires: houseoftires.c mathhelper.c mathhelper.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o houseoftires houseoftires.c mathhelper.c -lcs50 -lm 

clean:
	rm -f *.o a.out core pizza tires