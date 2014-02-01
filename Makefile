CSTUFF=gcc -O2 -Wall $(DEBUG)
LFLAGS= -lm -lglfw3

.PHONY: clean remake debug

run: main.o
	$(CSTUFF) main.o -lglfw -o run

main.o: main.c Makefile
	$(CSTUFF) -c main.c

clean:
	rm -f *.o run

remake:
	$(MAKE) clean
	$(MAKE)

debug:
	$(MAKE) DEBUG=-g
