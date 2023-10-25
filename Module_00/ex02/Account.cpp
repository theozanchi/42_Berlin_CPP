/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:08:49 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/25 17:48:54 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <time.h>

// ************************************************************************** //

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	for (int i = 0; i < _nbAccounts; ++i)
	{
		_displayTimestamp();
		std::cout << " accounts:" << getNbAccounts() << ";";
		std::cout << "amount:" << getTotalAmount() << ";";
		std::cout << "deposits:" << getNbDeposits() << ";";
		std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
	}
}

// ************************************************************************** //

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_totalNbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

// ************************************************************************** //

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << " p_amount:" << this->checkAmount() << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << " deposit:" << deposit << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << " p_amount:" << this->checkAmount() << ";";
	std::cout << " withdrawal:";
	if (this->checkAmount() >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";";
		std::cout << "amount:" << this->checkAmount() << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}


// ************************************************************************** //

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// ************************************************************************** //

void	Account::_displayTimestamp(void)
{
	time_t		raw_time;
	struct tm	*time_info;
	char		buffer[18];

	time(&raw_time);
	time_info = localtime(&raw_time);

	strftime(buffer, 18, "[%G%m%d_%H%M%S]", time_info);
	std::cout << buffer;
}

// ************************************************************************** //
