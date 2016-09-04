#include <iostream>
#include <string>

using namespace std;

#include "library.h"
#include "book.h"
#include "librarian.h"

int main( int argc, char **argv )
{
  Library t("Texas");
  Library b( t );
  b.setName("Balclutha");

  Library* testit = new Library [10];
  Library test("ttt111");
  for(int i = 0; i < 10; ++i) {
	  testit[i] = test;
  }
  delete [] testit;

  Book *newa = new Book("New book", "John", "122223" );
  Book *hp = new Book( "Harry Potter 1", "J.K Rownling", "1234567890" );

  cout << "Constructing tilly and Mary Librarians" << endl;
  Librarian tilly( t, "Tilly");
  Librarian Mary( b, "Fakka" );

  cout << "Returning harry potter to Tilly" << endl;
  tilly.returnBook( hp );

  cout << "tilly: Lending Confucious to cf ( should fail)" << endl;
  Book *cf = tilly.lendBook( "Confucious" );

  cout << "tilly;:Lending HP1 to cf (shoudl work)" << endl;
  cf = tilly.lendBook( "Harry Potter 1" );

  cout << "mary:Returning HP1 to Mary" << endl;
  Mary.returnBook( cf );


  cout << "lending hp from m to t" << endl;
  tilly.returnBook( Mary.lendBook( "HP1 " ) );

  cout << "printing library used for tilly" << endl;
  t.print();

  cout << "Adding to tilly" << endl;
  tilly.returnBook( newa );
  cout << "Printing tilly lib again" << endl;
  t.print();

  delete hp;
  hp = NULL;
  delete newa;
  newa = NULL; 

  return 0;
}
