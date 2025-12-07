#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{

private:

    static bool _Login() 
    {
        int FaildLoginCount = 0;
        bool LoginFaild = false;
        string UserName, Password;
        do {

            if (LoginFaild)
            {
                FaildLoginCount++;
                cout << "\nInvalid Username/Password!";
                cout << "\nYou have " << 3- FaildLoginCount << " Trials to login. \n\n";
            }
            if(FaildLoginCount == 3) {
                cout << "\nYou Are Locked after 3 faild trails!\n\n";
                return false;
            }

            cout << "Enter User UserName: ";
            cin >> UserName;

            cout << "Enter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName);
         
            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();

        clsMainScreen::ShowMainMenue();

        return true;
    }

public:


	static bool ShowLoginScreen()
	{
        system("cls");
        _DrawScreenHeader("\t   Login Screen");
        return _Login();
       
	}
};


