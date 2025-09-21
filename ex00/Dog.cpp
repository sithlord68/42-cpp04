/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:35:27 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 17:40:13 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>
#include <sstream>

Dog::Dog( void ): Animal()
{
	this->setType("Dog");
	this->setSound("barks");
	DogDebug("Cat default constructor called", 1);
	return;
}

Dog::~Dog( void )
{
	DogDebug("Cat destroyer called", 1);
	return;
}

Dog::Dog( const Dog & dog ): Animal(dog)
{
	this->setType(dog.getType());
	this->setSound(dog.getSound());
	DogDebug("Dog copy constructor called", 1);
	return;
}

void	Dog::DogDebug( std::string output, int level )
{
	if (!DOGDBG || level < DOGDBG)
		return ;
	std::clog << output << std::endl;
}

std::ostream &	operator<<(std::ostream & ssOutput, Dog const & o )
{
	ssOutput << o.getType();
	return ssOutput;
}
