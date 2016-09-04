#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>


using namespace std;

#include "book.h"

class Library {
private:
  string name;
  Book **books;
  int librarySize;
  int numBooks;

public:
  Library( string nameIn = "Library" );
  Library( const Library &obj );

  ~Library();
  Library operator += ( Book *obj );
  Library operator -= ( Book *obj );
  Library operator = ( const Library &obj );
  Library operator ++ (int);
  Library operator -- ();

  Book *getBook( string titleIn );
  Book *getBook( int index );
  bool isFull();
  void print();

  string getName() const { return name; }
  void setName( string nameIn ) { name = nameIn; }

  int getLibrarySize() const { return librarySize; }
  //void setLibrarySize( int newLibrarySize ) { librarySize = newLibrarySize }

  int getNumBooks() const { return numBooks; }

};

#endif
