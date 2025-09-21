/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:24:44 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 17:42:58 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>
#include <sstream>

Animal::Animal( void ): _type("Animal"), _sound("Cri")
{
	AnimalDebug( "Animal \"" + this->_type + "\" under construction", 9);
	return ;
}

Animal::~Animal ( void )
{
	AnimalDebug( "Animal \"" + this->_type + "\" is beeing destructed", 9);
	return ;
}

Animal::Animal( Animal const & ct )
{
	this->setType(ct.getType());
	this->setSound(ct.getSound());
	AnimalDebug( "Animal " + ct._type + " has been constructed", 9);
	return ;
}

Animal	& Animal::operator=( Animal const & rhs )
{
	this->_type = rhs._type;
	AnimalDebug( "Animal " + rhs._type + " has been cloned", 9);
	return *this;
}

void	Animal::AnimalDebug( std::string output, int level )
{
	if (!ANIMDBG || level < ANIMDBG)
		return ;
	std::clog << output << std::endl;
}

std::ostream &	operator<<(std::ostream & ssOutput, Animal const & o )
{
	ssOutput << o.getType();
	return ssOutput;
}

void	Animal::setType( std::string type )
{
	this->_type = type;
	return;
}

std::string	Animal::getType( void ) const
{
	return this->_type;
}

void	Animal::setSound( std::string sound )
{
	this->_sound = sound;
	return;
}

std::string	Animal::getSound( void ) const
{
	return this->_sound;
}

void	Animal::makeSound( void ) const
{
	std::cout << "[" << this->getType << "]" << this->getSound() << std::endl;
	return;
}