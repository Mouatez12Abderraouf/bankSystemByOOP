#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsCurrency.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";

using namespace std;

class clsUpdateCurrency : protected clsScreen
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

public:

	static void updateCurrencyRate()
	{
		_DrawScreenHeader("update currency rate");

		cout << "Enter currency code : ";
		string code = clsInputValidation::readString();

		while (!clsCurrency::isCurrencyExistByCode(code))
		{
			cout << "the currency isn't exist, Enter another currency code : ";
		    code = clsInputValidation::readString();
		}

		clsCurrency currency = clsCurrency::findByCode(code);

		print(currency);

		cout << "Are you sure to update currency rate? [y/n]? :";
		char choice = clsInputValidation::readYesOrNo();

		if (toupper(choice) == 'Y')
		{
			cout << "\n\nUpdate currency rate:\n";
			cout << "____________________________\n\n";

			cout << "Enter new rate: ";
			float newRate = clsInputValidation::readNumber<double>();

			currency.updateRate(newRate);

		}
		cout << "\n\n";

		print(currency);
		
	}

};

