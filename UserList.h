#pragma once
#include "User.h"
class UserList
{
private:
	User* users; 
	int capacity, usersCount;
public:
	int getUserCount();//Function returns userCount
	UserList();//default constructor
	UserList(int capacity);
	void addUser(User user); // at the end of the array
	User& searchUser(string name);
	User& searchUser(int id);
	void deleteUser(int id);
	friend ostream& operator<<(ostream& output, UserList& userList);//to display all users
	~UserList();
};
