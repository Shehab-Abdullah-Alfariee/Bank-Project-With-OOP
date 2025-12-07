#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "Global.h"

class clsAddNewClientsScreen :protected clsScreen
{

private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\n\n"<< "Add New Client Info : ";
        cout << "\n"<< "____________________\n";

        cout << "\n"<< "Enter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\n"<< "Enter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\n"<< "Enter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\n"<< "Enter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\n"<< "Enter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\n"<< "Enter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

    static void _PrintClientInfo(clsBankClient Client)
    {
        cout << "\n"<< "Client Card:";
        cout << "\n"<< "___________________";
        cout << "\n"<< "FirstName   : " << Client.FirstName;
        cout << "\n"<< "LastName    : " << Client.LastName;
        cout << "\n"<< "Full Name   : " << Client.FullName();
        cout << "\n"<< "Email       : " << Client.Email;
        cout << "\n"<< "Phone       : " << Client.Phone;
        cout << "\n"<< "Acc. Number : " << Client.AccountNumber();
        cout << "\n"<< "Password    : " << Client.PinCode;
        cout << "\n"<< "Balance     : " << Client.AccountBalance;
        cout << "\n"<< "___________________\n";

    }

public:


	static void ShowAddNewClientsScreen()
	{
         
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClients))
        {
            return;
        }
        _DrawScreenHeader("\t  Add New Client Screen");

        cout << "\n" << "Please Enter client Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n"<< "Account number is Exist, enter another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        char Answer = 'n';
        cout<< "Are you sure you want to add this client y/n ? ";
        cin >> Answer;
        if (tolower(Answer) == 'y') {

            SaveResult = NewClient.Save();
            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\n"<< "Account Added Successfully :-)\n";
                _PrintClientInfo(NewClient);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\n"<< "Error account was not saved because it's Empty";
                break;

            }

            }
        }     
	}
};

