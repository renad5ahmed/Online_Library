#include "User.h"
#include <iostream>
using namespace std;
#include <string>
#include "UserList.h"
User::User() //default cons: set default values
{
	ID = 0;
	age = 0;
	name = "";
	email = "";
	password = "";
}
void User::setPass(string pass)
{
	password = pass;
}
bool User::operator==(const User& user)  // compares values
{
	if ((name == user.name) && (age = user.age) && (email == user.email) && (password == user.password))
		return true;
	else
		return false;
}
string User::getName()const // name getter
{
	return name;
}
string User::getPassword()const // password getter
{
	return password;
}
string User::getEmail()const // email getter
{
	return email;
}
void User::setName(string name)
{
	this->name = name;
}
int User::getID()const
{
	return ID;
}
void User::setID(int id) {
	ID = id;
}
void User::setAge(int age) {
	this->age = age;
}
int User::getAge()const // Age getter
{
	return age;
}
void User::setEmail(string email)
{
	this->email = email;
}
User::User(string na, int ag, string em, string pass)// parameterized cons
{
	name = na;
	age = ag;
	email = em;
	password = pass;
}
User::User(const User& user) //copy cons: copy values
{
	name = user.name;
	age = user.age;
	email = user.email;
	password = user.password;
	ID = user.ID;
}
istream& operator>>(istream& is, User& user1)  // istream operator extraction for input
{
	cout << "Enter the user information in this order" << '\n' << "Name Age Email Password (Space separated)" << '\n';
	is >> user1.name >> user1.age >> user1.email >> user1.password;
	return is;
}
ostream& operator<<(ostream& os, const User& user) { //ostream operator insertion for output
	os << "========User " << (user.ID) << " info =========" << '\n';
	os << "Name: " << user.name << '\n' << "Age: " << user.age << '\n' << "Id: " << user.ID << '\n' << "Email: " << user.email << '\n';
	os << "=============================" << '\n';
	return os;
}
