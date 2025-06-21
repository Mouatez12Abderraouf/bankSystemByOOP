#pragma once

#include<iostream>
#include"clsBankUser.h";
#include"clsScreen.h";
#include"clsMainScreen.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
#include"Global.h";
using namespace std;

class clsLoginScreen : protected clsScreen
{
	
private:

	
	static bool Login()
	{
		string userName, password;
		bool failLogin = false;
		short heart = 3;
		do
		{
			

			cout << "Enter user name: \n";
			userName = clsInputValidation::readString();

			cout << "Enter password: \n";
			password = clsInputValidation::readString();

			currentUser = clsBankUser::find(userName, password);

			failLogin = currentUser.isEmpty();

			if (failLogin)
			{
				heart--;
				cout << "\nInvalid (user name / password) \n" << endl;
				cout << "You have " << heart << " Trials to login.\n\n";
			}

		} while (failLogin && heart != 0);

		if (heart != 0)
		{
			currentUser.registerLogin();
			clsMainScreen::ShowMainMenu();
			return true;
		}
		else
		{
			cout << "Your are Locked after 3 faild trails.\n\n\n";
			return false;
		}

		
	}


public:

	static bool showLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return Login();
	}
};

