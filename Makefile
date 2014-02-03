CSTUFF=gcc -O2 -Wall $(DEBUG)
#LFLAGS= -lm -lGLEW -lXi -lGL -lX11 -lXxf86vm -pthread -lXrandr
LFLAGS=-lm -lSDL2 -lGL -lImlib2

.PHONY: clean remake debug

run: main.o
	$(CSTUFF) main.o $(LFLAGS) -o run

main.o: main.c Makefile
	$(CSTUFF) -c main.c

clean:
	rm -f *.o run

remake:
	$(MAKE) clean
	$(MAKE)

debug:
	$(MAKE) DEBUG=-g
