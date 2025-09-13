#include <iostream>
#include <ctime>
#include "Account.hpp"

#define SHOW_DEBUG 0

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Account::Account( void ) {
// 	if (SHOW_DEBUG)
// 		std::cout << "Account class default constructor called" << std::endl;
// 	_accountIndex = Account::_nbAccounts;
// 	_totalAmount = 0;
// 	_totalNbDeposits = 0;
// 	_totalNbDeposits = 0;
// 	Account::_nbAccounts++;
// }

Account::Account( int amount ) {
	if (SHOW_DEBUG)
		std::cout << "Account class parameterized constructor called" << std::endl;
	
	_accountIndex = Account::_nbAccounts++;
	_amount = amount;
	_totalAmount += amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << amount << ";";
	std::cout << "created";
	std::cout << std::endl;
	if (SHOW_DEBUG)
		std::cout << "-------------------------------------" << std::endl;
}

// destructor
Account::~Account( void ) {
	if (SHOW_DEBUG)
		std::cout << "Account class default destructor called" << std::endl;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
	Account::_nbAccounts--;
}

void Account::_displayTimestamp(void) {
    std::time_t now = std::time(NULL);
    std::tm* ptm = std::localtime(&now);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ptm);
    std::cout << buffer;
}

int	Account::getNbAccounts( void ) { return Account::_nbAccounts; }

int	Account::getTotalAmount( void ) { return Account::_totalAmount; }

int	Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }

int	Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals; }

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	int p_amount = checkAmount();
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_totalNbDeposits++;
	_nbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	// [19920104_091532] index:0;p_amount:47;withdrawal:refused
	// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount( void ) const { return _amount; }

void	Account::displayStatus( void ) const {
	// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}