#pragma once


#include<iostream>
#include"clsScreen.h";
#include"clsBankUser.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;

class clsUpdateUser : protected clsScreen
{
private:
    static void _readUserInfo(clsBankUser& user)
    {
        cout << "Enter the first name:" << endl;
        user.setFirstName(clsInputValidation::readString());
        cout << "Enter the last name:" << endl;
        user.setLastName(clsInputValidation::readString());
        cout << "Enter the email:" << endl;
        user.setEmail(clsInputValidation::readString());
        cout << "Enter the phone number:" << endl;
        user.setPhon(clsInputValidation::readString());
        cout << "Enter the password:" << endl;
        user.setPassword(clsInputValidation::readString());
        cout << "Enter the permissions:" << endl;
        user.setPermission(readPermissions());

    }

    static short readPermissions()
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
        Answer = clsInputValidation::readYesOrNo();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        Answer = clsInputValidation::readYesOrNo();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        Answer = clsInputValidation::readYesOrNo();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        Answer = clsInputValidation::readYesOrNo();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        Answer = clsInputValidation::readYesOrNo();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        Answer = clsInputValidation::readYesOrNo();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        Answer = clsInputValidation::readYesOrNo();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pManageUsers;
        }

        return Permissions;


    }

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
    static void updateUser()
    {

        _DrawScreenHeader("\t Update user Screen");

        cout << "Enter the account number:" << endl;
        string userName = clsInputValidation::readString();

        while (!clsBankUser::isUserExist(userName))
        {
            cout << "Invalid user name, please enter another user name :" << endl;
            userName = clsInputValidation::readString();
        }

        clsBankUser u = clsBankUser::find(userName);

        _print(u);

        cout << "\n\nUpdate user info:";
        cout << "\n__________________________\n";

        _readUserInfo(u);

        clsBankUser::enSaveResult result;

        result = u.save();

        switch (result)
        {
        case clsBankUser::svFaildEmptyObject:
            cout << "\nError acount was not saved because it's Empty";
            break;

        case clsBankUser::svSucceeded:
            cout << "\nAccount updated successfully :-)\n";
            _print(u);
            break;

        default:
            break;
        }
    }
};

