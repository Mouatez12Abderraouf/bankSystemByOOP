#pragma once
#include<iostream>
#include"clsScreen.h";
#include"C:\Users\thinkbook\Source\Repos\bankProjectByOOP\bankProjectByOOP\clsBankClient.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";

using namespace std;

class clsUpdateClient : clsScreen
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
        client.setAccountBalance(clsInputValidation::readNumber<double>());

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

    static void updateClient()
    {

        _DrawScreenHeader("\t Update Client Screen");

        cout << "Enter the account number:" << endl;
        string accountNumber = clsInputValidation::readString();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "Invalid account number, please enter another account number :" << endl;
            accountNumber = clsInputValidation::readString();
        }

        clsBankClient c = clsBankClient::find(accountNumber);

        _print(c);

        cout << "\n\nUpdate client info:";
        cout << "\n__________________________\n";

        _readClientInfo(c);

        clsBankClient::enSaveResult result;

        result = c.save();

        switch (result)
        {
        case clsBankClient::svFaildEmptyObject:
            cout << "\nError acount was not saved because it's Empty";
            break;

        case clsBankClient::svSucceeded:
            cout << "\nAccount updated successfully :-)\n";
            _print(c);
            break;

        default:
            break;
        }
    }

};

