#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h";
#include <iomanip>

class clsLoginRegisterScreen :protected clsScreen
{

private:

    static void _PrintLoginRegister(clsBankUser::LoginRegister data)
    {

        cout << setw(8) << left << "" << "| " << left << setw(35) << data.dateTime;
        cout << "| " << left << setw(15) << data.userName;
        cout << "| " << left << setw(12) << data.Password;
        cout << "| " << left << setw(12) << data.permission;

    }

public:

    static void ShowLoginRegisterList()
    {
        vector<clsBankUser::LoginRegister> vData = clsBankUser::getLoginRegisterList();

        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vData.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(15) << "user Name";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vData.size() == 0)
            cout << "\t\t\t\tNo Login Available In the System!";
        else

            for (clsBankUser::LoginRegister data : vData)
            {

                _PrintLoginRegister(data);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};





