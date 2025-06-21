#pragma once
#include<iostream>
#include"clsScreen.h";
#include"C:\Users\thinkbook\Source\Repos\bankProjectByOOP\bankProjectByOOP\clsBankClient.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;

class clsFindClientScreen : clsScreen
{
private:

    static void _print(clsBankClient client)
    {
        cout << clsUtil::tab(1) << "client card\n";
        cout << "___________________________________\n";
        cout << "first name : " << client.getFirstName() << endl;
        cout << "last name : " << client.getLastName() << endl;
        cout << "full name : " << client.getFullName() << endl;
        cout << "email : " << client.getEmail() << endl;
        cout << "phone : " << client.getPhon() << endl;
        cout << "account number : " << client.getAccountNumber() << endl;
        cout << "pin code : " << client.getPinCode() << endl;
        cout << "account balance : " << client.getAccountBalance() << endl;

    }

public:

    static void findClient()
    {
        _DrawScreenHeader("\t Find Client Screen");

        cout << "Enter the Account Number :\n";
        string accountNumber = clsInputValidation::readString();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "the client isn't found, Enter the Account Number :\n";
            string accountNumber = clsInputValidation::readString();
        }

        clsBankClient client = clsBankClient::find(accountNumber);

        if (!client.isEmpty())
        {
            cout << "Client Found :-)\n\n";
        }
        else
        {
            cout << "Client not found.\n\n";
        }

        _print(client);
    }
};

