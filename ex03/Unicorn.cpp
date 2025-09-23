/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unicorn.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:35:27 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/22 17:13:54 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unicorn.hpp"
#include <iostream>
#include <string>
#include <sstream>

Unicorn::Unicorn( void ):
	Animal(),
	_brain( new Brain ),
	_sound( "cristal song")
{
	this->setType("Unicorn");
	UnicornDebug("Unicorn default constructor called", 1);
	return;
}

Unicorn::Unicorn( const std::string name ):
	Animal( name ),
	_brain( new Brain ),
	_sound( "cristal song")
{
	this->setType("Unicorn");
	UnicornDebug("Unicorn named constructor called", 1);
	return;
}

Unicorn::~Unicorn( void )
{
	delete this->_brain;
	UnicornDebug("Unicorn destroyer called", 1);
	return;
}

Unicorn::Unicorn( const Unicorn & rhs ):
	Animal( rhs ),
	_brain( new Brain ( *rhs._brain ) ),
	_sound( rhs.getSound() )
{
	this->setType(rhs.getType());
	UnicornDebug("Unicorn copy constructor called", 1);
	return;
}

Unicorn	& Unicorn::operator=( const Unicorn & unicorn )
{
	if ( this != &unicorn )
	{
		Animal::operator=( unicorn );
		Brain	*newBrain = new Brain ( *unicorn._brain );
		delete this->_brain;
		this->_brain = newBrain;
	}
	return *this;
}

void	Unicorn::UnicornDebug( std::string output, int level )
{
	if (!UNICORNDBG || level < UNICORNDBG)
		return ;
	std::clog << output << std::endl;
}

std::ostream &	operator<<(std::ostream & ssOutput, Unicorn const & o )
{
	ssOutput << o.getType();
	return ssOutput;
}

void	Unicorn::makeSound( void ) const
{
	std::cout << "[" << this->getType() << "]" << this->getSound() << std::endl;
	return;
}

void	Unicorn::setSound( std::string sound )
{
	this->_sound = sound;
}

std::string	Unicorn::getSound( void ) const
{
	return	this->_sound;
}
