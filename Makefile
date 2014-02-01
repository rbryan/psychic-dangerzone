CSTUFF=gcc -O2 -Wall $(DEBUG)
LFLAGS= -lm -lglfw -lGLEW -lXi -lGL -lX11 -lXxf86vm -pthread -lXrandr

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
