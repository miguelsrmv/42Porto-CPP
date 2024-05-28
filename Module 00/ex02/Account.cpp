#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdio>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    std::cout << "[19920104_091532] ";

	std::cout	<< "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;

	_nbAccounts++;
	_totalAmount += _amount;

    std::cout << "[19920104_091532] ";

	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << initial_deposit
				<< ";created" << std::endl;
}

Account::~Account(void)
{
    std::cout << "[19920104_091532] ";

	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    std::cout << "[19920104_091532] ";

	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount + deposit
				<< ";nb_deposits:" << _nbDeposits + 1
				<< std::endl;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
    std::cout << "[19920104_091532] ";

	if (withdrawal <= _amount)
	{
		std::cout	<< "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount - withdrawal
			<< ";nb_withdrawals:" << _nbWithdrawals + 1
			<< std::endl;

		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		return true;
	}
	else
	{
		std::cout	<< "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:refused"
			<< std::endl;
		return false;
	}
}

void Account::displayStatus(void) const
{
    std::cout << "[19920104_091532] ";

	std::cout	<< "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
}

