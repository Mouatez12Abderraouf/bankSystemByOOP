#pragma once
#include<iostream>
#include"clsScreen.h"
#include"C:\Users\thinkbook\Source\Repos\bankProjectByOOP\bankProjectByOOP\clsBankClient.h";
using namespace std;

class clsClientListScreen : protected clsScreen
{
private:

    static void _PrintClientRecordLine(clsBankClient client)
    {
        cout << setw(8) << left << "" << "| " << left << setw(15) << client.getAccountNumber();
        cout << "| " << left << setw(20) << client.getFullName();
        cout << "| " << left << setw(12) << client.getPhon();
        cout << "| " << left << setw(20) << client.getEmail();
        cout << "| " << left << setw(10) << client.getPinCode();
        cout << "| " << left << setw(12) << client.getAccountBalance();
    }

public:

    static void ShowClientsList()
    {
        vector<clsBankClient> vClients = clsBankClient::getClientsList();

        string title = "\t  Client list Screen";
        string subTitle = "\t    ( " + to_string(vClients.size()) + " ) Client(s).";

        _DrawScreenHeader(title, subTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
        {
            cout << "\t\t\t\t\t\tNO CLIENT\n";
        }
        else
        {
            for (clsBankClient Client : vClients)
            {
                _PrintClientRecordLine(Client);
                cout << endl;
            }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

        }

    }

};

