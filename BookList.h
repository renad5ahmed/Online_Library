#pragma once
#include "Book.h"
#include "UserList.h"
class BookList
{
private:
	Book* books;
	int capacity, booksCount;
public:
	BookList(const BookList& anotherList);//copy constructor
	void addBook(Book book);
	BookList(int capacity);
	Book& searchBook(string name);
	Book& searchBook(int id);
	void deleteBook(int id); 
	Book getTheHighestRatedBook();
	Book* getBooksForUser(User); 
	Book& operator [ ] (int position);
	friend ostream& operator<<(ostream& output, BookList& booklist); //to display all books
	~BookList();
	int getBooksCount();//Function returns booksCount
};
