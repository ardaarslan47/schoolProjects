#include <iostream>
#include <cstring>
using namespace std;

enum AccountType {
    FREE = 1,
    PAID = 2
};

struct Account {
    int balance;
    AccountType type;
};

void buyPremium(Account& account);
void deposit(Account& account);
void withdraw(Account& account);
void info(Account account);

int main(){
    int balance = 0, typeInput = 0;
    AccountType type = FREE;
    
    cout << "Balance: ";
    cin >> balance;
    
    cout << "free or paid (1 for free, 2 for paid): ";
    while (typeInput != 1 && typeInput != 2){
        cin >> typeInput;
    }
    
    type = static_cast<AccountType>(typeInput);

    Account my_account;
    my_account.balance = balance;
    my_account.type = type;
    
    int operation = 0;
    while (operation != 1 && operation != 2 && operation != 3 && operation != 4){
        cout << endl << "1- Deposit" << endl << "2- Withdraw" << endl << "3- Profile Info";
        if (my_account.type != PAID) {
            cout << endl << "4- Buy Premium";
        }
        cout << endl << endl;
        cout << "Enter operation code. ('q' for quit): ";
        cin >> operation;
        
        if (!operation) {
            break;
        }
        
        cout << endl;
        
        switch (operation) {
            case 1:
                deposit(my_account);
                break;
            
            case 2:
                withdraw(my_account);
                break;
                
            case 3:
                info(my_account);
                break;
                
            case 4:
                buyPremium(my_account);
                break;
                
            default:
                break;
        }
        
        operation = 0;
    }

    return 0;
}

void buyPremium(Account& account) {
    string confirmation;
    cout << "Do you want to buy premium, it will cost 100. (y / n): ";
    cin >> confirmation;
    if (confirmation == "y" || confirmation == "Y") {
        if (account.balance > 100) {
            account.balance -= 100;
            account.type = PAID;
            cout << "Congrats! You have premium now" << endl;
        } else {
            cout << "Your balance is low." << endl;
        }
    }
}

void deposit(Account& account) {
    int deposit;
    cout << "How much do you want to deposit: ";
    cin >> deposit;
    account.balance += deposit;
    cout << "New balance: " << account.balance << endl;
}

void withdraw(Account& account) {
    int withdraw;
    cout << "How much do you want to withdraw: ";
    cin >> withdraw;
    if (withdraw <= account.balance) {
        account.balance -= withdraw;
        cout << "Operation is succesfull." << endl << "Your new balance is: " << account.balance << endl;
    } else {
        cout << "Withdraw cant be higher than your balance!" << endl;
    }
}

void info(Account account) {
    cout << "Balance: " << account.balance << endl;
    cout << "Account type: " << (account.type == PAID ? "Premium" : "Free version") << endl;
}

