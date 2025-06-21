#pragma once
#include<iostream>
#include"Global.h"
#include"C:\Users\thinkbook\Source\Repos\testClassDate\testClassDate\clsDate.h";
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\t User : " << currentUser.getUserName() << endl;
        cout << "\t\t\t\t\t Date : " << clsDate::dateToString(clsDate()) << "\n\n";

    }

    static bool checkAccessRigth(clsBankUser::enPermissions permission)
    {
        if (!currentUser.checkAccessPermission(permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! contact your Admin";
            cout << "\n\t\t\t\t\t______________________________________";

            return false;
        }

        return true;
    }

};

