#include <iostream>
#include <string>

using namespace std;

#include "library.h"
#include "book.h"

int main( int argc, char **argv )
{
  Library t("Texas");
  Book *hp = new Book( "Harry Potter 1", "J.K Rownling", "1234567890" );

  t += hp;
  t.setName("Texas1");

  Library b( t );
  b.setName("Balclutha");
  Book *newa = new Book("New book", "John", "122223" );
  b += newa;
  cout << "TRY" << endl;
  t.print();
  b.print();

  Library a;
  a.print();
  if( a.getBook( "New book" ) == NULL ) {
	  cout << "Success?" << endl;
  }
  a += newa;
  a += newa;

  --a;
  --a;
  --a;
  --a;
  --a;
  --a;
  a.print();
  delete hp;
  hp = NULL;
  delete newa;
  newa = NULL; 
  return 0;
}
