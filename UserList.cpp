#include "UserList.h"
#include "BookList.h"
#include <iostream>
using namespace std;
UserList::UserList(int capacity)
{
	this->capacity = capacity;
}

void UserList::deleteUser(int id)//deletetUser(2)
{
	for (int i = id; i < capacity; i++) users[i] = users[i + 1];
	//users[capacity] = '\0';//y3ny mafeesh akher element
}

//ostream& operator<<(ostream& output, UserList& userList){for (int i = 0; i < 5; i++)
		//output << (*UserList::ptr).users[i] << endl;   return output;}
