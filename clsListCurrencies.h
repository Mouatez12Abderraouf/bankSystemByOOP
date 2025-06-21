#pragma once

#include<iostream>
#include"clsScreen.h";
#include"clsCurrency.h";
using namespace std;

class clsListCurrencies : protected clsScreen
{
private:

    static void _PrintClientRecordLine(clsCurrency currency)
    {
        cout << setw(8) << left << "" << "| " << left << setw(29) << currency.getCountry();
        cout << "| " << left << setw(12) << currency.getCurrencyCode();
        cout << "| " << left << setw(40) << currency.getCurrencyName();
        cout << "| " << left << setw(8) << currency.getRate();

    }

public:

    static void ShowClientsList()
    {
        vector<clsCurrency> vCurrency = clsCurrency::getCurrencyList();

        string title = "\t  Client list Screen";
        string subTitle = "\t    ( " + to_string(vCurrency.size()) + " ) Client(s).";

        _DrawScreenHeader(title, subTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(29) << "Country";
        cout << "| " << left << setw(12) << "Currency Code";
        cout << "| " << left << setw(40) << "Currency Name";
        cout << "| " << left << setw(8) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrency.size() == 0)
        {
            cout << "\t\t\t\t\t\tNO CURRENCY\n";
        }
        else
        {
            for (clsCurrency currency : vCurrency)
            {
                _PrintClientRecordLine(currency);
                cout << endl;
            }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

        }

    }

};





