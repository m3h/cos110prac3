#include "book.h"

using namespace std;

Book::Book( string titleIn, string authorIn, string ISBNIn )
{
	title = titleIn;
	author = authorIn;
	ISBN = ISBNIn;
}


ostream &operator << (ostream &strm, const Book &obj)
{
	strm << obj.title << " - " << obj.author << " - " << obj.ISBN;

	return strm;
}
