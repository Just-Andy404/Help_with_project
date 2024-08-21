#include "Account.h"

#include <fstream>
#include <string>
using namespace std;


void Account::writeDataToFile(const string& filename) const {
    ofstream out(filename, ios::binary | ios::trunc | ios::out);
    if (out.is_open()) {
        // Запись строк (сначала длина строки, потом сама строка)
        size_t accountSize = _userAccount.size();
        size_t passwordSize = _userPassword.size();
        size_t nameSize = _userName.size();

        out.write(reinterpret_cast<const char*>(&accountSize), sizeof(accountSize));
        out.write(_userAccount.c_str(), accountSize);

        out.write(reinterpret_cast<const char*>(&passwordSize), sizeof(passwordSize));
        out.write(_userPassword.c_str(), passwordSize);

        out.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
        out.write(_userName.c_str(), nameSize);

        // Убедитесь, что метод writeToFile существует в Card, если он нужен
        // if (_userCard) {
        //     _userCard->writeToFile(out);
        // }

        out.close(); // Закрытие файла
    }
    else {
        cerr << "Unable to open file for writing" << endl;
    }
}


Account::Account(string userAccount, string userPassword, Card* userCard, string userName)
    : _userAccount(userAccount), _userPassword(userPassword), _userCard(userCard), _userName(userName) {
    writeDataToFile("account_data.bin");
}

