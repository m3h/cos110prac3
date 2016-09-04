#include <iostream>
#include <string>

using namespace std;

#include "book.h"

//using namespace std;

int main( int argc, char **argv )
{
	Book hp( "Harry Potter 1", "J.K Rownling", "1234567890" );
	hp.setGenre("gore");
	cout << "Book: " << hp << endl;
	cout << hp.getGenre() << endl;

	hp.setTitle( "HP 2");
	hp.setAuthor( "Joker" );
	hp.setISBN( "0987654321" );
	hp.setGenre( "Horror" );

	cout << endl;
	cout << hp.getTitle() << endl;
	cout << hp.getAuthor() << endl;
	cout << hp.getISBN() << endl;
	cout << hp.getGenre() << endl;

	return 0;
}
