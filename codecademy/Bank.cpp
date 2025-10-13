#include "Bank.hpp"
#include <iostream>

void Bank::createAccount(std::string accountNumber, double balance) {
  std::cout << "Account " << accountNumber << " created!\n";
  BankAccount newAccount = BankAccount(accountNumber, balance);
  _accounts.push_back(newAccount);
}

BankAccount* Bank::findAccount(std::string accountNumber) {
  for (size_t i = 0; i < _accounts.size(); i++) {
    if (_accounts[i].getAccountNumber() == accountNumber)
      return &_accounts[i];
  }
  return nullptr;
 }

int Bank::transferMoney(BankAccount *source, BankAccount *target, double amount) {
  // сheck if accounts exits
  if (!findAccount(source->getAccountNumber()))
    return 2;
  if (!findAccount(target->getAccountNumber()))
    return 2;
  // check if sufficient balance
  if (source->getBalance() < amount)
    return 3;
  BankAccount::Transaction transaction = BankAccount::Transaction();
  transaction.withdraw(*source, amount);
  transaction.deposit(*target, amount);
  return 1;
}
