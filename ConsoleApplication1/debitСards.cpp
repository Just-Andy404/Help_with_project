#include <fstream>
#include "debit—ards.h"


void DebitCard::addMoney()
{
    double Money = 0.0;
    cout << "How much money do you want to add: ";
    cin >> Money;
    cout << endl;
    _balance += Money;

    ofstream out("transactions.bin", ios::binary | ios::trunc | ios::out);
    if (out.is_open()) {
        out.write(reinterpret_cast<char*>(&_balance), sizeof(_balance));
        out.close(); 
    }
    else {
        cerr << "Unable to open file for writing" << endl;
    }

}

void DebitCard::payment()
{

}

double DebitCard::getHowMuchMoney(const string& filename) {
    double number = 0.0;
    ifstream in(filename, ios::binary | ios::in);
    if (in.is_open()) {
        in.read(reinterpret_cast<char*>(&number), sizeof(number));
        in.close(); 
    }
    else {
        cerr << "Unable to open file for reading" << endl;
    }
    return number;
}
