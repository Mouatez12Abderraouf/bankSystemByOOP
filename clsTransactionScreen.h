#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsDepositScreen.h";
#include"clsWithdrawScreen.h";
#include"clsTransferLog.h";
#include"clsShowBalancesScreen.h";
#include"clsTransferScreen.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;

class clsTransactionScreen : protected clsScreen
{
private:
    enum enTransactionsMenueOptions
    {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3,eTransfer = 4, eTransferLog = 5, eShowMainMenue = 6

    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short choice = clsInputValidation::readNumberBetween<int>(1, 6, "Enter number between 1 to 6: ");
        return choice;
    }

    static void _ShowDepositScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        //cout << "\n Balances Screen will be here.\n";
        clsShowBalancesScreen::ShowClientsBalances();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::showTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLog::ShowTransferList();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionScreen();

    }



    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions choice)
    {
        switch (choice)
        {
        case clsTransactionScreen::eDeposit:

            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;

        case clsTransactionScreen::eWithdraw:

            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;

        case clsTransactionScreen::eShowTotalBalance:

            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;

        case clsTransactionScreen::eTransfer:

            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;

        case clsTransactionScreen::eTransferLog:

            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;

        case clsTransactionScreen::eShowMainMenue:

            break;

        default:
            break;
        }
    }

public:

	static void ShowTransactionScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Transaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
	}

};

