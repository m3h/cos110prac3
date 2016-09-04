main: main.o library.o book.o librarian.o
	g++ -static main.o book.o library.o librarian.o -o main

main.o: main.cpp
	g++ -c main.cpp

library.o: library.h library.cpp
	g++ -c library.h library.cpp

librarian.o: librarian.h librarian.cpp
	g++ -c librarian.cpp

book.o: book.h book.cpp
	g++ -c book.h book.cpp

run: main
	./main

runs: mains.out
	./mains.out

mainl.out: mainl.cpp book.h book.cpp library.h library.cpp librarian.cpp librarian.h
	g++ -static -g mainl.cpp book.cpp  library.cpp librarian.cpp -o mainl.out

runl: mainl.out
	./mainl.out

mains.out: mains.cpp book.h book.cpp library.h library.cpp
	g++ -static -g mains.cpp book.cpp library.cpp -o mains.out

test.out: main.cpp book.h book.cpp library.h library.cpp
	g++ -static -g main.cpp book.cpp library.cpp -o test.out

debug: test.out
	gdb ./test.out

clean:
	rm -vf ./*.out ./*.o
