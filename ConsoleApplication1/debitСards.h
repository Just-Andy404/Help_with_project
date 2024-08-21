#pragma once
#include "Card.h"
class DebitCard : public Card {
public:
	void ShowInfo() const;
	void addMoney();
	void payment();
	double getHowMuchMoney(const string& filename);
};

