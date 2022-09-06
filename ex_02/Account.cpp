#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return(Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return(Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
		_displayTimestamp();
    std::cout <<"accounts:" << Account::getNbAccounts() << ";total:" \
    << Account::getTotalAmount() << ";deposits:" \
    << Account::getNbDeposits() << ";withdrawals:" \
    << Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) : _accountIndex(Account::_nbAccounts), 
_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << "amount:" \
	<< Account::_amount << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << "amount:" \
	<< Account::_amount << ";closed" << std::endl;
}

void    Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout <<"index:" << Account::_accountIndex << ";p_amount:" \
    << Account::_amount << ";deposit:" \
    << deposit << ";amount" << Account::_amount + deposit << ";nb_deposits:" \
	<< Account::_nbDeposits + 1 << std::endl;

	Account::_amount += deposit;
	Account::_nbDeposits += 1;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
	if (withdrawal > Account::_amount)
	{
		std::cout << "index:" << Account::_accountIndex << ";p_amount:" \
    	<< Account::_amount << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "index:" << Account::_accountIndex << ";p_amount:" \
    << Account::_amount << ";withdrawal:" \
    << withdrawal << ";amount" << Account::_amount - withdrawal << ";nb_withdrawals:" \
	<< Account::_nbWithdrawals + 1 << std::endl;
	
	Account::_amount -= withdrawal;
	Account::_nbWithdrawals += 1;
	Account::_totalNbWithdrawals++; 
	Account::_totalAmount -= withdrawal;
	return (true);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:"
		<< this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

//private:

	

	void	Account::_displayTimestamp( void )
    {
    	std::time_t t = std::time(NULL);
    	std::tm tm = *localtime(&t);
    	std::cout << "[" << tm.tm_year + 1900
    	<< std::setfill('0') << std::setw(2) << tm.tm_mon
	    << std::setfill('0') << std::setw(2) << tm.tm_mday << "_"
   		<< std::setfill('0') << std::setw(2) << tm.tm_hour
    	<< std::setfill('0') << std::setw(2) << tm.tm_min
    	<< std::setfill('0') << std::setw(2) << tm.tm_sec << "] ";
		return ;
    }

	

//	Account( void );
