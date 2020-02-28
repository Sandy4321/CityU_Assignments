#include <iostream>
using namespace std;

// use to compare array
bool compareCharArray(char str1[], char str2[])
{
	// declare the result as true, once face any difference become false
	bool result = true;
	// use loop to compare character by character
	for (int i = 0; i < strlen(str1); i++)
	{
		if (str1[i] != str2[i])
		{
			result = false;
		}
	}

	// return result
	return result;
}

// Book class with some methods;
class Book
{
  private:
	char Name[10];
	int Date;
	bool State;

  public:
	// constructor
	Book();

	// assign the value with cin
	void assign();

	// get the name
	char *getName();

	// get the date
	int getDate();

	// get the state
	bool getState();

	// update the book with variables
	void setBook(char *name, int date, bool state);
	
	// print the book information
	void list();
};


Book::Book()
{
	Date = 0;
	State = 0;
}

void Book::assign()
{
	cin >> Name;
	cin >> Date;
	cin >> State;
}

char *Book::getName()
{
	return Name;
}

int Book::getDate()
{
	return Date;
}

bool Book::getState()
{
	return State;
}

void Book::setBook(char name[10], int date, bool state)
{
	for (int index = 0; index < 10; index++)
	{
		*(Name + index) = *(name + index);
	}
	Date = date;
	State = state;
}

void Book::list()
{
	cout << Name << " " << Date << " " << State << endl;
}



// Subject Class
class Subject
{
  private:
	int count;
	Book list[100];

  public:
	// constructor 
	Subject();
	
	// add the book into the list
	void appendBook(Book book);

	// display the book
	void listBooks();

	// sort the books according list
	void sort();

	// find the book 
	bool searchBook(char name[]);
	
	// if found the identify its status

	bool getStatus(char name[]);
};

Subject::Subject()
{
	count = 0;
}

void Subject::appendBook(Book book)
{
	list[count++] = book;
}

void Subject::listBooks()
{
	for (int index = 0; index < count; index++)
	{
		list[index].list();
	}
}

void Subject::sort()
{
	// use bubble sort
	// create a temp book to store the displaced book for swap
	Book tempBook;
	int indexPivoter = 0;

	for (int index = 0; index < count - 1; index++)
	{
		for (int index2 = 0; index2 < count - index - 1; index2++)
		{
			if (list[index2].getDate() < list[index2 + 1].getDate())
			{
				tempBook.setBook(list[index2].getName(), list[index2].getDate(), list[index2].getState());
				list[index2] = list[index2 + 1];
				list[index2 + 1] = tempBook;
			}
		}
	}
}

bool Subject::searchBook(char name[])
{
	/* 
		find the book for the subject
		assuming the book is not found whenever the book is found result will be true;
	*/
	bool result = false;
	for (int index = 0; index < count; index++)
	{
		if (compareCharArray(list[index].getName(), name))
		{
			result = true;
			break;
		}
	}
	return result;
}

bool Subject::getStatus(char name[])
{
	// same concept as finding the book

	bool result = false;

	for (int index = 0; index < count; index++)
	{
		if (compareCharArray(list[index].getName(), name))
		{
			return list[index].getState();
		}
	}
	// this part are just for mocking because it should not happens
	cout << "Error" << endl;
	return result;
}


class Library
{
  private:
	char Name[10];
	Subject Art, Science, History;

  public:
	  // put the book into their subject
	void appendBook(Book book);

	// list out all the subjects which will call the list in subject
	void listSubjects();

	// sort the subjects which will call the sort in subjects
	void sortSubjects();

	// check the books status
	void borrowBook();
};


void Library::appendBook(Book book)
{
	char type[10];
	char ArtStr[] = "Art\0", HistoryStr[] = "History\0", ScienceStr[] = "Science\0";
	cin >> type;
	// get the type and use the compare string to compare the type
	if (compareCharArray(type, ArtStr))
	{
		Art.appendBook(book);
	}
	else if (compareCharArray(type, HistoryStr))
	{
		History.appendBook(book);
	}
	else if (compareCharArray(type, ScienceStr))
	{
		Science.appendBook(book);
	}
}


void Library::listSubjects()
{
	//display the books by calling subjects' listBooks() function
	cout << "Books in the library:" << endl;
	cout << "Art:" << endl;
	Art.listBooks();
	cout << "Science:" << endl;
	Science.listBooks();
	cout << "History:" << endl;
	History.listBooks();
}

void Library::sortSubjects()
{
	// call the sort function respectively
	Art.sort();
	Science.sort();
	History.sort();
}


void Library::borrowBook()
{
	char bookName[10];

	// same concept as the searching consider at first nothing is found 
	// if anything is found bookIsFound will be true
	bool bookIsFound = false;


	while (!bookIsFound)
	{
		// get the book name
		cin >> bookName;

		if (Art.searchBook(bookName))
		{
			if (Art.getStatus(bookName))
			{
				cout << "Succeed!" << endl;
				bookIsFound = true;
			}
			else
			{
				cout << "Sorry, the book is not available. Try again:" << endl;
			}
			continue;
		}
		else if (Science.searchBook(bookName))
		{
			if (Science.getStatus(bookName))
			{
				cout << "Succeed!" << endl;
				bookIsFound = true;
			}
			else
			{
				cout << "Sorry, the book is not available. Try again:" << endl;
			}
			continue;
		}
		else if (History.searchBook(bookName))
		{
			if (History.getStatus(bookName))
			{
				cout << "Succeed!" << endl;
				bookIsFound = true;
			}
			else
			{
				cout << "Sorry, the book is not available. Try again:" << endl;
			}
			continue;
		}
		else
		{
			cout << "Sorry, the book is not available. Try again:" << endl;
		}
	}
}



int main()
{
	// get the number of books in the library
	int nBooks;
	cout << "Input the number of books:" << endl;
	cin >> nBooks;


	// create a library object
	Library lib;


	// get the books 
	cout << "Input the information of books (name, date, state, subject):" << endl;
	for (int index = 0; index < nBooks; index++)
	{
		Book book;
		book.assign();
		lib.appendBook(book);
	}

	
	// sort the subjects which will sort the book
	lib.sortSubjects();

	// list out all the subject
	lib.listSubjects();

	// lib.readSubject();
	cout << "Input the name of the book you want to borrow:" << endl;

	// borrowBook()
	lib.borrowBook();
	return 0;
}
