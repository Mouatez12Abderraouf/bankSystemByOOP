#pragma once
#include<iostream>
#include <iomanip>
#include"clsScreen.h";
#include"clsClientListScreen.h";
#include"clsAddNewClient.h";
#include"clsUpdateClient.h";
#include"clsDeleteClient.h";
#include"clsFindClientScreen.h";
#include"clsTransactionScreen.h";
#include"clsManageUsers.h";
#include"Global.h";
#include"clsLoginRegisterScreen.h";
#include"clsCurrencyScreen.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum enMenuOp
	{
		eShowListClients = 1, eAddClient = 2, eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eTransactions = 6, eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eLogout = 10
	};

	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenu();
	}

	static short _readMainMenuOp()
	{
		short choice;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
		choice = clsInputValidation::readNumberBetween<int>(1, 9, "enter number between 1 to 9:");
		return choice;
	}

	static void ShowListClients()
	{
		//cout << "\nshow clients list Screen Will be here...\n";
		if (!checkAccessRigth(clsBankUser::enPermissions::pListClients))
		{
			return;
		}
		clsClientListScreen::ShowClientsList();
	}

	static void AddClient()
	{
		//cout << "\nadd client Screen Will be here...\n";
		if (!checkAccessRigth(clsBankUser::enPermissions::pAddNewClient))
		{
			return;
		}
		clsAddNewClient::addNewClient();
	}

	static void DeleteClient()
	{
		//cout << "\ndelete client Screen Will be here...\n";
		if (!checkAccessRigth(clsBankUser::enPermissions::pDeleteClient))
		{
			return;
		}
		clsDeleteClient::deleteClient();
	}

	static void UpdateClient()
	{
		//cout << "\nupdate client Screen Will be here...\n";
		if (!checkAccessRigth(clsBankUser::enPermissions::pUpdateClients))
		{
			return;
		}
		clsUpdateClient::updateClient();
	}

	static void FindClient()
	{
		//cout << "\nfind client Screen Will be here...\n";
		if (!checkAccessRigth(clsBankUser::enPermissions::pFindClient))
		{
			return;
		}
		clsFindClientScreen::findClient();
	}

	static void Transactions()
	{
		//cout << "\nTransactions client Screen Will be here...\n";
		if (!checkAccessRigth(clsBankUser::enPermissions::pTranactions))
		{
			return;
		}
		clsTransactionScreen::ShowTransactionScreen();
	}

	static void ManageUsers()
	{
		//cout << "\nManage users Screen Will be here...\n";
		if (!checkAccessRigth(clsBankUser::enPermissions::pManageUsers))
		{
			return;
		}

		clsManageUsers::showManageMenu();
	}

	static void ShowLoginRegister()
	{
		if (!checkAccessRigth(clsBankUser::enPermissions::pLoginRegister))
		{
			return;
		}

		clsLoginRegisterScreen::ShowLoginRegisterList();
	}

	static void Logout()
	{
		//cout << "\nEnd Screen Will be here...\n";
		currentUser = clsBankUser::find("");
		
	}

	static void currencyExchange()
	{
		if (!checkAccessRigth(clsBankUser::enPermissions::pCurrencyExchange))
		{
			return;
		}
		clsCurrencyScreen::ShowCurrencyMenu();
	}

	static void _PerfromMainMenueOption(enMenuOp choice)
	{
		switch (choice)
		{
		case clsMainScreen::eShowListClients:
			system("cls");
			ShowListClients();
			_GoBackToMainMenue();
			break;

		case clsMainScreen::eAddClient:
			system("cls");
			AddClient();
			_GoBackToMainMenue();
			break;

		case clsMainScreen::eDeleteClient:
			system("cls");
			DeleteClient();
			_GoBackToMainMenue();
			break;

		case clsMainScreen::eUpdateClient:
			system("cls");
			UpdateClient();
			_GoBackToMainMenue();
			break;

		case clsMainScreen::eFindClient:
			system("cls");
			FindClient();
			_GoBackToMainMenue();
			break;

		case clsMainScreen::eTransactions:
			system("cls");
			Transactions();
			_GoBackToMainMenue();
			break;

		case clsMainScreen::eManageUsers:
			system("cls");
			ManageUsers();
			_GoBackToMainMenue();
			break;

		case clsMainScreen::eLoginRegister:
			system("cls");
			ShowLoginRegister();
			_GoBackToMainMenue();
			break;

		case clsMainScreen::eCurrencyExchange:
			system("cls");
			currencyExchange();
			_GoBackToMainMenue();
			break;

		case clsMainScreen::eLogout:
			system("cls");
			Logout();
			break;

		default:
			break;
		}
	}

public:

	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "[1] Show Client List.\n";
		cout << setw(37) << left << "" << "[2] Add New Client.\n";
		cout << setw(37) << left << "" << "[3] Delete Client.\n";
		cout << setw(37) << left << "" << "[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "[5] Find Client.\n";
		cout << setw(37) << left << "" << "[6] Transactions.\n";
		cout << setw(37) << left << "" << "[7] Manage Users.\n";
		cout << setw(37) << left << "" << "[8] Login Register.\n";
		cout << setw(37) << left << "" << "[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";


		_PerfromMainMenueOption((enMenuOp)_readMainMenuOp());

	}
};

