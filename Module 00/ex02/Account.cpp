#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int
Account::getNbAccounts ()
{
	return _nbAccounts;
}

int
Account::getTotalAmount ()
{
	return _totalAmount;
}

int
Account::getNbDeposits ()
{
	return _totalNbDeposits;
}

int
Account::getNbWithdrawals ()
{
	return _totalNbWithdrawals;
}

void
Account::displayAccountsInfos ()
{
	_displayTimestamp ();

	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account (int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;

	_nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp ();

	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit
			  << ";created" << std::endl;
}

Account::~Account (void)
{
	_displayTimestamp ();

	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";closed" << std::endl;
}

void
Account::makeDeposit (int deposit)
{
	_displayTimestamp ();

	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
			  << ";deposit:" << deposit << ";amount:" << _amount + deposit
			  << ";nb_deposits:" << _nbDeposits + 1 << std::endl;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

bool
Account::makeWithdrawal (int withdrawal)
{
	_displayTimestamp ();

	if (withdrawal <= _amount)
		{
			std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
					  << ";withdrawal:" << withdrawal
					  << ";amount:" << _amount - withdrawal
					  << ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;

			_amount -= withdrawal;
			_totalAmount -= withdrawal;
			_nbWithdrawals++;
			_totalNbWithdrawals++;
			return true;
		}
	else
		{
			std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
					  << ";withdrawal:refused" << std::endl;
			return false;
		}
}

void
Account::displayStatus (void) const
{
	_displayTimestamp ();

	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void
Account::_displayTimestamp (void)
{
	// std::cout << "[19920104_091532] ";

	std::time_t time_in_sec;
	std::tm *timemark;

	time_in_sec = std::time (NULL);
	timemark = std::localtime (&time_in_sec);
	std::cout << "[" << timemark->tm_year + 1900;
	std::cout << std::setfill ('0') << std::setw (2) << timemark->tm_mon;
	std::cout << std::setfill ('0') << std::setw (2) << timemark->tm_mday
			  << "_";
	std::cout << std::setfill ('0') << std::setw (2) << timemark->tm_hour;
	std::cout << std::setfill ('0') << std::setw (2) << timemark->tm_min;
	std::cout << std::setfill ('0') << std::setw (2) << timemark->tm_sec
			  << "] ";
}
