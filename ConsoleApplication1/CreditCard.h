#pragma once
#include "Card.h"

class CreditCard : public Card {

public:
	void ShowInfo() const;
	void addMoney();
	void payment();

};