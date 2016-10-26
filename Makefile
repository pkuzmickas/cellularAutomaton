CFLAGS = -g -Wall -Wextra –pedantic

build: 
	g++ -std=c++11 menu.cpp CA1DLogic.cpp GameOfLife.cpp -o exe
clean:
	rm -f exe
run:
	./exe
