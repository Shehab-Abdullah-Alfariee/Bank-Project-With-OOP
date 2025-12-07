#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "Global.h"

class clsUpdateClientScreen : clsScreen

{

private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\n\n" << "Update New Client Info : ";
        cout << "\n" << "____________________\n";

        cout << "\n" << "Enter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\n" << "Enter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\n" << "Enter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\n" << "Enter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\n" << "Enter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\n" << "Enter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
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


	static void  ShowUpdateClientScreen()
	{

        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }
		_DrawScreenHeader("\tUpdate Client Screen");

        cout << "\nPlease Enter client Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is Exist, enter another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient ClientUpdate = clsBankClient::Find(AccountNumber);

        _ReadClientInfo(ClientUpdate);

        clsBankClient::enSaveResults SaveResult;

        char Answer = 'n';
        cout << "\nAre you sure you want to Update this client y/n ? ";
        cin >> Answer;
        if (tolower(Answer) == 'y') {

            SaveResult = ClientUpdate.Save();
            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintClient(ClientUpdate);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }
        }
    }
};



