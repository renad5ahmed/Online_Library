#pragma once
#include <string>
#include "Book.h"
#include "User.h"
using namespace std;

class BookList
{
private:
	Book* books;
	int capacity;
	int booksCount;
public:
	BookList(const BookList& anotherList); //copy cons
	BookList(int capacity);
	Book& searchBook(string name);
	Book& searchBook(int id);
	void deleteBook(int id); //delete a book
	Book getTheHighestRatedBook();
	Book* getBooksForUser(User); // get all books of this author
	Book& operator [ ] (int position);
	friend ostream& operator<<(ostream& output, BookList& booklist); //to display all books
	~BookList();

};

