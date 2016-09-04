#ifndef LIBRARY_H
#define LIBRARY_H

#include"book.h"

class Library{
	private:
		string name;
		Book** books;
		int librarySize;
		int numBooks;
	public:
		//constructors(copy and parameter based) also destructor.
		Library(string fabbby = "Fabulous");
		Library(const Library &obj);
	//	~Library();

		//array of books functions.
		Book* getBook(string);
		bool isFull();
		void print();

		//overloaded operator functions.
		Library &operator +=(Book *a);
		Library &operator -=(Book *a);
		void operator =(const Library &obj);
		Library operator++(int);
		Library operator--();

		//accessors and mutators.
		string getName();
		int getLibrarySize();
		int getNumBooks();
		void setName(string);
		void setLibrarySize(int);
		void setNumBooks(int);
};

#endif
