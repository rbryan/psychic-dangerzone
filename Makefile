CSTUFF=gcc -O2 -Wall $(DEBUG)

.PHONY: clean remake debug

run: main.o
	$(CSTUFF) main.o -lglfw -o run

main.o: main.c
	$(CSTUFF) -c main.c

clean:
	rm -f *.o run

remake:
	$(MAKE) clean
	$(MAKE)

debug:
	$(MAKE) DEBUG=-g
