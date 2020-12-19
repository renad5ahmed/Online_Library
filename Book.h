#pragma once
#include <string>
using namespace std;
class Book
{
	int id, position;
	string name;
public:
	Book(int i, string n);
	//static int cntBook;
};
//int Book::cntBook = 0;