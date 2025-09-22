/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:24:44 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/22 16:55:13 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>
#include <sstream>

int	Animal::__nbAnimals = 0;

Animal::Animal( void ):
	_type("Animal"),
	_name(""),
	_sound("Animal noise")
{
	std::stringstream o;
	o << "Pet nb " << __nbAnimals++;
	this->_name = o.str();
	AnimalDebug( "Animal \"" + this->_type + "\" under construction", 9);
	return ;
}

Animal::Animal( const std::string name ):
	_type("Animal"),
	_name( name ),
	_sound("Animal noise")
{
	__nbAnimals++;
	AnimalDebug( "Animal \"" + this->_type + "\" under construction", 9);
	return ;
}

Animal::~Animal ( void )
{
	__nbAnimals--;
	AnimalDebug( "Animal \"" + this->_type + "\" is beeing destructed", 9);
	return ;
}

Animal::Animal( Animal const & rhs ):
	_type( rhs.getType() ),
	_name( rhs.getName() ),
	_sound( rhs.getSound() )

{
	__nbAnimals++;
	AnimalDebug( "Animal " + rhs.getType() + " has been constructed", 9);
	return ;
}

Animal	& Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->setType( rhs.getType() );
		this->setSound( rhs.getSound() );
		this->setName( rhs.getName() );
	}
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

void	Animal::makeSound( void ) const
{
	std::cout << "[" << this->getType() << "]" << "animal language speaking" << std::endl;
	return;
}

void	Animal::setSound( std::string sound )
{
	this->_sound = sound;
}

std::string	Animal::getSound( void ) const
{
	return	this->_sound;
}

void	Animal::setName( const std::string name )
{
	this->_name = name;
	return;
}

std::string	Animal::getName( void ) const
{
	return this->_name;
}
