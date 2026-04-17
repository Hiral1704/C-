#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully\n";
    }

    virtual void withdraw(double amount) {
        if(amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful\n";
        } else {
            cout << "Insufficient Balance\n";
        }
    }

    double getBalance() {
        return balance;
    }

    virtual void calculateInterest() {
        cout << "Interest calculation not applicable for this account.\n";
    }

    virtual void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal) {
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        cout << "Savings Interest: " << interest << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if(amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawal Allowed (Overdraft used if needed)\n";
        } else {
            cout << "Withdrawal exceeds overdraft limit!\n";
        }
    }

    void checkOverdraft() {
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount {
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t, double rate)
        : BankAccount(accNo, name, bal) {
        term = t;
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * interestRate * term / (12 * 100);
        cout << "Fixed Deposit Interest: " << interest << endl;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed before maturity!\n";
    }
};


int main() {

    BankAccount* account;

    int choice;
    int accNo;
    string name;
    double balance;
    double amount;

    cout << "===== Bank Account System =====\n";
    cout << "1. Savings Account\n";
    cout << "2. Checking Account\n";
    cout << "3. Fixed Deposit Account\n";
    cout << "Choose Account Type: ";
    cin >> choice;

    cout << "Enter Account Number: ";
    cin >> accNo;

    cout << "Enter Account Holder Name: ";
    cin >> name;

    cout << "Enter Initial Balance: ";
    cin >> balance;

    if(choice == 1) {
        double rate;
        cout << "Enter Interest Rate: ";
        cin >> rate;

        account = new SavingsAccount(accNo, name, balance, rate);
    }
    else if(choice == 2) {
        double limit;
        cout << "Enter Overdraft Limit: ";
        cin >> limit;

        account = new CheckingAccount(accNo, name, balance, limit);
    }
    else if(choice == 3) {
        int term;
        double rate;

        cout << "Enter Term (months): ";
        cin >> term;

        cout << "Enter Interest Rate: ";
        cin >> rate;

        account = new FixedDepositAccount(accNo, name, balance, term, rate);
    }
    else {
        cout << "Invalid Choice\n";
        return 0;
    }

    do {
        cout << "\n===== Menu =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Calculate Interest\n";
        cout << "5. Display Account Info\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter Amount: ";
            cin >> amount;
            account->deposit(amount);
            break;

        case 2:
            cout << "Enter Amount: ";
            cin >> amount;
            account->withdraw(amount);
            break;

        case 3:
            cout << "Current Balance: " << account->getBalance() << endl;
            break;

        case 4:
            account->calculateInterest();
            break;

        case 5:
            account->displayAccountInfo();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while(choice != 0);

    delete account;

    return 0;
}