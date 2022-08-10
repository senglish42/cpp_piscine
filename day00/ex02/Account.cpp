/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 07:22:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/23 07:22:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account( int initial_deposit )
{
    Account::_amount = initial_deposit;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;
    Account::_accountIndex = Account::_nbAccounts++;
    Account::_totalAmount = Account::_totalAmount + initial_deposit;
    Account::_displayTimestamp();
    std::cout   << "index:" << Account::_accountIndex
                << ";amount:" << Account::_amount
                << ";created" << std::endl;
}
Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout   << "index:" << Account::_accountIndex
                << ";amount:" << Account::_amount
                << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout   << "index:" << Account::_accountIndex
                << ";p_amount:" << Account::checkAmount()
                << ";deposit:" << deposit;
    Account::_amount = Account::_amount + deposit;
    Account::_totalAmount = Account::_totalAmount + deposit;
    std::cout   << ":amount:" << Account::checkAmount()
                << ":nb_deposits:" << ++Account::_nbDeposits
                << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout   << "index:" << Account::_accountIndex
                << ";p_amount:" << Account::checkAmount()
                << ";withdrawal:";
    if (withdrawal > Account::_amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    std::cout   << withdrawal;
    Account::_amount = Account::_amount - withdrawal;
    Account::_totalAmount = Account::_totalAmount - withdrawal;
    std::cout   << ":amount:" << Account::checkAmount()
                << ":nb_withdrawals:" << ++Account::_nbWithdrawals
                << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return Account::_amount;
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout   << "index:" << Account::_accountIndex
                << ";amount:" << Account::_amount
                << ";deposits:" << Account::_nbDeposits
                << ":withdrawals:" << Account::_nbWithdrawals
                << std::endl;
}

int	Account::getNbAccounts( void )
{
    return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout   << "accounts:" << Account::getNbAccounts()
                << ";total:" << Account::getTotalAmount()
                << ";deposits:" << Account::getNbDeposits()
                << ";withdrawals:" << Account::getNbWithdrawals()
                << std::endl;
}

void Account::_displayTimestamp() {

    char buffer[80];
    time_t seconds = time(NULL);
    tm* info = localtime(&seconds);
    std::string format = "[%Y%m%d_%I%M%S]";
    strftime(buffer, 80, format.c_str(), info);
    std::cout << buffer;
}

int	Account::_nbAccounts = 0;

int Account::_totalAmount = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalNbWithdrawals = 0;