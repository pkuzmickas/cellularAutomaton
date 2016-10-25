#James Strachan
#150008551
#AC21008

#CC = gcc
CFLAGS = -g -Wall -Wextra –pedantic -I.

build: 
	g++ menu.cpp CA1DLogic.cpp -o exe
clean:
	rm -f exe
run:
	./exe
