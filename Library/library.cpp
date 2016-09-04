#include "library.h"
#include "book.h"

#include <iostream>

using namespace std;

Library::Library( string nameIn  )
{
  name = nameIn;
  librarySize = 5;
  numBooks = 0;

  books = new Book* [librarySize];
}

Library::Library( const Library &obj )
{
  name = obj.getName();
  librarySize = obj.getLibrarySize();
  numBooks = obj.getNumBooks();

  books = new Book* [librarySize];
  for( int i = 0; i < numBooks; ++i ) {
    //Book *temp = new Book;

    //temp = getBook( i );

	//Book steve = *temp;

    //books[i] = temp;
	books[i] = obj.books[i];
  }

}

Library::~Library()
{
  for(int i = 0; i < numBooks; ++i ) {
	//delete books[i];
  }
  delete [] books;
}

Library Library::operator += ( Book *obj )
{
  if( librarySize == numBooks ) {
    cout << "Library is full!" << endl;
    return *this;
  }

  ++numBooks;
  //Book *temp = new Book();
  //*temp = obj;

  books[numBooks-1] = obj;

  return *this;
}

Library Library::operator -= ( Book *obj )
{
  if( numBooks < 1 ) {
    return *this;
  }

  int index = -1;
  for(int i = 0; i < numBooks; ++i) {
    if( books[i]->getISBN() == obj->getISBN() ) {
      index = i;
      break;
    }
  }

  if( index == -1 )
    return *this;

  //delete books[index];

  for(int i = index; i < numBooks; ++i) {
    books[i] = books[i+1];
  }

  --numBooks;

  return *this;

}

Library Library::operator = ( const Library &obj )
{
  if( &obj == this ) return *this;

  for( int i = 0; i < numBooks; ++i ) {
    //delete books[i];
  }
  delete [] books;

  name = obj.getName();
  librarySize = obj.getLibrarySize();
  numBooks = obj.getNumBooks();

  books = new Book* [librarySize];
  for( int i = 0; i < numBooks; ++i ) {
    //Book *temp = new Book;
    //*temp = *(getBook( i ));
    books[i] = obj.getBook( i );
  }
    return *this;
}

Library Library::operator++ (int) // post-decrement
{
  Library temp( *this );

  // shallow copy of array to tempBooks
  //Book **tempBooks;
  //tempBooks = new Book* [numBooks];
  Book *tempBooks[numBooks];

  for(int i = 0; i < numBooks; ++i ) {
    tempBooks[i] = books[i];
  }
  delete [] books;

  // allocate books with larger librarySize and assign from tempBooks
  books = new Book* [++librarySize];
  for(int i = 0; i < numBooks; ++i) {
    books[i] = tempBooks[i];
  }

  //delete [] tempBooks;

  return temp;
}

Library Library::operator -- ()
{
  // delete last book
  if( librarySize == numBooks ) {
    //cout << "Descreasing " << numBooks << endl;
    //delete books[numBooks - 1];
    --numBooks;
  }

  --librarySize;

  // shallow copy of array to tempBooks
  Book **tempBooks;
  tempBooks = new Book* [numBooks];
  for(int i = 0; i < numBooks; ++i ) {
    tempBooks[i] = books[i];
  }
  delete [] books;

  // allocate books with smaller librarySize and assign from tempBooks
  books = new Book* [librarySize];
  for(int i = 0; i < numBooks; ++i) {
    books[i] = tempBooks[i];
  }

  delete [] tempBooks;

  return *this;
}

Book *Library::getBook ( string titleIn ) const
{
  for(int i = 0; i < numBooks; ++i) {
    if( books[i]->getTitle() == titleIn ) {
      //cout << "FOUNDS MY PRECCIOUS" << endl;
      return getBook( i );
    }
  }
  //cout << "DIDN't FIND" << endl;
  return NULL;
}

Book *Library::getBook( int index ) const
{
  return books[index];
}

bool Library::isFull()
{
  if( numBooks == librarySize )
    return true;
  else
    return false;
}


#define LINER35 "==================================="
#define LINER34 "=================================="

void Library::print()
{
  cout << "Inventory of " << name << ":" << endl;


  if( numBooks == 0 ) {
    cout << "===================================" << endl;
    cout << "EMPTY" << endl;
    cout << LINER << endl;
  } else {
    cout << LINER << endl;
    // print Books
    for(int i = 0; i < numBooks; ++i) {
      //Book temp = *(books[i]);
	  //cout << books[i] << endl;
      cout << i+1 << ". " << *(books[i]) << endl;
    }

    // print empty spaces
    for(int i = numBooks; i < librarySize; ++i) {
      cout << i+1 << ". " << "[Empty Space]" << endl;
    }
    cout << LINER << endl;
  }

}
