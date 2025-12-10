#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginRegisterScreen : protected clsScreen
{

private:

    static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord RegisterUser)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << RegisterUser.DateTime;            ;
        cout << "| " << setw(20) << left << RegisterUser.UserName;
        cout << "| " << setw(20) << left << RegisterUser.Password;
        cout << "| " << setw(20) << left << RegisterUser.Permission;

    }

public:


    static void ShowLoginRegisterScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vRegisterUsers = clsUser::GetLoginRegisterList();

        string Title = "\t  Login Register Screen";
        string SubTitle = "\t    (" + to_string(vRegisterUsers.size()) + ") Register User(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t__________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << setw(35) << left << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(20) << "Permissions";
        cout << setw(8) << left << "" << "\n\t__________________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vRegisterUsers.size() == 0)
            cout << "\t\t\t\tNo RegisterUsers Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord Record : vRegisterUsers)
            {

                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t__________________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};



