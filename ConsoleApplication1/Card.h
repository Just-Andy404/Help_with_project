#include <iostream>
#include <string>
#include <cstdlib>  // Для rand() и srand()
#include <ctime>    // Для time()

using namespace std;

// Базовый класс Card
class Card {
protected:
    int _NumsOfCard[17];  // Массив для хранения 16-значного числа
    double _balance;
    int _validity_period[6];

public:
    Card() : _balance(0.0) {
        for (int i = 0; i < 16; ++i) {
            _NumsOfCard[i] = 0;
        }
        for (int i = 0; i < 5; ++i) {
            _validity_period[i] = 0;
        }
    }

    virtual ~Card(); 

    void generateNumsOfCard();

    void printNumsOfCard() const;

    void reportsExpensesCategories();

    bool checkNumsOfCard(const int cardNumber[16]) const;

    void getNumsOfCard() const;

    void getBalance() const;

    void getValidityPeriod() const;

};