#pragma once

#include<iostream>
#include"clsScreen.h";
#include"clsCurrency.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";

using namespace std;

class clsFindCurrency : protected clsScreen
{
private:

	static void print(clsCurrency currency)
	{
		cout << "currency card\n\n";
		cout << "---------------------\n\n";
		cout << "Country   : " << currency.getCountry() << endl;
		cout << "Code      : " << currency.getCurrencyCode() << endl;
		cout << "Name      : " << currency.getCurrencyName() << endl;
		cout << "Rate(1$)  = " << currency.getRate() << endl;
		cout << "\n---------------------\n";

	}

	static void findByCode()
	{
		cout << "Enter currency code :";
		string code = clsInputValidation::readString();

		clsCurrency currency = clsCurrency::findByCode(code);

		if (!currency.isEmpty())
		{
			cout << "\n\ncurrency found :-)\n\n";
			
		}
		else
		{
			cout << "\n\ncurrency isn't found.\n\n";
		}

		print(currency);
		
	}

	static void findByCountry()
	{
		cout << "Enter currency country :";
		string country = clsInputValidation::readString();

		clsCurrency currency = clsCurrency::findByCountry(country);

		if (currency.isEmpty())
		{
			cout << "currency isn't found.\n\n";
			
		}
		else
		{
			cout << "currency found :-)\n\n";
		}

		print(currency);

	}

public:

	static void findCurrency()
	{
		system("cls");
		_DrawScreenHeader("Find currency screen");

		cout << "Find by: [1] code or [2] country? ";
		short choice = clsInputValidation::readNumberBetween<int>(1, 2, "choice 1 or 2 ?");

		if (choice == 1)
		{
			findByCode();
		}
		else
		{
			findByCountry();
		}

	}
};

