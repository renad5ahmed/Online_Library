#include "BookList.h"
#include "UserList.h"
BookList::BookList(const BookList& anotherList)//copy constructor
{
	capacity = anotherList.capacity;
	books = anotherList.books;
	booksCount = anotherList.booksCount;
}
void BookList::addBook(Book book)//Adding function
{
	if (this->booksCount < this->capacity) {
		book.setID(this->booksCount + 1);
		this->books[this->booksCount] = book;
		this->booksCount++;
	}
}
BookList::BookList(int capacity)//Setting the dynamic array's size
{
	this->capacity = capacity;
	this->books = new Book[capacity];
	this->booksCount = 0;
}
Book& BookList::searchBook(string name)//Searching by name method
{
	for (int i = 0; i < booksCount; i++) {
		if (books[i].getTitle() == name)
				return books[i];
	}
}
Book& BookList::searchBook(int id)//Searching by ID method
{
	for (int i = 0; i < capacity; i++) {
		if (books[i].getId() == id) return books[i];
	}
}
void BookList::deleteBook(int id)//Delete book
{
	for (int i = 0; i < capacity; i++) {
		if ((books[i]).getId() == id) {
			while (i < booksCount) {
				books[i] = books[i + 1];
				i++;
			}
			booksCount--;
			break;
		}
	}
}
Book BookList::getTheHighestRatedBook()//getting the highest rated book
{
	int max = -1, i = 0, iMax = 0;
	for (i = 0; i < booksCount; i++) {
		if (max < books[i].getRate()) {
			max = books[i].getRate();
			iMax = i;
		}
	}
	return books[iMax];
}
Book* BookList::getBooksForUser(User user)//returning an array of books related to a specific user
{
	int j = 0;
	Book* arr = new Book[booksCount];
	for (int i = 0; i < booksCount; i++) {
		if (user.getID() == books[i].getAuthor().getID()) {
			arr[j] = books[i];
			j++;
		}
	}
	for (int i = 0; i < j; i++) {
		cout << endl << "========Book " << arr[i].getId() << " info ========" << '\n';
		cout << "Title: " << arr[i].getTitle() << '\n' << "ISBN: " << arr[i].getISBN() << '\n' << "Id: " << arr[i].getId() << '\n' << "Category: " << arr[i].getCategory() << '\n'
			<< "Avg Rating: " << arr[i].getRate() << '\n';
		cout << "Author: " << arr[i].getAuthor().getName() << '\n';
	}
	return arr;
}
Book& BookList::operator[](int position)//Subscript operator to add books
{
	if (position < booksCount)
		return books[position];
}
BookList::~BookList()//destructor
{
	delete[] books;
}
int BookList::getBooksCount()//books count getter
{
	return booksCount;
}
ostream& operator<<(ostream& output, BookList& booklist)//Ostream operator insertion for output
{
	for (int i = 0; i < booklist.booksCount; i++) {
		output << "========Book " << booklist[i].getId() << " info ======== " << "\n Title: " << booklist[i].getTitle() << "\n ISBN: " << booklist[i].getISBN() << "\n Id: " << booklist[i].getId() << "\n category: " << booklist[i].getCategory() << "\n Avg Rating: " << booklist[i].getRate() << endl;
		if(booklist[i].getAuthorExistOr()==true)
		    output << "========Author info ======== " << "\n Name: " << booklist[i].getAuthor().getName() << "\n Age: " << booklist[i].getAuthor().getAge() << "\n ID: " << booklist[i].getAuthor().getID() << "\n Email: " << booklist[i].getAuthor().getEmail() << "\n ====================================" << endl;

		else
			output << "====================================" << endl;
	}
	return output;
}
