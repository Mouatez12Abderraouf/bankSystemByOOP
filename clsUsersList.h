
#pragma once

#include <iostream>
#include<vector>
#include "clsScreen.h"
#include "clsBankUser.h";
#include <iomanip>

class clsUsersList :protected clsScreen
{

private:
    static void _PrintUserRecordLine(clsBankUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.getUserName();
        cout << "| " << setw(25) << left << User.getFullName();
        cout << "| " << setw(12) << left << User.getPhon();
        cout << "| " << setw(20) << left << User.getEmail();
        cout << "| " << setw(10) << left << User.getPassword();
        cout << "| " << setw(12) << left << User.getPermission();

    }

public:

    static void ShowUsersList()
    {
        vector <clsBankUser> vUsers = clsBankUser::getUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsBankUser User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};



