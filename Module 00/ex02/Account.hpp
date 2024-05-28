// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );
	// Done
	static int	getTotalAmount( void );
	// Done
	static int	getNbDeposits( void );
	// Done
	static int	getNbWithdrawals( void );
	// Done
	static void	displayAccountsInfos( void );
	// Done

	Account( int initial_deposit );
	// Done
	~Account( void );
	// Done

	void	makeDeposit( int deposit );
	// Done
	bool	makeWithdrawal( int withdrawal );
	// Done
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;
	// Done


private:

	static int	_nbAccounts;					// Number of accounts
	static int	_totalAmount;					// Total amount
	static int	_totalNbDeposits;				// Total number of deposits
	static int	_totalNbWithdrawals;			// Total number of withdrawals

	static void	_displayTimestamp( void );

	int				_accountIndex;				// Account index
	int				_amount;					// Amount per account
	int				_nbDeposits;				// Deposit per account
	int				_nbWithdrawals;				// Withdrawal ammount

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
