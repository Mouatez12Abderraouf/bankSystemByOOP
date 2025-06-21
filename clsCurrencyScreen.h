#pragma once
#include<iostream>
#include <iomanip>
#include"clsScreen.h";
#include"clsListCurrencies.h";
#include"clsFindCurrency.h";
#include"clsUpdateCurrency.h";
#include"clsCurrencyCalculator.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";

using namespace std;

class clsCurrencyScreen : protected clsScreen
{
private:
	enum enCurrencyOp
	{
		eShowListCurrency= 1, eFindCurrency = 2, eUpdateCurrencyRate = 3, eCurrencyCalculator = 4, eMainMenu = 5
	};

	static  void _GoBackToCurrencyMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Menu...\n";

		system("pause>0");
		ShowCurrencyMenu();
	}

	static short _readCurrencyMenuOp()
	{
		short choice;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		choice = clsInputValidation::readNumberBetween<int>(1, 5, "enter number between 1 to 5:");
		return choice;
	}

	static void ShowListCurrency()
	{
		//cout << "\nShow currency list Screen Will be here...\n";
		clsListCurrencies::ShowClientsList();
		
	}

	static void UpdateCurrencyRate()
	{
		//cout << "\nupdate currency rate Screen Will be here...\n";
		clsUpdateCurrency::updateCurrencyRate();

	}

	static void CurrencyCalculator()
	{
		//cout << "\nCalculator currency rate Screen Will be here...\n";
		clsCurrencyCalculator::calculatorCurrency();
	}

	static void FindCurrency()
	{
		//cout << "\nFind currency Screen Will be here...\n";
		clsFindCurrency::findCurrency();
		
	}

	static void _PerfromMainMenueOption(enCurrencyOp choice)
	{
		switch (choice)
		{
		case enCurrencyOp::eShowListCurrency:
			system("cls");
			ShowListCurrency();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOp::eFindCurrency:
			system("cls");
			FindCurrency();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOp::eUpdateCurrencyRate:
			system("cls");
			UpdateCurrencyRate();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOp::eCurrencyCalculator:
			system("cls");
			CurrencyCalculator();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOp::eMainMenu:
			
			break;

		default:
			break;
		}
	}

public:

	static void ShowCurrencyMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tCurrency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "[1] List Currencies .\n";
		cout << setw(37) << left << "" << "[2] Find currency.\n";
		cout << setw(37) << left << "" << "[3] Update currency rate.\n";
		cout << setw(37) << left << "" << "[4] Currency calculator.\n";
		cout << setw(37) << left << "" << "[5] Main menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";


		_PerfromMainMenueOption((enCurrencyOp)_readCurrencyMenuOp());

	}
};

