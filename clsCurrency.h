#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"C:\Users\thinkbook\Source\Repos\testClassString\testClassString\clsString.h";

using namespace std;

string currencyFile = "Currencies.txt";

class clsCurrency
{
private:

	enum enMode
	{
		eEmptyMode = 0, eUpdateMode = 1
	};

	enMode mode;
	string country;
	string currencyCode;
	string currencyName;
	float rate;

	static string convertCurrencyObjectToLine(clsCurrency currency, string delim = "#//#")
	{
		return currency.country + delim + currency.currencyCode + delim
			+ currency.currencyName + delim + to_string(currency.rate);
	}

	static clsCurrency convertLineToCurrencyObject(string data, string delim = "#//#")
	{
		vector<string> vString = clsString::splitString(data, delim);

		return clsCurrency(enMode::eUpdateMode, vString.at(0), vString.at(1), vString.at(2), stod(vString.at(3)));
	}

	static vector<clsCurrency> loadCurrencyDataFromFile()
	{
		vector<clsCurrency> vCurrency;
		fstream myFile;

		myFile.open(currencyFile, ios::in);
		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsCurrency c = convertLineToCurrencyObject(line);
				vCurrency.push_back(c);
			}
			myFile.close();
		}
		return vCurrency;
	}

	static void saveCurrencyDataToFile(vector<clsCurrency> vCurrency)
	{
		fstream myFile;

		myFile.open(currencyFile, ios::out);

		if (myFile.is_open())
		{
			string data;

			for (clsCurrency& c : vCurrency)
			{
					data = convertCurrencyObjectToLine(c);
					myFile << data << endl;
			}
			myFile.close();
		}
	}

	void update()
	{
		vector<clsCurrency> vClients = loadCurrencyDataFromFile();

		for (clsCurrency& client : vClients)
		{
			if (this->currencyCode == client.currencyCode)
			{
				client = *this;
				break;
			}
		}
		saveCurrencyDataToFile(vClients);
	}

	static clsCurrency getEmptyCurrency()
	{
		return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode mode, string Country, string countryCode, string currencyName, float rate)
	{
		this->mode = mode;
		this->country = Country;
		this->currencyCode = countryCode;
		this->currencyName = currencyName;
		this->rate = rate;
	}

	static vector<clsCurrency> getAllUSDRates()
	{
		return loadCurrencyDataFromFile();
	}

	enMode getMode()
	{
		return mode;
	}

	string getCountry()
	{
		return country;
	}

	string getCurrencyCode()
	{
		return currencyCode;
	}

	string getCurrencyName()
	{
		return currencyName;
	}

	void updateRate(float rate)
	{
		this->rate = rate;
		update();
	}

	float getRate()
	{
		return rate;
	}

	bool isEmpty()
	{
		return  this->mode == enMode::eEmptyMode;
	}

	static clsCurrency findByCode(string code)
	{
		fstream myFile;

		myFile.open(currencyFile, ios::in);
		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsCurrency c = convertLineToCurrencyObject(line);
				if (c.currencyCode == clsString::UpperAllString(code))
				{
					myFile.close();
					return c;
				}
			}

			myFile.close();


		}
		return getEmptyCurrency();
	}

	static clsCurrency findByCountry(string country)
	{
		country = clsString::UpperAllString(country);
		fstream myFile;

		myFile.open(currencyFile, ios::in);
		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsCurrency c = convertLineToCurrencyObject(line);
				if (country == clsString::UpperAllString(c.country))
				{
					myFile.close();
					return c;
				}
			}

			myFile.close();


		}
		return getEmptyCurrency();
	}

	static bool isCurrencyExistByCode(string code)
	{
		return !findByCode(code).isEmpty();
	}

	static bool isCurrencyExistByCountry(string country)
	{
		return !findByCountry(country).isEmpty();
	}

	static vector<clsCurrency> getCurrencyList()
	{
		return loadCurrencyDataFromFile();
	}

	float convertAmountToUSD(float amount)
	{
		return amount / getRate();
	}

	float convertAmountToAnotherCurrency(float amount, clsCurrency currencyTo)
	{
		float amountUSD = convertAmountToUSD(amount);

		if (currencyTo.getCurrencyCode() == "USD")
		{
			return amountUSD;
		}

		return amountUSD * currencyTo.getRate();

	}

};

