main.out: main.o book.o
	g++ main.o book.o -o main.out

main.o: main.cpp
	g++ -c main.cpp

Book.o: book.h book.cpp
	g++ -c book.h book.cpp

run: main.out
	./main.out

clean:
	rm ./*.out ./*.o
