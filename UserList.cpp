#include "UserList.h"
#include "User.h"
int UserList::getUserCount()//Returns userCount
{
	return usersCount;
}
UserList::UserList()//default constructor
{
	capacity = 0;
	usersCount = 0;
}
UserList::UserList(int capacity)//Setting the dynamic array's size
{
	this->capacity = capacity;
	this->users = new User[capacity];
	this->usersCount = 0;
}
void UserList::addUser(User user)//Adding function
{
	if (this->usersCount < this->capacity) {
		user.setID(this->usersCount+1);
		this->users[this->usersCount] = user;
		this->usersCount++;
	}
}
User& UserList::searchUser(string name)//Searching by name method
{
	for (int i = 0; i < usersCount; i++) {
		if (users[i].getName() == name) 
			return users[i];
	}   
}
User& UserList::searchUser(int id)//Searching by ID method
{
	for (int i = 0; i < capacity; i++) {
		if ((users[i]).getID() == id) 
			return users[i];
	}
}
void UserList::deleteUser(int id)//delete User
{
	for (int i = 0; i < capacity; i++)
	{
		if ((users[i]).getID() == id)
		{
			while (i < usersCount )
			{
				users[i] = users[i + 1];
				i++;
			}
			usersCount--;
			break;
		}
	}
}
ostream& operator<<(ostream& output, UserList& userList)//Ostream operator insertion for output 
{
	for ( int i = 0; i < userList.usersCount; i++) {		
		output << userList.users[i] << '\n';
	}
    return output;
}
UserList:: ~UserList() {//destructor
	delete[] users;
}
