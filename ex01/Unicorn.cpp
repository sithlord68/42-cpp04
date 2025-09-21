/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unicorn.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:35:27 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 23:05:57 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unicorn.hpp"
#include <iostream>
#include <string>
#include <sstream>

Unicorn::Unicorn( void ):
	Animal(),
	_brain( new Brain )
{
	this->setType("Unicorn");
	UnicornDebug("Unicorn default constructor called", 1);
	return;
}

Unicorn::~Unicorn( void )
{
	delete this->_brain;
	UnicornDebug("Unicorn destroyer called", 1);
	return;
}

Unicorn::Unicorn( const Unicorn & unicorn ):
	Animal(unicorn),
	_brain( new Brain ( *unicorn._brain ) )
{
	this->setType(unicorn.getType());
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
	std::cout << "[" << this->getType() << "]" << "HHHHHIIIIIIiiii...." << std::endl;
	return;
}
