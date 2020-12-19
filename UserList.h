#pragma once
#include <string>
#include "User.h"

using namespace std;
class UserList
{
private:
	User* users; //array
	int capacity;
	int usersCount;
	int* ptr;

public:
	UserList(int capacity);
	void addUser(User user); // at the end of the array.
	User& searchUser(string name);
	User& searchUser(int id);
	void deleteUser(int id);
	friend ostream& operator<<(ostream& output, UserList& userList);//to display all books
	~UserList();
};