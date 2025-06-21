#pragma once

#include<iostream>
#include"clsScreen.h";
#include"clsBankUser.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;

class clsFindUser : protected clsScreen
{
private:
    static void _print(clsBankUser user)
    {
        cout << clsUtil::tab(1) << "user card\n";
        cout << "______________________________\n";
        cout << "first name : " << user.getFirstName() << endl;
        cout << "last name : " << user.getLastName() << endl;
        cout << "full name : " << user.getFullName() << endl;
        cout << "email : " << user.getEmail() << endl;
        cout << "phone : " << user.getPhon() << endl;
        cout << "account number : " << user.getUserName() << endl;
        cout << "pin code : " << user.getPassword() << endl;
        cout << "account balance : " << user.getPermission() << endl;

    }

public:

    static void findClient()
    {
        _DrawScreenHeader("\t Find user Screen");

        cout << "Enter the user name :\n";
        string userName = clsInputValidation::readString();

        while (!clsBankUser::isUserExist(userName))
        {
            cout << "the user isn't found, Enter the user name :\n";
            userName = clsInputValidation::readString();
        }

        clsBankUser user = clsBankUser::find(userName);

        if (!user.isEmpty())
        {
            cout << "User Found :-)\n\n";
        }
        else
        {
            cout << "User not found.\n\n";
        }

        _print(user);
    }
};

