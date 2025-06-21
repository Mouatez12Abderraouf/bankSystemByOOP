#pragma once
#include<iostream>
#include"clsScreen.h";
#include"C:\Users\thinkbook\Source\Repos\bankProjectByOOP\bankProjectByOOP\clsBankClient.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;

class clsWithdrawScreen : clsScreen
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
        cout << "___________________________________\n";

    }

    static string _readAccountNumber()
    {
        string accountNumber;
        cout << "Enter the account number :\n";
        accountNumber = clsInputValidation::readString();
        return accountNumber;
    }

public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t withdraw Screen");

        string accountNumber = _readAccountNumber();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "\nClient with account number [" << accountNumber << "] isn't exist.\n";
            accountNumber = _readAccountNumber();
        }

        clsBankClient client = clsBankClient::find(accountNumber);
        _print(client);

        cout << "Please Enter withdraw Amount: ";
        double amount = clsInputValidation::readNumber<double>();

        cout << "Are you sure you want to preform this transaction [y/n]? : ";
        char off_on;
        off_on = clsInputValidation::readYesOrNo();

        if (toupper(off_on) == 'Y')
        {
            if (client.withdraw(amount))
            {
                cout << "\nAmount withdraw Successfully.\n";
                cout << "\nNew Balance Is: " << client.getAccountBalance();
            }
            else
            {
                cout << "\ncannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmount to withdrw is: " << amount;
                cout << "\nYour Balance is: " << client.getAccountBalance();
            }

        }
        else
        {
            cout << "\nOperation war cancelled.\n";
        }
    }
};

