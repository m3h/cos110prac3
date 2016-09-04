#include <iostream>
#include <string>

using namespace std;

#include "librarian.h"
#include "book.h"
#include "library.h"

int main( int argc, char **argv)
{

	Library hello("Balc");
	Book* book1 = new Book("InkSpell" ,"Cornelia Funke" ," 97804396412");


	Librarian mary(hello, "Mary");
	delete book1;

	return 0;
}
