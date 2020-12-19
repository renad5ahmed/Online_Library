#include "User.h"
#include <string>
#include <iostream>
//User::User(int i, string n): id(i), name(n){}

User::User()//default cons
{
	name = "";
	password = "";
	age = 0;
	email = "";
	id = 0;
	cout << "USERS MENU" << '\n' << "1- create a USER and add it to the list" << '\n' << "2- search for a user" << '\n' << "3- Display all users" << '\n' << "4- Back to the main menu" << '\n';
}

void User::addUser()
{
	cout << "Enter the user information in this order" << '\n' << "Name Age Email Password (Space separated)" << '\n';

}

User::User(string name, int age, string email, string password)//parameterized cons
{
	this->name = name;
	this->age = age;
	this->email = email;
	this->password = password;
	id = cntUser;
	User::cntUser++;

}

void User::printUser()
{
	id = 1;
	cout << "========User " << id << " info =========" << '\n';
	cout << "Name: " << name << '\n' << "Age: " << age << '\n' << "Id: " << id << '\n' << "Email: " << email << '\n';
	cout << "=============================" << '\n';
	id++;
}

