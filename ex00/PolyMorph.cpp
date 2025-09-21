/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:24:44 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/20 17:17:52 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>
#include <sstream>

ClapTrap::ClapTrap( void ): _name(""), _hit(10), _energy(10), _attack(0)
{
	ClapTrapDebug( "ClapTrap \"" + this->_name + "\" just arrived within range", 9);
	return ;
}

ClapTrap::ClapTrap( std::string name ): _name(name), _hit(10), _energy(10), _attack(0)
{
	ClapTrapDebug( "ClapTrap " + name + " just arrived within range", 9);
	return ;
}

ClapTrap::ClapTrap( std::string name, int hit, int energy, int attack): _name(name), _hit(hit), _energy(energy), _attack(attack)
{
	ClapTrapDebug( "ClapTrap " + name + " has arrived on the battlefield" , 9);
	return ;
}

ClapTrap::~ClapTrap ( void )
{
	ClapTrapDebug( "ClapTrap \"" + this->_name + "\" destructor called", 9);
	return ;
}

ClapTrap::ClapTrap( ClapTrap const & ct )
{
	this->_name = ct._name;
	this->_attack = ct._attack;
	this->_energy = ct._energy;
	this->_hit = ct._hit;
	ClapTrapDebug( "ClapTrap " + ct._name + " has been constructed", 9);
	return ;
}

ClapTrap	& ClapTrap::operator=( ClapTrap const & rhs )
{
	this->_name = rhs._name;
	this->_attack = rhs._attack;
	this->_energy = rhs._energy;
	this->_hit = rhs._hit;
	ClapTrapDebug( "ClapTrap " + rhs._name + " has been cloned", 9);
	return *this;
}

void	ClapTrap::attack( const std::string & target)
{
	if ( this->_energy < 1 )
	{
		std::cout << "ClapTrap " << this->_name << " hasn't enough energy to attack" << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attack << " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << amount;
	std::cout << " points of damage!" << std::endl;
	this->_hit -= amount;
	if ( this->_hit < 1 )
		ClapTrapDebug( "ClapTrap " + this->_name + " is recycled to a bin", 9);
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if ( this->_energy < 1 )
	{
		std::cout << "ClapTrap " << this->_name << " can't repair because of energy to low" << std::endl;
		return ;
	}
	this->_energy--;
	this->_hit += amount;
	std::cout << "ClapTrap " << this->_name << " has repaired with " << amount;
	std::cout << " points. He now has " << this->_hit << " hit points" << std::endl;
	return ;
}

void	ClapTrap::ClapTrapDebug( std::string output, int level )
{
	if (!CLAPDBG || level < CLAPDBG)
		return ;
	std::clog << output << std::endl;
}

std::string	ClapTrap::getName( void ) const
{
	return this->_name;
}

int	ClapTrap::getHit( void ) const
{
	return this->_hit;
}

int	ClapTrap::getEnergy( void ) const
{
	return this->_energy;
}

int	ClapTrap::getAttack( void ) const
{
	return this->_attack;
}

std::ostream &	operator<<(std::ostream & ssOutput, ClapTrap const & o )
{
	ssOutput << "\"" << o.getName() << "\" (HP:" << o.getHit() << ",EN:" << o.getEnergy() << ",AT:" << o.getAttack() << ")";
	return ssOutput;
}

bool	ClapTrap::isDestroyed( void )
{
	if ( this->_hit < 1)
		return true;
	return false;
}

void	ClapTrap::setName( std::string name )
{
	this->_name = name;
}

void	ClapTrap::setHit( int value )
{
	this->_hit = value;
}

void	ClapTrap::setEnergy( int value )
{
	this->_energy = value;
}

void	ClapTrap::setAttack( int value )
{
	this->_attack = value;
}
