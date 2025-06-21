

#pragma once
#include<iostream>
#include"clsScreen.h";
#include"C:\Users\thinkbook\Source\Repos\bankProjectByOOP\bankProjectByOOP\clsBankClient.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;


class ClsDeleteUser : clsScreen
{
private:

    static void _print(clsBankUser user)
    {
        cout << clsUtil::tab(1) << "client card\n";
        cout << "______________________________\n";
        cout << "first name : " << user.getFirstName() << endl;
        cout << "last name : " << user.getLastName() << endl;
        cout << "full name : " << user.getFullName() << endl;
        cout << "email : " << user.getEmail() << endl;
        cout << "phone : " << user.getPhon() << endl;
        cout << "user name : " << user.getUserName() << endl;
        cout << "password : " << user.getPassword() << endl;
        cout << "account permission : " << user.getPermission() << endl;

    }


public:

    static void deleteUser()
    {

        _DrawScreenHeader("\t Delete User Screen");

        string userName;

        cout << "Enter the user Name :\n";
        userName = clsInputValidation::readString();

        while (!clsBankUser::isUserExist(userName))
        {
            cout << "no user exist, Enter the rigth user Name :\n";
            userName = clsInputValidation::readString();
        }

        clsBankUser user = clsBankUser::find(userName);

        _print(user);
        char check = 'n';

        cout << "\nDo you want to delete this user [y/n]? :";
        check = clsInputValidation::readYesOrNo();

        if (toupper(check) == 'Y')
        {

            if (user.Delete())
            {
                cout << "\nUser delete Successfully :-)\n\n";
                _print(user);
            }
            else
            {
                cout << "\nError user was not deleted\n";
            }
        }

    }

};



