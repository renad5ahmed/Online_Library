#pragma once
#include <string>
using namespace std;
class User
{
	int id, age;
	string name, password, email;
public:
	//User(int i, string n);
	User();
	void addUser();
	//~User();
	User(string name, int age, string email, string password);
	static int cntUser;
	void printUser();
};
