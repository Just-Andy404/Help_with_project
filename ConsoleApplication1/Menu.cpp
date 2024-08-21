#include "Account.h"
#include "Card.h"
#include "CreditCard.h"
#include "debit�ards.h"

int WelcomeMenu()
{
    while (true)
    {
        int choice = 0;
        cout << "Welcome to our bank !" << endl;
        cout << "1) Login" << endl;
        cout << "2) Registrate an account" << endl << "choice: ";
        cin >> choice;
        cout << endl;
        if (choice == 1 || choice == 2)
        {
            return choice;
        }
        else
        {
            cout << "Input coorect choice" << endl;
        }
    }
}

void LoginMenu()
{
	cout << "Login: ";

	cout << "Password: ";
	//TODO ������� ������� �������� ������� � �������

}

void RegisterateMenu() 
{
    string login, password, name;
    int choice;
    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;
    cout << "Which card do you want to use?\n1) Debit card\n2) Credit card\nChoice: ";
    cin >> choice;

    Card* userCard = nullptr;

    if (choice == 1) {
        userCard = new DebitCard();  // ������� ������ DebitCard
    }
    else if (choice == 2) {
        userCard = new CreditCard();  // ������� ������ CreditCard
    }

    Account account(login, password, userCard, name);

    // ������������ ������ ����� �������������
    delete userCard;
}


void Menu(Account& Acc) {
    int WelcomeMenuChoice = WelcomeMenu();

    if (WelcomeMenuChoice == 1)
    {
        LoginMenu();
    }
    else if(WelcomeMenuChoice == 2)
    {
        RegisterateMenu();
    }
    int choice;
    Card* card = WhichOneCards(Acc); 

    cout << "Welcome " << Acc.getUserName() << endl;
    cout << "1) Show info" << endl;
    cout << "2) Add money" << endl;
    cout << "3) Pay" << endl;
    cout << "4) Generate reports on expenses and categories" << endl;
    cout << "5) Top 3 expenses" << endl;
    cout << "6) TOP-3 categories" << endl;
    cout << "0) Exit" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        Acc.showInfo();
        break;
    case 2:
        if (DebitCard* debitCard = dynamic_cast<DebitCard*>(card)) {
            debitCard->addMoney(); 
        }
        else if (CreditCard* creditCard = dynamic_cast<CreditCard*>(card)) {
            creditCard->addMoney(); 
        }
        break;
    case 3:
        if (DebitCard* debitCard = dynamic_cast<DebitCard*>(card)) {
            debitCard->payment(); // ����� ������ payment() ��� ��������� �����
        }
        else if (CreditCard* creditCard = dynamic_cast<CreditCard*>(card)) {
            creditCard->payment(); // ����� ������ payment() ��� ��������� �����
        }
        break;
    case 4:
        if (DebitCard* debitCard = dynamic_cast<DebitCard*>(card)) {
            debitCard->reportsExpensesCategories(); // ����� ������ payment() ��� ��������� �����
        }
        else if (CreditCard* creditCard = dynamic_cast<CreditCard*>(card)) {
            creditCard->reportsExpensesCategories(); // ����� ������ payment() ��� ��������� �����
        }
        break;
    case 5: 

    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}

Card* WhichOneCards(Account& Acc) {
    Card* card = nullptr;

    // ��������� ��� ����� ������������
    if (CreditCard* creditCard = dynamic_cast<CreditCard*>(Acc.getWhichOfCard())) {
        card = creditCard;
        cout << "Credit card selected." << endl;
    }
    else if (DebitCard* debitCard = dynamic_cast<DebitCard*>(Acc.getWhichOfCard())) {
        // ���� ����� ���������
        card = debitCard;
        cout << "Debit card selected." << endl;
    }

    if (card == nullptr) {
        cout << "No valid card associated with the account." << endl;
    }

    return card;
}