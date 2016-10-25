#James Strachan
#150008551
#AC21008

#CC = gcc
CFLAGS = -g -Wall -Wextra –pedantic -I.

build: 
	g++ menu.cpp -o menu
clean:
	rm -f menu
run:
	./menu