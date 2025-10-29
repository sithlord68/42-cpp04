/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:35:27 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/22 17:12:30 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>
#include <sstream>

Cat::Cat( void ):
	Animal(),
	_brain( new Brain ),
	_sound( "mmmiiiiaaouuuu")
{
	this->setType("Cat");
	CatDebug("Cat default constructor called", 1);
	return;
}

Cat::Cat( std::string name ):
	Animal( name ),
	_brain( new Brain ),
	_sound( "mmmiiiiaaouuuu")
{
	this->setType("Cat");
	CatDebug("Cat named constructor called", 1);
	return;

}

Cat::~Cat( void )
{
	delete this->_brain;
	CatDebug("Cat destroyer called", 1);
	return;
}

Cat::Cat( const Cat & rhs ):
	Animal( rhs ),
	_brain( new Brain ( *rhs._brain ) ),
	_sound( rhs.getSound() )
{
	this->setType(rhs.getType());
	CatDebug("Cat copy constructor called", 1);
	return;
}

Cat	& Cat::operator=( const Cat & cat )
{
	if ( this != &cat )
	{
		Animal::operator=( cat );
		Brain	*newBrain = new Brain ( *cat._brain );
		this->setType(cat.getType());
		this->setSound(cat.getSound());
		delete this->_brain;
		this->_brain = newBrain;
	}
	return *this;
}

void	Cat::CatDebug( std::string output, int level )
{
	if (!CATDBG || level < CATDBG)
		return ;
	std::clog << output << std::endl;
}

std::ostream &	operator<<(std::ostream & ssOutput, Cat const & o )
{
	ssOutput << o.getType();
	return ssOutput;
}

void	Cat::makeSound( void ) const
{
	std::cout << "[" << this->getType() << "]" << this->getSound() << std::endl;
	return;
}

void	Cat::setSound( std::string sound )
{
	this->_sound = sound;
}

std::string	Cat::getSound( void ) const
{
	return	this->_sound;
}
