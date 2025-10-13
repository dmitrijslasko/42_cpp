#include "BankAccount.hpp"

BankAccount::BankAccount(string accountNumber, double balance):
  _accountNumber(accountNumber),
  _balance(balance)
{}

string BankAccount::getAccountNumber() {
  return _accountNumber;
}

double BankAccount::getBalance() {
  return _balance;
}

void BankAccount::setAccountNumber(string newAccountNumber) {
  _accountNumber = newAccountNumber;
}

void BankAccount::setBalance(double newBalance) {
  _balance = newBalance;
}

void BankAccount::Transaction::deposit(BankAccount& account, double amount) {
  double currentBalance = account.getBalance();
  std::cout << "Starting balance: " << currentBalance << "\n";
  std::cout << "Deposit: " << amount << "\n";
  double newBalance = currentBalance + amount;
  account.setBalance(newBalance);
  std::cout << "New balance: " << newBalance << "\n";
}

void BankAccount::Transaction::withdraw(BankAccount& account, double amount) {
  double currentBalance = account.getBalance();
  std::cout << "Starting balance: " << currentBalance << "\n";
  std::cout << "Withdrawal: " << amount << "\n";
  double newBalance = currentBalance;
  if (currentBalance >= amount) {
    newBalance = currentBalance - amount;
    account.setBalance(newBalance);
  }
  else
    std::cout << "Not sufficient funds!\n";
  std::cout << "New balance: " << newBalance << "\n";
}
