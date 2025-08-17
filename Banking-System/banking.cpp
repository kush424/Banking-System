#include <iostream>
using namespace std;

class BankAccount {
protected:
    long int accountNumber;
    string accountHolderName;
    double balance;

public:
    virtual ~BankAccount() {}

    void createAccount(long int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = initialBalance;
    }

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " successfully!!!\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << " successfully!!!\n";
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    virtual void displayAccountInfo() const {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    virtual void calculateInterest() {
        cout << "This account type has no interest calculation.\n";
    }

    long int getAccountNumber() const {
        return accountNumber;
    }
};

// Saving Account
class SavingAccount : public BankAccount {
    float interestRate;
public:
    SavingAccount(float rate = 5.0) : interestRate(rate) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest (" << interestRate << "%) applied. New Balance: " << balance << endl;
    }
};

// Checking Account
class CheckingAccount : public BankAccount {
    double overdraftLimit;
public:
    CheckingAccount(double limit = 5000) : overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrew " << amount << " successfully (Overdraft applied if needed).\n";
        } else {
            cout << "Withdrawal exceeds balance and overdraft limit.\n";
        }
    }
};

// Fixed Deposit Account
class FixedDepositAccount : public BankAccount {
    int term; 
    float interestRate;
public:
    FixedDepositAccount(int t = 12, float rate = 6.0) : term(t), interestRate(rate) {}

    void setTerm(int t) {
        term = t;
    }

    void calculateInterest() override {
        double interest = balance * (interestRate / 100) * (term / 12.0);
        balance += interest;
        cout << "Interest for " << term << " months at " << interestRate 
             << "% applied. New Balance: " << balance << endl;
    }
};

int main() {
    BankAccount* accounts[100]; 
    int accountCount = 0;
    int choice;

    do {
        cout << "\n=== BANKING SYSTEM MENU ===\n";
        cout << "1. Create Saving Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Display All Accounts\n";
        cout << "7. Calculate Interest\n";
        cout << "8. Display Balance\n";
        cout << "9. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3) {
            long int accNo;
            string name;
            double initialBalance;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Account Holder Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> initialBalance;

            if (choice == 1) {
                float rate;
                cout << "Enter Interest Rate (%): ";
                cin >> rate;
                SavingAccount* sa = new SavingAccount(rate);
                sa->createAccount(accNo, name, initialBalance);
                accounts[accountCount++] = sa;
                cout << "Savings Account created successfully!!!\n";
            } 
            else if (choice == 2) {
                double limit;
                cout << "Enter Overdraft Limit: ";
                cin >> limit;
                CheckingAccount* ca = new CheckingAccount(limit);
                ca->createAccount(accNo, name, initialBalance);
                accounts[accountCount++] = ca;
                cout << "Checking Account created successfully!!!\n";
            } 
            else {
                int term;
                float rate;
                cout << "Enter Term (months): ";
                cin >> term;
                cout << "Enter Interest Rate (%): ";
                cin >> rate;
                FixedDepositAccount* fa = new FixedDepositAccount(term, rate);
                fa->createAccount(accNo, name, initialBalance);
                accounts[accountCount++] = fa;
                cout << "Fixed Deposit Account created successfully!!!\n";
            }
        }

        else if (choice >= 4 && choice <= 8) {
            if (accountCount == 0) {
                cout << "No accounts available.\n";
                continue;
            }

            long int accNo;
            cout << "Enter the Account Number: ";
            cin >> accNo;
            BankAccount* account = nullptr;

            for (int i = 0; i < accountCount; i++) {
                if (accounts[i]->getAccountNumber() == accNo) {
                    account = accounts[i];
                    break;
                }
            }

            if (!account) {
                cout << "Account not found!\n";
                continue;
            }

            if (choice == 4) { // Deposit
                double amt;
                cout << "Enter amount to deposit: ";
                cin >> amt;
                account->deposit(amt);
            }
            else if (choice == 5) { // Withdraw
                double amt;
                cout << "Enter amount to withdraw: ";
                cin >> amt;
                account->withdraw(amt);
            }
            else if (choice == 6) { // Display All Accounts
                for (int i = 0; i < accountCount; i++) {
                    cout << "\n--- Account " << (i + 1) << " ---\n";
                    accounts[i]->displayAccountInfo();
                }
            }
            else if (choice == 7) { // Interest
                account->calculateInterest();
            }
            else if (choice == 8) { // Balance
                cout << "Current Balance: " << account->getBalance() << endl;
            }
        }
        else if (choice == 9) {
            cout << "Exiting... Thank you!\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 9);

    for (int i = 0; i < accountCount; i++) {
        delete accounts[i]; 
    }

    return 0;
}
