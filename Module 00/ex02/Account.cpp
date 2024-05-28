#include "Account.hpp"
#include <iostream>

int	Account::getNbAccounts()
{
	return t::_nbAccounts;
}

int	Account::getTotalAmount()
{
	return t::_totalAmount;
}

int	Account::getNbDeposits()
{
	return t::_totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return t::_totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	for (int i = 0; i < Account::getNbAccounts; i++)
	{
		std::cout << "index:" << i << ";amount:" << Account::getTotalAmount 
	}
}
