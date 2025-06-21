#pragma once
#include<iostream>
#include"clsScreen.h";
#include<iomanip>
#include"C:\Users\thinkbook\Source\Repos\bankProjectByOOP\bankProjectByOOP\clsBankClient.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;

class clsShowBalancesScreen : protected clsScreen
{
private:
    static void PrintClientBalance(clsBankClient client)
    {
        cout << setw(25) << left << "" << "| " << left << setw(15) << client.getAccountNumber();
        cout << "| " << left << setw(40) << client.getFullName();
        cout << "| " << left << setw(12) << client.getAccountBalance();
    }

public:

    

    static void ShowClientsBalances()
    {
        system("cls");

        vector<clsBankClient> vClients = clsBankClient::getClientsList();
        double total = clsBankClient::getTotalBalances();

        string title = "\t Balances List Screen";
        string subTitle =  "\t\t  ( " + to_string(vClients.size()) + " ) Client(s).";
        _DrawScreenHeader(title, subTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;


        cout << setw(25) << left << "" <<  "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;


        if (vClients.size() == 0)
        {
            cout << "\t\t\t\t\t\tNO CLIENT\n";
        }
        else
        {
            for (clsBankClient& client : vClients)
            {
                PrintClientBalance(client);
                cout << endl;
            }


            cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
            cout << "__________________________\n" << endl;


            cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << total << endl;
            cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::numberToString(total) << ")";

        }



    }
};

