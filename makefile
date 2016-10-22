exe: main.o sudoku.o
	g++ -Wall -g main.o sudoku.o -o exe

main.o: main.cpp sudoku.h
	g++ -Wall -g -c main.cpp

sudoku.o: sudoku.h sudoku.cpp
	g++ -Wall -g -c sudoku.cpp

clean:
	rm -f *.o exe