#pragma once

#include<iostream>
#include "clsScreen.h"
#include"C:\Users\thinkbook\Source\Repos\bankProjectByOOP\bankProjectByOOP\clsBankClient.h";
#include <iomanip>
using namespace std;

class clsTransferLog : protected clsScreen
{
private:

    static void _PrintTransferRecordLine(clsBankClient::transferLog data)
    {

        cout << setw(8) << left << "" << "| " << setw(22) << left << data.dateTime;
        cout << "| " << setw(10) << left << data.sendAccount;
        cout << "| " << setw(10) << left << data.receiveAccount;
        cout << "| " << setw(8) << left << data.amount;
        cout << "| " << setw(8) << left << data.sAmount;
        cout << "| " << setw(8) << left << data.dAmount;
        cout << "| " << setw(15) << left << data.userName;


    }

public:

    static void ShowTransferList()
    {
        vector <clsBankClient::transferLog> vUsers = clsBankClient::getTransferLogList();

        string Title = "\t  transfer log List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << setw(22) << left << "date/time";
        cout << "| " << setw(10) << left << "s.Account";
        cout << "| " << setw(10) << left << "d.Acccount";
        cout << "| " << setw(8) << left << "Amount";
        cout << "| " << setw(8) << left << "s.Amount";
        cout << "| " << setw(8) << left << "d.Amount";
        cout << "| " << setw(12) << left << "user Name";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo transfer Available In the System!";
        else

            for (clsBankClient::transferLog User : vUsers)
            {

                _PrintTransferRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

