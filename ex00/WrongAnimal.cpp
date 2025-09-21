/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:00:47 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 18:14:41 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>
#include <sstream>

WrongAnimal::WrongAnimal( void ): _type("WrongAnimal"), _sound("Cri")
{
	WrongAnimalDebug( "WrongAnimal \"" + this->_type + "\" under construction", 9);
	return ;
}

WrongAnimal::~WrongAnimal ( void )
{
	WrongAnimalDebug( "WrongAnimal \"" + this->_type + "\" is beeing destructed", 9);
	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const & ct )
{
	this->setType(ct.getType());
	this->setSound(ct.getSound());
	WrongAnimalDebug( "WrongAnimal " + ct._type + " has been constructed", 9);
	return ;
}

WrongAnimal	& WrongAnimal::operator=( WrongAnimal const & rhs )
{
	this->_type = rhs._type;
	WrongAnimalDebug( "WrongAnimal " + rhs._type + " has been cloned", 9);
	return *this;
}

void	WrongAnimal::WrongAnimalDebug( std::string output, int level )
{
	if (!WANIMDBG || level < WANIMDBG)
		return ;
	std::clog << output << std::endl;
}

std::ostream &	operator<<(std::ostream & ssOutput, WrongAnimal const & o )
{
	ssOutput << o.getType();
	return ssOutput;
}

void	WrongAnimal::setType( std::string type )
{
	this->_type = type;
	return;
}

std::string	WrongAnimal::getType( void ) const
{
	return this->_type;
}

void	WrongAnimal::setSound( std::string sound )
{
	this->_sound = sound;
	return;
}

std::string	WrongAnimal::getSound( void ) const
{
	return this->_sound;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "[" << this->getType() << "]" << this->getSound() << std::endl;
	return;
}