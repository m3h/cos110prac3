#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
	string title;
	string author;
	string ISBN;
	string genre;

public:
	Book() {}
	Book( string title, string author, string ISBN );

	friend ostream &operator << (ostream &strm, const Book &obj);

	string getTitle() const { return title; }
	void setTitle( string a ) { title = a; }

	string getAuthor() const { return author; }
	void setAuthor( string a ) { author = a; }

	string getISBN() const { return ISBN; }
	void setISBN( string a ) { ISBN = a; }

	string getGenre() const { return genre; }
	void setGenre( string a ) { genre = a; }
};

#endif
