#pragma once

#include<iostream>
#include <iomanip>
#include"clsScreen.h";
#include"clsUsersList.h";
#include"clsAddUser.h";
#include"ClsDeleteUser.h";
#include"clsUpdateUser.h";
#include"clsFindUser.h";
#include"C:\Users\thinkbook\Source\Repos\testClsInput&VaelidationClass\testClsInput&VaelidationClass\clsInputValidation.h";
using namespace std;

class clsManageUsers : protected clsScreen
{

private:

	enum enMenuUserOp
	{
		eShowListUsers = 1, eAddUser = 2, eDeleteUser = 3, eUpdateUser = 4,
		eFindUser = 5, eMainMenu = 6
	};

	static short _readManageMenuOp()
	{
		short choice;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		choice = clsInputValidation::readNumberBetween<int>(1, 6, "enter number between 1 to 6:");
		return choice;
	}

	static void ShowListUsers()
	{
		//cout << "\nshow Users list Screen Will be here...\n";
		clsUsersList::ShowUsersList();

	}

	static void AddUser()
	{
		//cout << "\nadd User Screen Will be here...\n";
		clsAddUser::addNewClient();
	}

	static void DeleteUser()
	{
		//cout << "\ndelete User Screen Will be here...\n";
		ClsDeleteUser::deleteUser();

	}

	static void UpdateUser()
	{
		//cout << "\nupdate User Screen Will be here...\n";
		clsUpdateUser::updateUser();
	}

	static void FindUser()
	{
		//cout << "\nfind User Screen Will be here...\n";
		clsFindUser::findClient();
	}

	static void _GoBackToManageMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Menue...\n";

		system("pause>0");
		showManageMenu();
	}

	static void _PerfromManageMenueOption(enMenuUserOp choice)
	{
		switch (choice)
		{
		case clsManageUsers::eShowListUsers:
			system("cls");
			ShowListUsers();
			_GoBackToManageMenue();

			break;
		case clsManageUsers::eAddUser:
			system("cls");
			AddUser();
			_GoBackToManageMenue();
			break;
		case clsManageUsers::eDeleteUser:
			system("cls");
			DeleteUser();
			_GoBackToManageMenue();
			break;
		case clsManageUsers::eUpdateUser:
			system("cls");
			UpdateUser();
			_GoBackToManageMenue();
			break;
		case clsManageUsers::eFindUser:
			system("cls");
			FindUser();
			_GoBackToManageMenue();
			break;
		case clsManageUsers::eMainMenu:

			break;

		default:
			break;
		}
	}

public:

	static void showManageMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tManage user Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tManage Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "[1] Show User List.\n";
		cout << setw(37) << left << "" << "[2] Add New User.\n";
		cout << setw(37) << left << "" << "[3] Delete User.\n";
		cout << setw(37) << left << "" << "[4] Update User Info.\n";
		cout << setw(37) << left << "" << "[5] Find User.\n";
		cout << setw(37) << left << "" << "[6] Main menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";


		_PerfromManageMenueOption((enMenuUserOp)_readManageMenuOp());
	}

};


