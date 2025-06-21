#pragma once

#include<iostream>
#include"clsScreen.h";
#include"clsBankUser.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;

class clsAddUser : protected clsScreen
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

        cout << "\nShow Login Register? y/n? ";
        Answer = clsInputValidation::readYesOrNo();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pLoginRegister;
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
        cout << "user name : " << user.getUserName() << endl;
        cout << "password : " << user.getPassword() << endl;
        cout << "permissions : " << user.getPermission() << endl;

    }

public:

    static void addNewClient()
    {
        _DrawScreenHeader("\t  Add New user Screen");

        cout << "Enter the user name :" << endl;
        string userName = clsInputValidation::readString();

        while (clsBankUser::isUserExist(userName))
        {
            cout << "Invalid user name, please enter another user name:" << endl;
            userName = clsInputValidation::readString();
        }

        clsBankUser user = clsBankUser::getNewUser(userName);

        cout << "\nadd new client :";
        cout << "\n__________________________\n";

        _readUserInfo(user);

        clsBankUser::enSaveResult result;

        result = user.save();

        switch (result)
        {
        case clsBankUser::svFaildEmptyObject:
            cout << "\nError account was not saved because it's empty\n";
            break;

        case clsBankUser::svSucceeded:
            cout << "\nAccount Addeded Successfully :-)\n";
            _print(user);
            break;

        case clsBankUser::svFaildAccountNumberExist:
            cout << "\nthe Account is already exist.\n";
            break;

        default:
            break;
        }
    }

};



