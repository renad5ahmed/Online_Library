#include <string>
#include "User.h"
#include "UserList.h"
#include "Book.h"
#include "BookList.h"
#include <iostream>
#include <vector>

void question() {
	cout << "select one of the following choices:" << '\n';
	cout << "1- Books menu" << '\n' << "2- Users menu" << '\n' << "3- Exit" << '\n';
}
int User::cntUser = 1;
using namespace std;
vector <User> users;
int c, c2_User, NoOFUsers = 0, NoOfBooks = 0, age = 0;
string n, em, pass;

int main() {
	question();
	cin >> c;
	if (c == 1)  cout << "HI";//law 1-books menu 
	else if (c == 2) {//law 2-users menu
		cout << "How many users will be added?" << '\n';
		cin >> NoOFUsers;
		User u;// users menu
		cin >> c2_User;
		if (c2_User == 1) {//law 1-add a user
			u.addUser();
			cin >> n >> age >> em >> pass;
			User u1(n, age, em, pass);

			users.push_back(u1);
		}
		User uk;
		cin >> c2_User;
		if (c2_User == 1) {
			uk.addUser();
			cin >> n >> age >> em >> pass;
			User u2(n, age, em, pass);
			users.push_back(u2);

		}
	}
	else return 0;// law 3-exit
	users[0].printUser();
	users[1].printUser();
	//UserList U1();
	//BookList B1();
	return 0;
}