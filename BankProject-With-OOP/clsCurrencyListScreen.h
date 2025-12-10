#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "Global.h"
#include <vector>


using namespace std;

class clsCurrencyListScreen : protected clsScreen
{


private:

    static void PrintCurrencysRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(26) << left << Currency.Country();
        cout << "| " << setw(12) << left << Currency.CurrencyCode();
        cout << "| " << setw(39) << left << Currency.CurrencyName();
        cout << "| " << setw(12) << left << Currency.Rate();
    }

public:


    static void ShowListCurrencyScreen()
    {

        vector <clsCurrency> vCurrencys = clsCurrency::GetCurrenciesList();

        string Title = "\t  Currency List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencys.size()) + ") Currency(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(26) << "Country";
        cout << "| " << left << setw(12) << "Code";
        cout << "| " << left << setw(39) << "Name";
        cout << "| " << left << setw(10) << "Rate(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrencys.size() == 0)
            cout << "\t\t\t\tNo Currencys Available In the System!";
        else

            for (clsCurrency Currency : vCurrencys)
            {

                PrintCurrencysRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }




};

