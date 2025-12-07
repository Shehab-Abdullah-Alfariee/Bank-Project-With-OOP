#pragma once
#include <iostream>
#include "clsScreen.h"
#include<iomanip>
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransfareScreen.h"
#include "clsTransfareRegisterScreen.h"

class clsTransactionsScreen : protected clsScreen
{


private:

    enum enTransactionsMenuOptions {
        eDeposit = 1, eWithdrow = 2, eTotalBalance = 3, eTransfare = 4, eTransfareLog = 5, eMainMenu = 6
    };

    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToTransactionsMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

        system("pause>0");
        ShowTransactionsMenue();
    }

    static void _ShowDepositScreen()
    {
        //cout << "\nDeposit Screen Will be here...\n";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();

    }

    static void _ShowTotalBalanceScreen()
    {
        clsTotalBalanceScreen::ShowTotalBalanceScreen();

    }

    static void _ShowTransfareScreen()
    {
        clsTransfareScreen::ShowTransfareScreen();

    }

    static void _ShowTransfareLogScreen()
    {
        clsTransfareRegisterScreen::ShowTransfareLogScreen();

    }

    static void _PerfromTransactionsMenueOption(enTransactionsMenuOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enTransactionsMenuOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enTransactionsMenuOptions::eWithdrow:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenuOptions::eTotalBalance:
        {
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enTransactionsMenuOptions::eTransfare:
        {
            system("cls");
            _ShowTransfareScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enTransactionsMenuOptions::eTransfareLog:
        {
            system("cls");
            _ShowTransfareLogScreen();
            _GoBackToTransactionsMenue();

            break;
        }
        case enTransactionsMenuOptions::eMainMenu:
        {
            system("cls");
            break;
        }
        }

    }

public:


    static void ShowTransactionsMenue()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t\tTransactions Menue Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfare.\n";
        cout << setw(37) << left << "" << "\t[5] Transfare Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTransactionsMenueOption((enTransactionsMenuOptions)_ReadTransactionsMenueOption());
    }

};

