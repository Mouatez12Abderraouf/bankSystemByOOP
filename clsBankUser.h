#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"C:\Users\thinkbook\Source\Repos\testClsUtilClass\testClsUtilClass\clsUtil.h";
#include"C:\Users\thinkbook\Source\Repos\testClassString\testClassString\clsString.h";
#include"C:\Users\thinkbook\Source\Repos\bankProjectByOOP\bankProjectByOOP\clsPerson.h";
#include "C:\Users\thinkbook\Source\Repos\testClsUtilClass\testClsUtilClass\clsUtil.h";

using namespace std;

string UserFile = "Users.txt";

string loginFile = "loginFile.txt";

class clsBankUser : public clsPerson
{
    struct LoginRegister;

private:

    enum enMode
    {
        emptyMode = 0, updateMode = 1, addMode = 2
    };

    string userName;
    string password;
    short permission;
    enMode mode;
    bool markToDelete = false;

    static clsBankUser convertStringToObjectUser(string data, string delim = "#//#")
    {
        vector<string> vString = clsString::splitString(data, delim);

        return clsBankUser(enMode::updateMode, vString.at(0), vString.at(1), vString.at(2), vString.at(3), vString.at(4), clsUtil::DecryptText(vString.at(5)), stoi(vString.at(6)));
    }

    static LoginRegister convertStringToLoginRecord(string data, string delim = "#//#")
    {
        vector<string> vString = clsString::splitString(data, delim);
        LoginRegister record;

        record.dateTime = vString.at(0);
        record.userName = vString.at(1);
        record.Password = clsUtil::DecryptText(vString.at(2));
        record.permission = stoi(vString.at(3));

        return record;

    }

    static string convertUserObjectToString(clsBankUser b, string delim = "#//#")
    {
        return b.getFirstName() + delim + b.getLastName() + delim + b.getEmail() + delim +
            b.getPhon() + delim + b.getUserName() + delim + clsUtil::EncryptText(b.getPassword()) + delim +
            to_string(b.permission);
    }

    static clsBankUser getEmptyUserObject()
    {
        return clsBankUser(enMode::emptyMode, "", "", "", "", "", "", 0);
    }

    void saveUserDataToFile(vector<clsBankUser> vClients)
    {
        fstream myFile;

        myFile.open(UserFile, ios::out);

        if (myFile.is_open())
        {
            string data;

            for (clsBankUser& c : vClients)
            {
                if (!c.markToDelete)
                {
                    data = convertUserObjectToString(c);
                    myFile << data << endl;

                }

            }
            myFile.close();
        }
    }

    static vector<clsBankUser> loadUsersDataFromFile()    // method of abu-hadhoud, and we can ignore 2 method (fillListOfClients, readFromFile)
    {
        fstream myFile;
        vector<clsBankUser> vUsers;

        myFile.open(UserFile, ios::in);
        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsBankUser c = convertStringToObjectUser(line);
                vUsers.push_back(c);
            }
            myFile.close();
        }
        return vUsers;
    }

    static vector<LoginRegister> loadLoginRegisterFromFile()    // method of abu-hadhoud, and we can ignore 2 method (fillListOfClients, readFromFile)
    {
        fstream myFile;
        vector<LoginRegister> LoginData;

        myFile.open(loginFile, ios::in);
        if (myFile.is_open())
        {
            string line;
            LoginRegister c;
            while (getline(myFile, line))
            {
                c = convertStringToLoginRecord(line);
                LoginData.push_back(c);
            }
            myFile.close();
        }
        return LoginData;
    }

    void update()
    {
        vector<clsBankUser> vUsers = loadUsersDataFromFile();

        for (clsBankUser& user : vUsers)
        {
            if (this->userName == user.userName)
            {
                user = *this;
                break;
            }
        }
        saveUserDataToFile(vUsers);
    }

    void addUserToFile(string s1)
    {
        fstream myFile;

        myFile.open(UserFile, ios::out | ios::app);

        if (myFile.is_open())
        {
            myFile << s1 << endl;

            myFile.close();
        }
    }

    void add()
    {
        addUserToFile(convertUserObjectToString(*this));
    }

    string prepareLoginRecord(string delim = "#//#")
    {
        return clsDate::getTotalSystemDate() + delim + getUserName() + delim + clsUtil::EncryptText(getPassword()) + delim + to_string(getPermission());
    }

    
