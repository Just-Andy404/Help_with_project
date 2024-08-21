#include "Card.h"

Card::~Card()
{
}

void Card::generateNumsOfCard()
{
    for (int i = 0; i < 16; ++i) {
        _NumsOfCard[i] = rand() % 9 + 1;
    }
}

void Card::printNumsOfCard() const
{
    for (int i = 0; i < 16; ++i) {
        if (_NumsOfCard[0] != 0)
        {
            cout << _NumsOfCard[i];
        }
    }
    cout << endl;
}

void Card::reportsExpensesCategories()
{
}

bool Card::checkNumsOfCard(const int cardNumber[16]) const
{
    for (int i = 0; i < 16; ++i) {
        if (_NumsOfCard[i] != cardNumber[i]) {
            return false;
        }
    }
    return true;
}

void Card::getNumsOfCard() const {
    cout << "Card number: ";
    for (int i = 0; i < 16; ++i) {
        cout << _NumsOfCard[i];
    }
    cout << endl;
}


