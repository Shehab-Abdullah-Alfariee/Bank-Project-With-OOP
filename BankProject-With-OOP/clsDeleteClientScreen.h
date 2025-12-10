#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "Global.h"
class clsDeleteClientScreen : protected clsScreen
{

private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n" << "Client Card:";
		cout << "\n" << "___________________";
		cout << "\n" << "FirstName   : " << Client.FirstName;
		cout << "\n" << "LastName    : " << Client.LastName;
		cout << "\n" << "Full Name   : " << Client.FullName();
		cout << "\n" << "Email       : " << Client.Email;
		cout << "\n" << "Phone       : " << Client.Phone;
		cout << "\n" << "Acc. Number : " << Client.AccountNumber();
		cout << "\n" << "Password    : " << Client.PinCode;
		cout << "\n" << "Balance     : " << Client.AccountBalance;
		cout << "\n" << "___________________\n";

	}


public:

	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClients))
		{
			return;
		}

		_DrawScreenHeader("\t  Delete Client Screen");

		cout << "Enter Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();
				
		while(!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount number is Not Exist, enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);
		
		char Answer = 'n';
		cout << "\nAre you sure you want to delete this client ? y/n";
		cin >> Answer;

		if (tolower(Answer) == 'y') {

			if(Client1.Delete())
			{ 
				cout << "\nAccount Deleted Successfully :-)\n";
			}
			else
			{
				cout << "\nError Client was not Deleted Successfully.";

			}
		}
		
	}

};

