#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h";
#include"Global.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
#include"C:\Users\thinkbook\Source\Repos\bankProjectByOOP\bankProjectByOOP\clsBankClient.h";
#include <iomanip>
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

	static void print(clsBankClient client)
	{
		cout << "client card\n";
		cout << "_______________\n\n";
		cout << "full name: " << client.getFullName() << endl;
		cout << "Acc number: " << client.getAccountNumber() << endl;
		cout << "Balance: " << client.getAccountBalance() << "\n";
		cout << "_______________\n\n";

	}


public:
	static void showTransferScreen()
	{
		system("cls");
		_DrawScreenHeader("Transfer Screen");

		string sendAccount, receiverAccount;

		cout << "Please Enter account number to transfer from:\n";
		sendAccount = clsInputValidation::readString();

		while (!clsBankClient::isClientExist(sendAccount))
		{
			cout << "the account isn't exist, Enter another account number:\n";
			sendAccount = clsInputValidation::readString();

		}

		clsBankClient sendClient = clsBankClient::find(sendAccount);

		print(sendClient);

		cout << "Please Enter account number to transfer to:\n";
		receiverAccount = clsInputValidation::readString();

		while (!clsBankClient::isClientExist(receiverAccount))
		{
			cout << "the account isn't exist, Enter another account number:\n";
			receiverAccount = clsInputValidation::readString();

		}

		clsBankClient receiverClient = clsBankClient::find(receiverAccount);

		print(receiverClient);

		double amount;

		cout << "Enter transfer amount: ";
		amount = clsInputValidation::readNumber<double>();

		while (sendClient.getAccountBalance() < amount)
		{
			cout << "Amount Exceeds the available balance, Enter another amount: ";
			amount = clsInputValidation::readNumber<double>();

		}

		cout << "Are you sure you want to preform this transaction [y/n]? : ";
		char off_on;
		off_on = clsInputValidation::readYesOrNo();

		if (toupper(off_on) == 'Y')
		{
			if (sendClient.transfer(amount, receiverClient, currentUser.getUserName()))
			{
				cout << "\nTransfer done Successfully.\n";
			}
			else
			{
				cout << "\ncannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to withdrw is: " << amount;
				cout << "\nYour Balance is: " << sendClient.getAccountBalance();
			}

		}
		else
		{
			cout << "\nOperation war cancelled.\n";
		}

		print(sendClient);
		print(receiverClient);
		
	}

};

