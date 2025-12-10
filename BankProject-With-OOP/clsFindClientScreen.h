#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "Global.h"
class clsFindClientScreen : protected clsScreen
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


	static void ShowFindClientScreen() {


		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("\t  Find Client Screen");

		cout << "\nEnter Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount number is Not Exist, enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty()) {
			cout << "\nClient Found :-)\n";
		}
		else {
			cout << "\nClient Not Found :-(\n";

		}
		_PrintClient(Client1);
	}
};

