#include <iostream>
#include "Account.hpp"

#define SHOW_DEBUG 1

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) {
	if (SHOW_DEBUG)
		std::cout << "Account class default constructor called" << std::endl;
}

Account::~Account(void) {
	if (SHOW_DEBUG)
		std::cout << "Account class default destructor called" << std::endl;
}
