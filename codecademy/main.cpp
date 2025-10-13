#include <iostream>
#include "Bank.hpp"

using namespace std;

int main() {
  Bank myBank = Bank();
  myBank.createAccount("1001", 5000);
  myBank.createAccount("1002", 3000);
  myBank.createAccount("1003", 2000);

  BankAccount* account = myBank.findAccount("1001");
  BankAccount::Transaction transaction;
  transaction.deposit(*account, 500);

  account = myBank.findAccount("1002");
  transaction.withdraw(*account, 500);

  BankAccount* source = myBank.findAccount("1002");
  BankAccount* target = myBank.findAccount("1003");
  int res = myBank.transferMoney(source, target, 150);
  if (res == 1)
  	std::cout << ">>> Succesful transfer!\n";

  return 0;
}
