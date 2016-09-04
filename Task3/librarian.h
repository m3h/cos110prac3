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

		Book* lendBook(string name);
		void returnBook(Book* book);

		string getName() { return name; };

};
#endif
