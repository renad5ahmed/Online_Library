#pragma once
#ifndef BOOK_H
#define BOOK_H
#include<cstring>
#include<iostream>
#include "User.h"
using namespace std;
class Book
{
private:
	bool AuthorExist;
	string title,isbn, category;
	int id,noOfRatings;
	double averageRating,sumOfRatings;
	User author;
public:
	void AuthorExists(bool u);
	bool getAuthorExistOr()const;
	void setAuthor(User user);
	Book(); 
	Book(string tit, string isb, string categ);
	Book(const Book& book); 
	string getTitle()const;
	string getISBN()const;
	int getId()const;
	void setID(int id);
	void setRate(double rating);
	void setTitle(string name);
	void setCategory(string cat);
	string getCategory()const;
	double getRate()const;
	User getAuthor()const;
	void rateBook(int rating);
	bool operator==(const Book& book);
	friend ostream& operator<<(ostream& output, const Book& book);
	friend istream& operator>>(istream& input, Book& book);
};
#endif // BOOK_H
