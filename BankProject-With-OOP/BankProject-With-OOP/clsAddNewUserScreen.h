#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include<string>
#include <iomanip>
#include "clsInputValidate.h"


using namespace std;

class clsAddNewUserScreen :protected clsScreen
{

private:

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }


        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClients;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClients;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nLogin Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLoginRegister;
        }

        return Permissions;

    }

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\n\n" << "Add New User Info : ";
        cout << "\n" << "____________________\n";

        cout << "\n" << "Enter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\n" << "Enter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\n" << "Enter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\n" << "Enter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\n" << "Enter User Name: ";
        User.UserName = clsInputValidate::ReadString();

        cout << "\n" << "Enter Password: ";
        User.Password = clsInputValidate::ReadString();

        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUserInfo(clsUser User)
    {
        cout << "\n" << "User Card:";
        cout << "\n" << "___________________";
        cout << "\n" << "FirstName   : " << User.FirstName;
        cout << "\n" << "LastName    : " << User.LastName;
        cout << "\n" << "Full Name   : " << User.FullName();
        cout << "\n" << "Email       : " << User.Email;
        cout << "\n" << "Phone       : " << User.Phone;
        cout << "\n" << "UserName    : " << User.UserName;
        cout << "\n" << "Password    : " << User.Password;
        cout << "\n" << "Permissions : " << User.Permissions;
        cout << "\n" << "___________________\n";

    }

public:


    static void ShowAddNewUsersScreen()
    {

        _DrawScreenHeader("\t  Add New User Screen");

        cout << "\n" << "Please Enter User Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(AccountNumber))
        {
            cout << "\n" << "User is Exist, enter another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(AccountNumber);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        char Answer = 'n';
        cout << "Are you sure you want to add this User y/n ? ";
        cin >> Answer;
        if (tolower(Answer) == 'y') {

            SaveResult = NewUser.Save();
            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\n" << "User Added Successfully :-)\n";
                _PrintUserInfo(NewUser);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\n" << "Error User was not saved because it's Empty";
                break;

            }

            }
        }
    }
};
