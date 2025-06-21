#pragma once
#include<iostream>
#include"clsScreen.h";
#include"C:\Users\thinkbook\Source\Repos\bankProjectByOOP\bankProjectByOOP\clsBankClient.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;


class clsDeleteClient : clsScreen
{
private:

    static void _print(clsBankClient client)
    {
        cout << clsUtil::tab(1) << "client card\n";
        cout << "______________________________\n";
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

    static void deleteClient()
    {

        _DrawScreenHeader("\t Delete Client Screen");

        string accountNumber;

        cout << "Enter the account number :\n";
        accountNumber = clsInputValidation::readString();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "no client exist, Enter the rigth account number :\n";
            accountNumber = clsInputValidation::readString();
        }

        clsBankClient client = clsBankClient::find(accountNumber);

        _print(client);
        char check = 'n';

        cout << "\nDo you want to delete this client [y/n]? :";
        check = clsInputValidation::readYesOrNo();

        if (toupper(check) == 'Y')
        {

            if (client.Delete())
            {
                cout << "\nClient delete Successfully :-)\n\n";
                _print(client);
            }
            else
            {
                cout << "\nError client was not deleted\n";
            }
        }

    }

};

