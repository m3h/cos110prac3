#include <iostream>
#include <string>

using namespace std;

#include "library.h"
#include "book.h"

int main( int argc, char **argv )
{
  Library t("Texas");
  Book hp( "Harry Potter 1", "J.K Rownling", "1234567890" );

  t += hp;
  t.setName("Texas1");

  //Library b( t );
  //b.setName("Balclutha");
  cout << "TRY" << endl;
  t.print();
  //b.print();
  return 0;
}
