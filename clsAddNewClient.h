#pragma once
#include<iostream>
#include"clsScreen.h";
#include"C:\Users\thinkbook\Source\Repos\bankProjectByOOP\bankProjectByOOP\clsBankClient.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;

class clsAddNewClient : protected clsScreen
{
private:

    static void _readClientInfo(clsBankClient& client)
    {
        cout << "Enter the first name:" << endl;
        client.setFirstName(clsInputValidation::readString());
        cout << "Enter the last name:" << endl;
        client.setLastName(clsInputValidation::readString());
        cout << "Enter the email:" << endl;
        client.setEmail(clsInputValidation::readString());
        cout << "Enter the phone number:" << endl;
        client.setPhon(clsInputValidation::readString());
        cout << "Enter the pin code:" << endl;
        client.setPinCode(clsInputValidation::readString());
        cout << "Enter the Balance:" << endl;
        client.setAccountBalance(clsInputValidation::readNumber<double>("invalid input, enter a number : "));

    }

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

    static void addNewClient()
    {
         _DrawScreenHeader("\t  Add New Client Screen");

        cout << "Enter the account number:" << endl;
        string accountNumber = clsInputValidation::readString();

        while (clsBankClient::isClientExist(accountNumber))
        {
            cout << "Invalid account number, please enter another account number:" << endl;
            accountNumber = clsInputValidation::readString();
        }

        clsBankClient client = clsBankClient::getNewClient(accountNumber);

        cout << "\nadd new client :";
        cout << "\n__________________________\n";

        _readClientInfo(client);

        clsBankClient::enSaveResult result;

        result = client.save();

        switch (result)
        {
        case clsBankClient::svFaildEmptyObject:
            cout << "\nError account was not saved because it's empty\n";
            break;

        case clsBankClient::svSucceeded:
            cout << "\nAccount Addeded Successfully :-)\n";
            _print(client);
            break;

        case clsBankClient::svFaildAccountNumberExist:
            cout << "\nthe Account is already exist.\n";
            break;

        default:
            break;
        }
    }

};

