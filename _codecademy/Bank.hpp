#include <vector>
#include "BankAccount.hpp"


class Bank {
  private:
    vector<BankAccount> _accounts;

  public:
    void createAccount(std::string accountNumber, double balance);
    BankAccount *findAccount(std::string accountNumber);
    int transferMoney(BankAccount *source, BankAccount *target, double amount);
};
