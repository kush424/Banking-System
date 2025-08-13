#include <iostream>
using namespace std;
class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:

      BankAccount(int accNum, string accName, double initialBal)
    : accountNumber(accNum), accountHolderName(accName), balance(initialBal) {}


    virtual ~BankAccount() {}

    int getAccountNumber() const
    {
        return accountNumber;
    }
    string getAccountHolderName() const
    {
        return accountHolderName;
    }
      double getBalance() const
    {
        return balance;
    }
    

    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount!\n";
        }
    }
    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal or insufficient funds!\n";
        }
    }
  

    virtual void displayAccountInfo() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
    virtual void calculateInterest() const
    {
        cout << "Interest calculation not available for base account.\n";
    }
    
protected:
   
    void adjustBalance(double amount) {
        balance += amount;
    }
};
class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int accNum, string accName, double initialBal, double rate)
        : BankAccount(accNum, accName, initialBal), interestRate(rate) {}

    void calculateInterest() const override
    {
        double interest = getBalance() * (interestRate / 100);
        cout << "Savings Account Interest: " << interest << endl;
    }
};
class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, string accName, double initialBal, double limit)
        : BankAccount(accNum, accName, initialBal), overdraftLimit(limit) {}

    void withdraw(double amount)override
    {
        if (amount > 0 && amount <= getBalance() + overdraftLimit)
        {
            double newBalance = getBalance() - amount;
            adjustBalance(-amount);
             cout << "Withdrawn: " << amount << " | New Balance: " << getBalance() << endl;
        }
        else
        {
            cout << "Overdraft limit has been surpassed!" << endl;
        }
    }
    void calculateInterest() const
    {
        cout << "Interest is generally not paid on checking accounts." << endl;
    }
};
class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(int accNum, string accName, double initialBal, int t, double rate)
        : BankAccount(accNum, accName, initialBal), term(t), interestRate(rate) {}

    void calculateInterest() const
    {
        double interest = getBalance() * (interestRate / 100) * (term / 12.0);
        cout << "Fixed Deposit Interest (" << term << " months): " << interest << endl;
    }
};

int main()
{

    SavingsAccount sa(101, "kush", 5000, 5);
    CheckingAccount ca(102, "Param", 9000, 500);
    FixedDepositAccount fda(103, "shiv", 11000, 6, 8);

    BankAccount *accounts[] = {&sa, &ca, &fda};
    int choice, accTypes;
    double amount;

    do
    {
        cout << "---- Banking System Menu ----" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Account Info" << endl;
        cout << "4. Calculate Interest"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<" Enter your choice: ";
        cin>>choice;

        if(choice==0)
            break;

            cout<<"Select Account (0: Saving, 1: Checking, 2: Fixed Deposit):";
            cin>>accTypes;

            switch(choice){
                case 1:
                cout<<"Please enter deposit amount:- ";
                cin>>amount;
                accounts[accTypes]->deposit(amount);
                break;

                case 2:
                cout<<"Please enter withdraw amount:- ";
                cin>>amount;
                accounts[accTypes]->withdraw(amount);
                break;

                case 3:
                accounts[accTypes]-> displayAccountInfo();
                break;

                case 4:
                accounts[accTypes]->calculateInterest();
                break;

                default:
                cout<<"Invalid choice"<<endl;
            
            }
    
    }while(choice!=0);

    return 0;
}



// ---- Banking System Menu ----
// 1. Deposit
// 2. Withdraw
// 3. Display Account Info
// 4. Calculate Interest
// 0. Exit
//  Enter your choice: 2
// Select Account (0: Saving, 1: Checking, 2: Fixed Deposit):0
// Please enter withdraw amount:- 500
// Withdrawn: 500 | New Balance: 4500
// ---- Banking System Menu ----
// 1. Deposit
// 2. Withdraw
// 3. Display Account Info
// 4. Calculate Interest
// 0. Exit
//  Enter your choice: 2
// Select Account (0: Saving, 1: Checking, 2: Fixed Deposit):1
// Please enter withdraw amount:- 1000
// Withdrawn: 1000 | New Balance: 8000
// ---- Banking System Menu ----
// 1. Deposit
// 2. Withdraw
// 3. Display Account Info
// 4. Calculate Interest
// 0. Exit
//  Enter your choice: 2
// Select Account (0: Saving, 1: Checking, 2: Fixed Deposit):2
// Please enter withdraw amount:- 6000
// Withdrawn: 6000 | New Balance: 5000
// ---- Banking System Menu ----
// 1. Deposit
// 2. Withdraw
// 3. Display Account Info
// 4. Calculate Interest
// 0. Exit
//  Enter your choice: 3
// Select Account (0: Saving, 1: Checking, 2: Fixed Deposit):0
// Account Number: 101
// Account Holder: kush
// Balance: 4500
// ---- Banking System Menu ----
// 1. Deposit
// 2. Withdraw
// 3. Display Account Info
// 4. Calculate Interest
// 0. Exit
//  Enter your choice: 3
// Select Account (0: Saving, 1: Checking, 2: Fixed Deposit):1
// Account Number: 102
// Account Holder: Param
// Balance: 8000
// ---- Banking System Menu ----
// 1. Deposit
// 2. Withdraw
// 3. Display Account Info
// 4. Calculate Interest
// 0. Exit
//  Enter your choice: 3
// Select Account (0: Saving, 1: Checking, 2: Fixed Deposit):2
// Account Number: 103
// Account Holder: shiv
// Balance: 5000
// ---- Banking System Menu ----
// 1. Deposit
// 2. Withdraw
// 3. Display Account Info
// 4. Calculate Interest
// 0. Exit
//  Enter your choice: 4
// Select Account (0: Saving, 1: Checking, 2: Fixed Deposit):0
// Savings Account Interest: 225
// ---- Banking System Menu ----
// 1. Deposit
// 2. Withdraw
// 3. Display Account Info
// 4. Calculate Interest
// 0. Exit
//  Enter your choice: 4
// Select Account (0: Saving, 1: Checking, 2: Fixed Deposit):1
// Interest is generally not paid on checking accounts.
// ---- Banking System Menu ----
// 1. Deposit
// 2. Withdraw
// 3. Display Account Info
// 4. Calculate Interest
// 0. Exit
//  Enter your choice: 4
// Select Account (0: Saving, 1: Checking, 2: Fixed Deposit):2
// Fixed Deposit Interest (6 months): 200
// ---- Banking System Menu ----
// 1. Deposit
// 2. Withdraw
// 3. Display Account Info
// 4. Calculate Interest
// 0. Exit
//  Enter your choice: 0