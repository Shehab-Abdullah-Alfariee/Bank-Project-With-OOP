#pragma once
#include<iostream>
#include<string>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsInputValidate.h"



using namespace std;

class clsDepositScreen : clsScreen

{


private:

	static string _ReadAccoutNumber()
	{
		cout << "\nEnter AccountNumber ? ";
		string AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}

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

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t  Deposit Screen");

		string AccountNumber = _ReadAccoutNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] dose not Exist.";
			AccountNumber = _ReadAccoutNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease Enter deposit Amount? ";
		Amount = clsInputValidate::ReadNumber<double>();


		char Answer = 'n';
		cout << "Are you sure you want to Perfrom this transaction ? y/n : ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			Client1.Deposit(Amount);
			cout << "\nAmount Deposit Successfully :-)\n";
			cout << "\nNew Balance is : " << Client1.AccountBalance << endl;
		}
		else {
			cout << "\nOpreation was cancelled.\n";

		}
	}

};
