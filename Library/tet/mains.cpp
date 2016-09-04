//This is the main file for the second part of the prac.
#include<iostream>
#include<string>

using namespace std;

#include"book.h"
#include"library.h"

int main()
{
	Book* book1 = new Book("InkSpell" ,"Cornelia Funke" ," 97804396412");
	Book* book2 = new Book("The name of the Wind" ,"Patrick Rothfuss" ," 9780756404741");
	Book* book3 = new Book("Ender's Game" ,"Orson Scott Card" ," 9788617354691");
	Book* book4 = new Book("Dune" ,"Frank Herbert" ," 9781587464687");
	Book* book5 = new Book("dsbebreb" ,"Cornelia dsv" ," 619166516516");

	Library Pretoria("Pretoria");
	Library Balclutha("Balclutha");
	Pretoria.print();
	Pretoria += book1;
	Pretoria += book2;
	Pretoria += book3;
	Pretoria += book4;
	Pretoria += book5;

	Pretoria.print();
	--Pretoria;
	Pretoria.print();
	Pretoria -= book2;
	Pretoria.print();
	--Pretoria;
	Pretoria.print();
	Pretoria++;
	Pretoria += book2;
	Pretoria.print();
	cout <<"This is the get book function: \n";
	cout << *(Pretoria.getBook(book1->getTitle())) << endl;
	cout << "This is getting a non-existant book" << endl;
	cin.ignore();

	if( Pretoria.getBook( "Petrushka") != NULL )
	cout << *(Pretoria.getBook( "Petrushka" ) );

	Balclutha = Pretoria;
	Balclutha.setName("copiedBalclutha");
	Balclutha.print();
	--Pretoria;
	--Pretoria;
	--Pretoria;
	--Pretoria;

	Pretoria.print();
	Pretoria++;
	Pretoria += book2;
	Balclutha.print();
	Balclutha++;
	Balclutha++;
	Balclutha++;

	Balclutha += book1;
	Balclutha += book3;
	Balclutha += book4;
	Balclutha += book3;
	Pretoria.print();
	Balclutha.print();
	return 0;
}
