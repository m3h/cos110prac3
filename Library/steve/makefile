book.o: book.h book.cpp
	g++ -std=c++11 -static -c book.h book.cpp
	
library.o: book.o library.h library.cpp 
	g++ -std=c++11 -static -c book.o library.h library.cpp
		
main: book.o library.o main.cpp
	g++ -std=c++11 -static book.o library.o main.cpp -o main
	
run: main
	./main