#include <iostream>
#include <string>
#include <unordered_map>
#include <memory> // For smart pointers

// OOP Concepts:
// 1. Class: A blueprint for objects.
// 2. Object: An instance of a class.
// 3. Encapsulation: Data is hidden inside classes and exposed through methods.
// 4. Inheritance: Allows classes to inherit properties and behavior from another class.
// 5. Polymorphism: Allows methods to be used differently in inherited classes (achieved using method overriding).
// 6. Abstraction: Hides implementation details and provides a user with a clean interface.
// 7. Composition: A "has-a" relationship where one class contains objects of another class.

// Abstract Base Class for Accounts (Abstraction)
class Account
{
protected:
    std::string owner; // Account owner
    double balance;    // Account balance

public:
    Account(std::string owner, double balance = 0.0) : owner(owner), balance(balance) {}

    // Abstract Methods (Pure Virtual Functions) for deposit and withdraw
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    // Getter for balance (Encapsulation: exposing private/protected data via public methods)
    double getBalance() const
    {
        return balance;
    }

    virtual ~Account() = default; // Virtual destructor for proper cleanup of derived classes
};

// Derived class from Account: CurrentAccount (Inheritance)
class CurrentAccount : public Account
{
private:
    double overdraftLimit;

public:
    CurrentAccount(std::string owner, double balance = 0.0, double overdraftLimit = 1000.0)
        : Account(owner, balance), overdraftLimit(overdraftLimit) {}

    // Overriding deposit method (Polymorphism)
    void deposit(double amount) override
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << "Deposited " << amount << " to Current Account. New balance: " << balance << "\n";
        }
        else
        {
            std::cout << "Deposit amount must be positive.\n";
        }
    }

    // Overriding withdraw method (Polymorphism)
    void withdraw(double amount) override
    {
        if (balance + overdraftLimit >= amount)
        {
            balance -= amount;
            std::cout << "Withdrew " << amount << " from Current Account. New balance: " << balance << "\n";
        }
        else
        {
            std::cout << "Insufficient funds (including overdraft limit).\n";
        }
    }
};

// Derived class from Account: SavingsAccount (Inheritance)
class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(std::string owner, double balance = 0.0, double interestRate = 0.05)
        : Account(owner, balance), interestRate(interestRate) {}

    // Overriding deposit method (Polymorphism)
    void deposit(double amount) override
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << "Deposited " << amount << " to Savings Account. New balance: " << balance << "\n";
        }
        else
        {
            std::cout << "Deposit amount must be positive.\n";
        }
    }

    // Overriding withdraw method (Polymorphism)
    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            balance -= amount;
            std::cout << "Withdrew " << amount << " from Savings Account. New balance: " << balance << "\n";
        }
        else
        {
            std::cout << "Insufficient funds.\n";
        }
    }

    // Additional method specific to SavingsAccount
    void applyInterest()
    {
        balance += balance * interestRate;
        std::cout << "Applied interest. New balance: " << balance << "\n";
    }
};

// Bank class that holds accounts (Composition)
class Bank
{
private:
    // Composition: A bank has multiple accounts
    std::unordered_map<std::string, std::shared_ptr<Account>> accounts;

public:
    // Factory method to create accounts
    void createAccount(const std::string &accountType, const std::string &owner, double balance = 0.0)
    {
        if (accountType == "current")
        {
            accounts[owner] = std::make_shared<CurrentAccount>(owner, balance);
            std::cout << "Created a Current Account for " << owner << "\n";
        }
        else if (accountType == "savings")
        {
            accounts[owner] = std::make_shared<SavingsAccount>(owner, balance);
            std::cout << "Created a Savings Account for " << owner << "\n";
        }
    }

    // Get account by owner name
    std::shared_ptr<Account> getAccount(const std::string &owner)
    {
        return accounts[owner];
    }

    // Transfer money between accounts
    void transfer(const std::string &fromOwner, const std::string &toOwner, double amount)
    {
        auto fromAccount = accounts[fromOwner];
        auto toAccount = accounts[toOwner];

        if (fromAccount && toAccount)
        {
            if (fromAccount->getBalance() >= amount)
            {
                fromAccount->withdraw(amount);
                toAccount->deposit(amount);
                std::cout << "Transferred " << amount << " from " << fromOwner << " to " << toOwner << "\n";
            }
            else
            {
                std::cout << fromOwner << " does not have enough balance.\n";
            }
        }
        else
        {
            std::cout << "One or both accounts do not exist.\n";
        }
    }
};

// Example usage
int main()
{
    Bank bank;

    // Create accounts
    bank.createAccount("current", "Alice", 500.0);
    bank.createAccount("savings", "Bob", 1000.0);

    // Perform operations
    auto aliceAccount = bank.getAccount("Alice");
    auto bobAccount = bank.getAccount("Bob");

    // Deposit and withdraw
    aliceAccount->deposit(200.0);
    aliceAccount->withdraw(300.0);

    bobAccount->deposit(500.0);
    bobAccount->withdraw(1200.0); // Insufficient funds
    bobAccount->withdraw(200.0);

    // Apply interest to Bob's savings account
    if (auto savingsAcc = std::dynamic_pointer_cast<SavingsAccount>(bobAccount))
    {
        savingsAcc->applyInterest();
    }

    // Transfer money between accounts
    bank.transfer("Alice", "Bob", 200.0);

    return 0;
}
