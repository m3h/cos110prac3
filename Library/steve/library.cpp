#include"library.h"
#include"book.h"

Library::Library(string lib)
{
	name = lib;
	librarySize = 5;
	numBooks = 0;
	books = new Book*[librarySize];
}

//copy constructor.
Library::Library(const Library &obj)
{
	name = obj.name;
	librarySize = obj.librarySize;
	numBooks = obj.numBooks;
	books = new Book* [librarySize];
	for(int i =0; i<numBooks; i++)
	{
		books[i] = obj.books[i];
	}
}		

//Search function for the array of pointers.
Book* Library::getBook(string name)
{
	bool flag = false;
	Book* bookSearch;
	for(int i = 0; i<numBooks; i++)
	{
		if((books[i]->getTitle()) == name)
		{
			flag = true;
			bookSearch = books[i];
		}
	}
	if(flag)
		return bookSearch;
	else
		return NULL;
}

//check is library is full.
bool Library::isFull()
{
	if(numBooks == librarySize)
		return true;
	else
		return false;
}

//The output function.
void Library::print()
{
	if(numBooks >0)
	{
		cout<< "Inventory of " << name << " Library: \n";
		cout << "======================\n";
		for(int i = 0; i<librarySize; i++)
		{
			if((0 < numBooks) && (books[i] != NULL))
				cout << i+1 << ". " << *(books[i]);
			else
				cout << i+1 << ". [Empty Space]\n";
		}
	cout << "======================\n";
	}
	else
	{
		cout << "======================\n";
		cout << "EMPTY\n";
		cout << "======================\n";
	}
}

//the overloaded operators :
//overload operator to add a book
Library &Library::operator +=(Book *a)
{
	if(isFull())
	{
		cout << "Library is full!\n";
		return *this;
	}
	else
	{
		books[numBooks] = a;
		numBooks = numBooks +1;
		return *this;
	}
}

//overloaded operator to remove a book from the library.
Library &Library::operator -=(Book *a)
{
	if(numBooks == 0)
	{
		return *this;
	}
	else
	{
		for(int i = 0; i< numBooks; i++)
		{
			if(books[i] == a)
			{
				int j =i;
				while(j!=numBooks)
				{
					books[j] = books[j+1];
					j++;
				}
				books[j] = NULL;
				numBooks = numBooks - 1;
			}
			
		}
		
	}
	return *this;
}

//the assignment operator.
void Library::operator =(const Library &obj)
{
	cout << "Inside assignment operator: \n";
	delete [] books;
	cout << "The books have been deleted\n";
	librarySize = obj.librarySize;
	numBooks = obj.numBooks;
	name = obj.name;
	
	books = new Book* [librarySize];
	for(int i = 0; i<numBooks; i++)
	{
		books[i] = obj.books[i];
	}
}

//The post increment operator increases librarySize.
Library Library::operator++(int)
{
	Book* temp[librarySize];
	for(int i = 0; i<librarySize; i++)
	{
		temp[i] = books[i];
	}
	delete [] books;
	
	librarySize  = librarySize +1;
	books = new Book* [librarySize];
	for(int i = 0; i<(librarySize - 1); i++)
	{
		books[i] = temp[i];
	}
		
	return *this;

}

//This operator decreases the size of books.
Library Library::operator--()
{
	if(isFull())
	{
		books[numBooks-1] = NULL;
		Book* temp[librarySize];
		for(int i = 0; i<librarySize; i++)
		{
			temp[i] = books[i];
		}
		delete [] books;
		
		librarySize  = librarySize -1;
		books = new Book* [librarySize];
		for(int i = 0; i<librarySize; i++)
		{
			books[i] = temp[i];
		}
		numBooks = numBooks-1;
		
			
		return *this;
	}
	else
	{
		Book* temp[librarySize];
		for(int i = 0; i<librarySize; i++)
		{
			temp[i] = books[i];
		}
		delete [] books;
		
		librarySize  = librarySize -1;
		books = new Book* [librarySize];
		for(int i = 0; i<librarySize; i++)
		{
			books[i] = temp[i];
		}
		
		return *this;
	}
}

/*Library::~Library()
{
	//for(int i = 0; i<librarySize; i++)
	//{
	//	delete books[i];
	//}
	delete [] books;
}*/

//accessor and mutator
string Library::getName()
{
	return name;
}

int Library::getLibrarySize()
{
	return librarySize;
}

int Library::getNumBooks()
{
	return numBooks;
}

void Library::setName(string a)
{
	name = a;
}

void Library::setLibrarySize(int a)
{
	librarySize = a;
}

void Library::setNumBooks(int a)
{
	numBooks = a;
}

