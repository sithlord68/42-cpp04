/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:35:27 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/22 14:51:55 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>
#include <sstream>

Dog::Dog( void ):
	Animal(),
	_brain( new Brain ),
	_sound( "wwwaaaffff")
{
	this->setType("Dog");
	DogDebug("Dog default constructor called", 1);
	return;
}

Dog::~Dog( void )
{
	delete this->_brain;
	DogDebug("Dog destroyer called", 1);
	return;
}

Dog::Dog( const Dog & dog ):
	Animal(dog),
	_brain(new Brain ( *dog._brain )),
	_sound( dog.getSound() )
{
	this->setType(dog.getType());
	DogDebug("Dog copy constructor called", 1);
	return;
}

void	Dog::DogDebug( std::string output, int level )
{
	if (!DOGDBG || level < DOGDBG)
		return ;
	std::clog << output << std::endl;
}

Dog	& Dog::operator=( const Dog & dog )
{
	if ( this != &dog )
	{
		Animal::operator=( dog );
		Brain	*newBrain = new Brain ( *dog._brain );
		this->setType(dog.getType());
		this->setSound(dog.getSound());
		delete this->_brain;
		this->_brain = newBrain;
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & ssOutput, Dog const & o )
{
	ssOutput << o.getType();
	return ssOutput;
}

void	Dog::makeSound( void ) const
{
	std::cout << "[" << this->getType() << "]" << this->getSound() << std::endl;
	return;
}

void	Dog::setSound( std::string sound )
{
	this->_sound = sound;
}

std::string	Dog::getSound( void ) const
{
	return	this->_sound;
}
