#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "Global.h"


class clsTransfareRegisterScreen : protected clsScreen
{


    static void PrintTransfareLogRecordLine(clsBankClient::stTransfareLogRecord TransfareLog)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransfareLog.DateTime; ;
        cout << "| " << setw(8) << left << TransfareLog.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransfareLog.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransfareLog.Amount;
        cout << "| " << setw(10) << left << TransfareLog.srcBalanceAfter;
        cout << "| " << setw(10) << left << TransfareLog.destBalanceAfter;
        cout << "| " << setw(8) << left << TransfareLog.UserName;

    }

public:


    static void ShowTransfareLogScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pTransfareRegister))
        {
            return;
        }

        vector <clsBankClient::stTransfareLogRecord> vTransfareLog = clsBankClient::GetTransfareLogList();

        string Title = "\t  Transfare Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransfareLog.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t__________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << setw(23) << left << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
 
        cout << setw(8) << left << "" << "\n\t__________________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransfareLog.size() == 0)
            cout << "\t\t\t\tNo Transfare Registers In the System!";
        else

            for (clsBankClient::stTransfareLogRecord Record : vTransfareLog)
            {

                PrintTransfareLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t__________________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

