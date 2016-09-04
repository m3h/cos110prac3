#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <iostream>
#include <string>

using namespace std;

#include "library.h"

class Librarian {
	private:
		Library &lib;
		const string name;

	public:
		Librarian( Library &libIn, string nameIn = "Librarian" ): lib(libIn), name( nameIn ) { }
		Librarian( string nameIn , Library &libIn ): lib(libIn), name( nameIn ) { }


		Book* lendBook(string bname)
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

		void returnBook(Book* book)
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


		string getName() { return name; }

};
#endif
