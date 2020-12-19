#include "BookList.h"

void BookList::deleteBook(int id)// deleteBook(2)
{
	for (int i = id; i < capacity; i++) books[i] = books[i + 1];
	//	books[capacity] = '\0'; //akher element howa el null
}

ostream& operator<<(ostream& output, BookList& booklist)
{
	// TODO: insert return statement here
	//print sth
	return output;
}