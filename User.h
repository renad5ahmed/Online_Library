#pragma once
#ifndef USER_H
#define USER_H
#include<cstring>
#include<iostream>
using namespace std;
class User
{
private:
	int age, ID;
	string password, email, name;
public:
	void setID(int id);
	User(); 
	User(string na, int ag, string em, string pass);
	User(const User& user);
	bool operator==(const User& user);
	void setAge(int age);
	void setName(string name);
	void setPass(string pass);
	void setEmail(string email);
	string getName() const;
	string getPassword()const;
	string getEmail()const;
	int getID()const;
	int getAge()const;
	friend istream& operator >>(istream& input, User& user);
	friend ostream& operator<<(ostream& os, const User& user);
};
#endif // USER_H
