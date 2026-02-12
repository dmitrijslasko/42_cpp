#pragma once 

#include <string>
#include <iostream>

using namespace std;

class BankAccount {
  private:
    string  _accountNumber;
    double  _balance;

  public:
    BankAccount(string accountNumber, double balance);
    string getAccountNumber();
    double getBalance();
    void  setAccountNumber(string newAccountNumber);
    void  setBalance(double newBalance);
    class Transaction {
      private:

      public:
      void deposit(BankAccount& account, double amount);
      void withdraw(BankAccount& account, double amount);
    };
};