public:

    struct LoginRegister
    {
        string dateTime;
        string userName;
        string Password;
        short permission;
    };

    static vector<LoginRegister> getLoginRegisterList()
    {
        return loadLoginRegisterFromFile();
    }

    void registerLogin()
    {
        fstream myFile;
        string data;

        data = prepareLoginRecord();

        myFile.open(loginFile, ios::out | ios::app);

        if (myFile.is_open())
        {
       
            myFile << data << endl;

            myFile.close();
        }
    }

    enum enPermissions
    {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pLoginRegister = 128, pCurrencyExchange = 256
    };

    static enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExist = 2 };

    clsBankUser(enMode mode, string firstName, string lastName, string email, string phon, string userName, string password, short permission)
        : clsPerson(firstName, lastName, email, phon)
    {
        this->mode = mode;
        this->userName = userName;
        this->password = password;
        this->permission = permission;
    }

    void setPassword(string password)
    {
        this->password = password;
    }

    void setPermission(short permission) {

        this->permission = permission;
    }

    void setUserName(string userName)
    {
        this->userName = userName;
    }

    // Getters
    string getUserName() const { return userName; }

    string getPassword() const { return password; }

    enMode getMode() const { return mode; }

    short getPermission() const { return permission; }

    //no UI in object

    /*void print()
    {
        cout << clsUtil::tab(1) << "client card\n";
        cout << "______________________________\n";
        cout << "first name : " << this->getFirstName() << endl;
        cout << "last name : " << this->getLastName() << endl;
        cout << "full name : " << this->getFullName() << endl;
        cout << "email : " << this->getEmail() << endl;
        cout << "phone : " << this->getPhon() << endl;
        cout << "account number : " << this->getAccountNumber() << endl;
        cout << "pin code : " << this->getPinCode() << endl;
        cout << "account balance : " << this->getAccountBalance() << endl;
    }*/

    vector<string> readFromFile(string fileName)
    {
        fstream myFile;
        vector<string> vString;

        myFile.open(fileName, ios::in);

        if (myFile.is_open())
        {
            string line;

            while (getline(myFile, line))
            {
                vString.push_back(line);
            }
            myFile.close();
        }
        return vString;
    }

    bool isEmpty()
    {
        return mode == enMode::emptyMode;
    }

    static clsBankUser find(string userName)
    {
        fstream myFile;

        myFile.open(UserFile, ios::in);
        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsBankUser c = convertStringToObjectUser(line);
                if (c.userName == userName)
                {
                    myFile.close();
                    return c;
                }
            }

            myFile.close();


        }
        return getEmptyUserObject();
    }

    static clsBankUser find(string userName, string password)
    {
        fstream myFile;

        myFile.open(UserFile, ios::in);
        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsBankUser c = convertStringToObjectUser(line);
                if (c.userName == userName && c.password == password)
                {
                    myFile.close();
                    return c;
                }
            }

            myFile.close();

        }
        return getEmptyUserObject();
    }

    static bool isUserExist(string userName)
    {
        clsBankUser c = find(userName);

        return (!c.isEmpty());
    }

    enSaveResult save()
    {
        switch (mode)
        {
        case emptyMode:
            return enSaveResult::svFaildEmptyObject;

        case updateMode:
            update();
            return enSaveResult::svSucceeded;

        case addMode:
            if (isUserExist(this->userName))
            {
                return enSaveResult::svFaildAccountNumberExist;
            }
            else
            {
                add();
                this->mode = enMode::updateMode;
                return enSaveResult::svSucceeded;
            }

        default:
            break;
        }
    }

    static clsBankUser getNewUser(string userName)
    {
        return clsBankUser(enMode::addMode, "", "", "", "", userName, "", 0);
    }

    bool Delete()
    {
        vector<clsBankUser> vUsers = loadUsersDataFromFile();

        for (clsBankUser& user : vUsers)
        {
            if (user.userName == this->userName)
            {
                user.markToDelete = true;
                this->markToDelete = true;
                break;
            }
        }
        if (this->markToDelete)
        {
            saveUserDataToFile(vUsers);
            *this = getEmptyUserObject();
            return true;
        }

        return false;
    }

    static vector<clsBankUser> getUsersList()
    {
        return loadUsersDataFromFile();
    }

    bool checkAccessPermission(enPermissions permission)
    {
        if (this->permission == enPermissions::eAll)
        {
            return true;
        }
        else
        {
            if ((permission & this->permission) == permission)
            {
                return true;
            }

            return false;
        }
    }

};


