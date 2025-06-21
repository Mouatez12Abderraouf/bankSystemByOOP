#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsCurrency.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";

using namespace std;

class clsCurrencyCalculator : protected clsScreen
{
private:

	static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{

		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << Currency.getCountry();
		cout << "\nCode          : " << Currency.getCurrencyCode();
		cout << "\nName          : " << Currency.getCurrencyName();
		cout << "\nRate(1$) =    : " << Currency.getRate();
		cout << "\n_____________________________\n\n";

	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.convertAmountToUSD(Amount);

		cout << Amount << " " << Currency1.getCurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.getCurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrrency2 = Currency1.convertAmountToAnotherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.getCurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.getCurrencyCode();

	}


public:

	static void calculatorCurrency()
	{
		string code1, code2;
		float AmountExchange, result;
		char choice;

		do
		{
			system("cls");
			_DrawScreenHeader("Calculator currency screen");

			cout << "Enter currency 1 code : ";
			code1 = clsInputValidation::readString();

			while (!clsCurrency::isCurrencyExistByCode(code1))
			{
				cout << "the currency isn't exist, Enter another currency code : ";
				code1 = clsInputValidation::readString();
			}

			cout << "Enter currency 2 code : ";
			code2 = clsInputValidation::readString();

			while (!clsCurrency::isCurrencyExistByCode(code2))
			{
				cout << "the currency isn't exist, Enter another currency code : ";
				code2 = clsInputValidation::readString();
			}

			cout << "Enter amount to exchange : ";

			AmountExchange = clsInputValidation::readNumber<double>();

			clsCurrency currencyFrom = clsCurrency::findByCode(code1);

			clsCurrency currencyTo = clsCurrency::findByCode(code2);

			_PrintCalculationsResults(AmountExchange, currencyFrom, currencyTo);

			cout << "\nDo you want to perform another calculation? [y/n]? ";
			choice = clsInputValidation::readYesOrNo();

		} while (toupper(choice) == 'Y');


	}
};

