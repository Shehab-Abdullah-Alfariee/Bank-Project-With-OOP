#pragma once
#include<iostream>
#include<string>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

class clsTotalBalanceScreen : protected clsScreen
{

private:

    static void _PrintClientRecordLine(clsBankClient Client)
    {

        cout << "\t\t| " << setw(10) << left << Client.AccountNumber();
        cout << "\t\t| " << setw(20) << left << Client.FullName();
        cout << "\t\t| " << setw(12) << left << Client.AccountBalance;
    }

public:


    static void ShowTotalBalanceScreen()
    {


        vector <clsBankClient> vClients = clsBankClient::GetClientList();
        string Title = "\t  Total Balance Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\t\t___________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t\t| " << left << setw(10) << "Accout Number";
        cout << "\t\t| " << left << setw(20) << "Client Name";
        cout << "\t\t| " << left << setw(12) << "Balance";
        cout << "\n\t\t___________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();
        if (vClients.size() == 0)
            cout << "\t\t\tNo Clients Available In the System!";
        else
            for (clsBankClient Client : vClients)
            {
                _PrintClientRecordLine(Client);
                cout << endl;
            }
        cout << "\n\t\t___________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\n\t\tTotal Balances is : " << TotalBalances << endl;

        cout << "\n\t\t(" << clsUtil::NumberToText(TotalBalances) <<")\n";


    }
};
