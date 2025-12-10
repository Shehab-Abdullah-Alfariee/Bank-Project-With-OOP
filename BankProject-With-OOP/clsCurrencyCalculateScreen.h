#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculateScreen : protected clsScreen
{
private:

    static float _ReadAmount()
    {
        cout << "\nEnter Amount: ";
        float Amount = 0;

        Amount = clsInputValidate::ReadNumber<float>();
        return Amount;
    }

    static clsCurrency _GetCurrency(string Message)
    {
        string CurrencyCode = "";
        cout << Message << endl;

        CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }

    static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Convert From") {

        cout << "\n" << Title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";

    }

    static void _PrintCalculateResult(float Amount, clsCurrency Curency1, clsCurrency Curency2)
    {

        _PrintCurrencyCard(Curency1,"Convert From:");

        float AmountInUSD = Curency1.ConvertToUSD(Amount);

        cout << Amount << " " << Curency1.CurrencyCode() <<
            " = " << AmountInUSD << " USD\n";

        if (Curency2.CurrencyCode() == "USD")
        {
            return;
        }
        cout << "Convert From USD to: \n";
        _PrintCurrencyCard(Curency2,"To:");

        float AmountInCurrency2 = Curency1.ConvertToOtherCurrency(Amount,Curency2);


        cout << Amount << " " << Curency1.CurrencyCode() <<
            " = " << AmountInCurrency2 << " " << Curency2.CurrencyCode();
    }

public:

   
    static void ShowCurrencyCalculateScreen()
    {

        _DrawScreenHeader("\Calculate Currency Screen");

        char Continue = 'y';
        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");
            _DrawScreenHeader("\Calculate Currency Screen");

            clsCurrency CurencyFrom = _GetCurrency("\nPlease Enter Currency1 Code :");
            clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code :");
            float Amount = _ReadAmount();

            _PrintCalculateResult(Amount, CurencyFrom, CurrencyTo);

            cout << "\nDo you want to perform another currency calculation? y/n: ";
            cin >> Continue;

        }
    }
};

