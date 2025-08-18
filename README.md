
# 🏦 Banking System (C++ | OOP | In‑Memory)

![C++](https://img.shields.io/badge/C%2B%2B-17%2B-00599C?logo=c%2B%2B&logoColor=white)
![Paradigm](https://img.shields.io/badge/Paradigm-OOP-blueviolet)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-orange)
![Status](https://img.shields.io/badge/Status-Learning%2FDemo-brightgreen)

A clean, menu-driven console app demonstrating core OOP with polymorphism and inheritance in C++. It supports Savings, Checking (with overdraft), and Fixed Deposit accounts, interest calculation, deposits/withdrawals, and account info display. Data is stored in memory (no files/DB).

---

## ✨ Features

- Create accounts
  - SavingAccount with interest rate
  - CheckingAccount with overdraft limit
  - FixedDepositAccount with term (months) and interest rate
- Deposit and withdraw (Checking supports overdraft up to limit)
- Display all accounts
- Calculate interest per account type
- Show current balance
- Clean shutdown and memory cleanup

---

## 🧠 OOP Concepts in This Project

- Inheritance: SavingAccount, CheckingAccount, and FixedDepositAccount derive from BankAccount
- Polymorphism: Virtual functions (withdraw, calculateInterest, displayAccountInfo) enable runtime dispatch via BankAccount pointers
- Encapsulation: Account data and operations are bundled within classes
- Virtual destructor: Ensures proper cleanup when deleting through base pointers

---

## 📦 Class Overview

- BankAccount (base)
  - Data: accountNumber, accountHolderName, balance
  - Methods: createAccount, deposit, withdraw, getBalance, displayAccountInfo, calculateInterest, getAccountNumber
- SavingAccount (derived)
  - Data: interestRate (default 5%)
  - Overrides: calculateInterest adds balance * (rate/100)
- CheckingAccount (derived)
  - Data: overdraftLimit (default 5000)
  - Overrides: withdraw allows amount <= balance + overdraftLimit
- FixedDepositAccount (derived)
  - Data: term (months), interestRate (default 12 months, 6%)
  - Overrides: calculateInterest adds balance * (rate/100) * (term/12.0)

---

## 🖥️ Demo (Menu)

```
=== BANKING SYSTEM MENU ===
1. Create Saving Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display All Accounts
7. Calculate Interest
8. Display Balance
9. Exit
```

Example flow:
- Create a Saving account → Deposit → Calculate Interest → Display Balance

---

## 🚀 Build & Run

1) Clone
```bash
git clone https://github.com/kush424/Banking-System.git
cd Banking-System

```

## 🔢 Important Details

- Storage: In-memory only (BankAccount* accounts[100]) — data is lost after exit
- Capacity: Max 100 accounts
- Name input: Uses cin >> name; spaces in names aren’t supported (use single word or modify to getline)
- Validations:
  - Deposit must be > 0
  - Withdraw must be > 0 and within balance (or balance + overdraft for Checking)
  - Interest adds directly to balance (compounded once per call)

---

## ⚠️ Limitations

- No persistent storage (files/DB) — all data is cleared on exit
- No uniqueness check for account numbers
- Basic input handling (no robust validation for non-numeric input)
- Fixed-size array; manual memory management

---

## 🛠️ Nice-to-Have Improvements

- Use std::vector<std::unique_ptr<BankAccount>> instead of raw pointers/arrays
- Support names with spaces using std::getline
- Add persistence (e.g., save/load to a file or simple DB)
- Enforce unique account numbers and add search utilities
- Add transaction history and transfers between accounts
- Better input validation and error handling

---

## 📁 Project Structure

```
.
├── main.cpp      # Full source (menu + classes)
└── README.md
```

---

## 🤝 Contributing

- Fork the repo 
- Create a feature branch
- Commit with clear messages
- Open a Pull Request

Ideas and issues welcome!

---

## 📜 License

Add a LICENSE file (MIT recommended). Update this section if you choose a different license.

---

## 👤 Author

Made with ❤️ by [Kush](https://github.com/kush424)


---

<img width="583" height="368" alt="image" src="https://github.com/user-attachments/assets/501bb922-50ed-4ad8-b0b0-68d86ba6bff3" />
<img width="559" height="358" alt="image" src="https://github.com/user-attachments/assets/de643f9a-17ae-44af-a6a7-c91731bd07e1" />
<img width="619" height="376" alt="image" src="https://github.com/user-attachments/assets/70f9fba3-64f0-4432-975a-50c3a8319fcd" />
<img width="439" height="314" alt="image" src="https://github.com/user-attachments/assets/e9b97ea3-850d-4d59-b6df-cbe20566bdba" />
<img width="374" height="310" alt="image" src="https://github.com/user-attachments/assets/94d53498-f0db-4c4d-8db8-4f79e98a3233" />
<img width="611" height="313" alt="image" src="https://github.com/user-attachments/assets/897a23e0-3193-4a8e-9a11-ad424c1fbc97" />
<img width="522" height="590" alt="image" src="https://github.com/user-attachments/assets/8f8033e9-b709-4274-9762-d3a93b2236d0" />
<img width="713" height="293" alt="image" src="https://github.com/user-attachments/assets/15a9ea93-9e78-42c0-84d6-274c9a4a9aee" />
<img width="445" height="288" alt="image" src="https://github.com/user-attachments/assets/3f8c3cd0-dbd7-43bd-ada5-067217a774bb" />
<img width="498" height="260" alt="image" src="https://github.com/user-attachments/assets/6d2b116f-765e-482f-b615-23e2769e7ce2" />
