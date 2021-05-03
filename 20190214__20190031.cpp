#include <iostream>
#include "Book.h"
#include "User.h"
#include <string>
#include "UserList.h"
#include "BookList.h"
using namespace std;

void BookUpdateOptions() {//Display function for the updating options in Books Menu
	cout << "1- Update author" << '\n' << "2- Update name" << '\n' << "3- Update Category" << '\n' << "4- Delete book" << '\n' << "5- Rate book" << '\n' << "6- Get back to Books Menu" << '\n';
}
void BookSearchMenu() {//Display function for Searching options in Books Menu
	cout << "SEARCH FOR A Book" << '\n' << "1- Search by name" << '\n' << "2- Search by id" << '\n' << "3- Return to Books Menu" << '\n';
}
void UserDeleteORContinue() {// User's options after searching for specific one
	cout << "1- Delete user" << '\n' << "2- Return to Users Menu" << '\n';
}
void UserSearchMenu() {//Display function for Searching options in Users Menu
	cout << "SEARCH FOR A USER" << '\n' << "1- Search by name" << '\n' << "2- Search by id" << '\n' << "3- Return to Users Menu" << '\n';
}
void UserMenu() {//Users menu
	cout << "USERS MENU" << '\n' << "1- create a USER and add it to the list" << '\n' << "2- search for a user" << '\n' << "3- Display all users" << '\n' << "4- Back to the main menu" << '\n';
}
void BooksMenu() {//Books menu
	cout << "BOOKS MENU" << '\n' << "1- Create a book and add it to the list" << '\n' << "2- Search for a book" << '\n' << "3- Display all books (with book rating)" << '\n' << "4- Get the highest rating book" << '\n' << "5- Get all books of a user" << '\n' << "6- Copy the current Book List to a new Book List and switch to it" << '\n' << "7- Back to the main menu" << '\n';
}
int main()
{
	Book B1;
	Book* b = NULL;
	double rating = 0;
	string name = "", category = "", author = "", name2, Authorsname;
	User U, U_info, DeleteU;
	int choice = 0, secondChoice = 0, UpdateOptions = 0, userCap = 0, i = 0, bookCap = 0, SearchCaseChoice = 0, id = 0, DeleteOrReturnChoice = 0, SetAuthorOrContinue = 0;
	bool HowManyUsers = false, HowManyBooks = false, authorExist = false;
	UserList* UL = NULL;
	BookList* BL = NULL;
	do
	{//Displaying main menu
		cout << "select one of the following choices:" << '\n';
		cout << "1- Books menu" << '\n' << "2- Users menu" << '\n' << "3- Exit" << '\n';
		cin >> choice;
		switch (choice) {
		case(1): {//books menu
			do {
				BooksMenu();
				cin >> secondChoice;//Choosing inside books menu
				switch (secondChoice) {
				case(1): {//Create a book
					B1;
					if (!HowManyBooks) {
						cout << "How many books will be added?" << '\n';
						cin >> bookCap;
						HowManyBooks = true;
						BL = new BookList(bookCap);
					}
					cin >> B1; // Read book.
					cout << "1- Assign author" << '\n' << "2- Continue" << '\n';
					cin >> SetAuthorOrContinue;
					if (SetAuthorOrContinue == 1) {//Assign author
						cout << "Enter author(user) id:" << '\n';
						cin >> id;
						UL->searchUser(id);
						if ((id == UL->searchUser(id).getID()))//ID Exists or?
						{
							B1.setAuthor(UL->searchUser(id));// assigning
							B1.AuthorExists(true);
						}
						else cout << "No author found with id =" << id << '\n';
					}
					else if (SetAuthorOrContinue == 2)
						B1.AuthorExists(false);


					BL->addBook(B1);
					break;	}//Create a book case ends

				case(2): {//Searching case
					BookSearchMenu();
					cin >> SearchCaseChoice;
					if (SearchCaseChoice == 1) {//Search by name
						cout << "Enter Name" << '\n';
						cin >> name;
						cout << BL->searchBook(name);

						BookUpdateOptions();
						cin >> UpdateOptions;
						switch (UpdateOptions) {
						case(1): {//update author
							cout << "Enter Author's ID: " << '\n';
							cin >> id;
							if ((id == UL->searchUser(id).getID()))//ID Exists or?
								(BL->searchBook(name)).setAuthor(UL->searchUser(id));
							break;
						}
						case(2): {//update book's name
							cout << "Enter new name:" << '\n';
							cin >> name2;
							BL->searchBook(name).setTitle(name2);
							break;
						}
						case(3): {//update category
							cout << "Enter new category:" << '\n';
							cin >> category;
							BL->searchBook(name).setCategory(category);
							break;
						}
						case(4): {//delete book
							id = BL->searchBook(name).getId();
							BL->deleteBook(id);
							break;
						}
						case(5): {//rate book
							cout << "Enter new rating value" << '\n';
							cin >> rating;
							BL->searchBook(name).setRate(rating);
							break;
						}
						}//Update options switch ends specified to Search by name
					}//If ends
					else if (SearchCaseChoice == 2) {//Search by id
						cout << "Enter ID" << '\n';
						cin >> id;
						cout << BL->searchBook(id) << '\n';
					}
					break;
				}//Searching case ends

				case(3): {//Displaying case
					cout << *BL;
					break;
				}
				case(4): {//Get the highest rating case
					cout << BL->getTheHighestRatedBook();
					break;
				}
				case(5): {//Get all books of a user
					cout << "Enter user ID " << '\n';
					cin >> id;
					BL->getBooksForUser(UL->searchUser(id));
					break;
				}
				case(6): {//copy current book & add it to new list
					cout << "Copied to the current list ( " << BL->getBooksCount() << " books) to a new list and switched to it" << '\n';
					BookList* NBL = new BookList(*BL);
					break;
				}
				}//Books menu options case ends
			} while (secondChoice != 7);//Do while loop ends
			break; }//Case 1-Books Menu ends

		case(2): {//Choosing choice (2), users menu
			do {
				UserMenu();
				cin >> secondChoice;
				switch (secondChoice) {
				case(1): {//Create a user
					User U1;
					if (!HowManyUsers) {
						cout << "How many users will be added?" << '\n';
						cin >> userCap;
						HowManyUsers = true;
						UL = new UserList(userCap);
					}
					cin >> U1; // Read User.
					UL->addUser(U1);
					break;
				}//Creating case ends
				case(2): {//Searching case
					UserSearchMenu();
					cin >> SearchCaseChoice;
					if (SearchCaseChoice == 1) {//search by name
						cout << "Enter Name" << '\n';
						cin >> name;
						cout << UL->searchUser(name);
						UserDeleteORContinue();
						cin >> DeleteOrReturnChoice;
						if (DeleteOrReturnChoice == 1) {//delete user
							id = UL->searchUser(name).getID();
							UL->deleteUser(id);
						}
					}
					else if (SearchCaseChoice == 2) {//search by id
						cout << "Enter ID" << '\n';
						cin >> id;
						cout << UL->searchUser(id) << '\n';
						UserDeleteORContinue();
						cin >> DeleteOrReturnChoice;
						if (DeleteOrReturnChoice == 1) {//delete user
							UL->deleteUser(id);
						}
					}
					break;
				}//Searching case ends
				case(3): {//Display case
					cout << *UL;
				}
				}//Switch of Users menu options ends
			} while (secondChoice != 4);//Do while loop ends
		}
		}//Case 2-Users menu ends
	} while (choice != 3);//First do while loop ends

	if (UL)		delete UL;
	if (BL)     delete BL;
	if (b)     delete b;
	return 0;
}
