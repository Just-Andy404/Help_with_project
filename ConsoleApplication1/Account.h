#include <iostream>
#include <cstdlib>  // ��� rand() � srand()
#include <ctime>    // ��� time()
#include "Card.h"
using namespace std;

class Account 
{
private:
    string _userName;
    string _userAccount;
    string _userPassword;
    Card* _userCard;
    void writeDataToFile(const string& filename) const;

public:
    // ����������� �� ���������
    Account() : _userAccount(""), _userName(""), _userPassword(""), _userCard(nullptr) { }

    // ����������� � �����������
    Account(string userAccount, string userPassword, Card* userCard, string userName);

    // ������ ��� ��������� ��������
    void setUserAccount(const string& userAccount) {
        _userAccount = userAccount;
    }

    void setUserName(const string& userName) {
        _userName = userName;
    }

    void setUserPassword(const string& userPassword) {
        _userPassword = userPassword;
    }

    void setWhichOfCard(Card* userCard) {
        _userCard = userCard;
    }

    // ������ ��� ��������� ��������
    string getUserAccount() const {
        return _userAccount;
    }

    string getUserName() const {
        return _userName;
    }

    string getUserPassword() const {
        return _userPassword;
    }

    Card* getWhichOfCard() const {
        return _userCard;
    }

    // �������� ������
    bool checkPassword(const string& password) const {
        return _userPassword == password;
    }

    // ����� ����������
    void showInfo() const {
        cout << "User name: " << _userName << endl;
        cout << "Account: " << _userAccount << endl;
        cout << "Password: " << _userPassword << endl;
        if (_userCard) {
            _userCard->getNumsOfCard(); 
            _userCard->getBalance();
            _userCard->getValidityPeriod();

        }
        else {
            cout << "No card associated." << endl;
        }


    
    }

};
