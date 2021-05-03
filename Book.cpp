#include "Book.h"
#include <string>
#include <iostream>
using namespace std;
void Book::AuthorExists(bool u)//set Author existence checker with true value
{
	AuthorExist = u;
}
bool Book::getAuthorExistOr() const //get Author existence checker
{
	return AuthorExist;
}
void Book::setAuthor(User user)// author setter(assign one)
{
	author = user;
}
Book::Book() // default constructor: set default values
{
	noOfRatings = 0;
	sumOfRatings = 0.0;
	averageRating = 0.0;
	id = 0;
	averageRating = 0.0;
	AuthorExist = false;
}
Book::Book(string title, string isbn, string category) // parameterized constructor
{
	this->title = title;
	this->isbn = isbn;
	this->category = category;
}
string Book::getTitle()const // title getter
{
	return title;
}
string Book::getISBN()const // isbn getter
{
	return isbn;
}
string Book::getCategory()const //category getter
{
	return category;
}
void Book::rateBook(int rating) // calculate the average rating of a book
{
	noOfRatings++; //increment for the number of values that passed through parameter
	if (sumOfRatings == 0) //this condition is satisfy for 1 time only for an object as the first rate value to the book object implement these statements
	{
		sumOfRatings = rating; //sum of values equal the first value passed
		averageRating = sumOfRatings;
	}
	else  
	{
		sumOfRatings += rating; // sum of values equal the sum of the previous value plus the new value

		averageRating = sumOfRatings / noOfRatings; // average rating equals the sum of values / number of values passed through the parameter
	}
}
double Book::getRate()const //rating getter
{
	return averageRating;
}
User Book::getAuthor() const //Author getter
{
	return author;
}
int Book::getId()const //id getter
{
	return id;
}
void Book::setRate(double rating)//rate setter
{
	averageRating = rating;
}
void Book::setTitle(string name)//title setter
{
	title = name;
}
void Book::setCategory(string cat)//category setter
{
	category = cat;
}
void Book::setID(int id) {//ID detter
	this->id = id;
}
bool Book::operator==(const Book& book)//compares values
{
	if ((title == book.title) && (isbn == book.isbn) && (id == book.id) && (category == book.category) && (averageRating == book.averageRating))
		return true;
	else
		return false;
}
ostream& operator<<(ostream& output, const Book& book)//ostream operator insertion for output
{
	output << endl << "========Book " << book.id << " info ========" << endl << "Title: " << book.title << "\nISBN: " << book.isbn << "\nID: " << book.id << "\nCategory: " << book.category << "\nAvg Rating: " << book.averageRating<<'\n';
	if (book.getAuthorExistOr()==true)
			output << "Author: " << book.author.getName() << endl << "====================================" << endl;
	else
		output << endl << "====================================" << endl;
	return output;
}
istream& operator>>(istream& input, Book& book) // istream operator extraction for input
{
	cout << "Enter the book information in this order" << '\n' << "Title ISBN Category (Space separated)" << '\n';
	input >> book.title >> book.isbn >> book.category;
	return input;
}
Book::Book(const Book& book)//copy constructor
{
	averageRating = book.averageRating;
	isbn = book.isbn;
	title = book.title;
	category = book.category;
	id = book.id;
	author = book.author;
	noOfRatings = book.noOfRatings;
	sumOfRatings = book.sumOfRatings;
	AuthorExist = book.AuthorExist;
}   
