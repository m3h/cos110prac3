#include "librarian.h"

Book* Librarian::lendBook( string bname )
{
	Book* lent;

	lent = lib.getBook( bname );

	if( lent == NULL ) {
		cout << name << ": Sorry, we don't have that book!" << endl;
	} else {
		cout << name << ": Here is the " << lent->getTitle() << ", we hope you enjoy it!" << endl;
		lib -= lent;
	}

	return lent;
}

void Librarian::returnBook(Book *book)
{
	if( book == NULL ) {
		cout << "Error: returning NULL book" << endl;
		return;
	}

	if( lib.isFull() ) {
		lib++;
	}

	lib += book;

	cout << name  << ": Thanks for returning " << book->getTitle() << "!" << endl;

	return;
}
