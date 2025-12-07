#pragma once
#include<iostream>
#include<string>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

class clsTransfareScreen : protected clsScreen
{



private:
	
	static string _ReadAccoutNumber(string FromOrTo)
	{
		
		cout << "\nPlease Enter Account Number to Transfare " << FromOrTo << "? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number [" << AccountNumber << "] id not Found, choos another one ? ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n" << "Client Card:";
		cout << "\n" << "___________________";
		cout << "\n" << "Full Name   : " << Client.FullName();
		cout << "\n" << "Acc. Number : " << Client.AccountNumber();
		cout << "\n" << "Balance     : " << Client.AccountBalance;
		cout << "\n" << "___________________\n";

	}

	static float _ReadAmount()
	{
		float Amount = 0;
		cout << "\nPlease Enter Transfare Amount? ";
		Amount = clsInputValidate::ReadDblNumber();

		return Amount;
	}

public:


	static void ShowTransfareScreen()
	{

		string Title = "\t  Transfare Screen";

		_DrawScreenHeader(Title);
		
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccoutNumber("From"));
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccoutNumber("To"));
		_PrintClient(DestinationClient);

		
		float Amount = _ReadAmount();
		
		cout << "Are you sure you want to Perfrom this transfare ? y/n : ";
		char Answer = 'n';
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			if (SourceClient.Transfare(Amount,DestinationClient)) {

				cout << "\nTransfare done Successfully :-)\n";
			}
			else
			{
				cout << "\nTransfare Faild.\n";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

