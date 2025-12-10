#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include<string>
#include <iomanip>
#include "clsInputValidate.h"


using namespace std;

class clsDeleteUserScreen : clsScreen
{

private:

	static void _PrintUserInfo(clsUser User)
	{
		cout << "\n" << "User Card:";
		cout << "\n" << "___________________";
		cout << "\n" << "FirstName   : " << User.FirstName;
		cout << "\n" << "LastName    : " << User.LastName;
		cout << "\n" << "Full Name   : " << User.FullName();
		cout << "\n" << "Email       : " << User.Email;
		cout << "\n" << "Phone       : " << User.Phone;
		cout << "\n" << "UserName    : " << User.UserName;
		cout << "\n" << "Password    : " << User.Password;
		cout << "\n" << "Permissions : " << User.Permissions;
		cout << "\n" << "___________________\n";

	}

public:


	static void ShowDeleteUsersScreen()
	{
		_DrawScreenHeader("\t  Delete User Screen");

		cout << "Please Enter UserName ? ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {

			cout << "\nUser is Found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);

		_PrintUserInfo(User);

		char Answer = 'n';
		cout << "\nAre you sure you want to delete this User ? y/n : ";
		cin >> Answer;

		if (tolower(Answer) == 'y') {

			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";
			}
			else
			{
				cout << "\nError User was not Deleted Successfully.";

			}
		}

	}	
};

