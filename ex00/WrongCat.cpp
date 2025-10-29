/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:04:31 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 18:38:38 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>
#include <string>
#include <sstream>

WrongCat::WrongCat( void ): WrongAnimal()
{
	this->setType("WrongCat");
	WrongCatDebug("WrongCat default constructor called", 1);
	return;
}

WrongCat::~WrongCat( void )
{
	WrongCatDebug("WrongCat destroyer called", 1);
	return;
}

WrongCat::WrongCat( const WrongCat & wrongcat ): WrongAnimal(wrongcat)
{
	this->setType(wrongcat.getType());
	WrongCatDebug("WrongCat copy constructor called", 1);
	return;
}

void	WrongCat::WrongCatDebug( std::string output, int level )
{
	if (!WCATDBG || level < WCATDBG)
		return ;
	std::clog << output << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "[" << this->getType() << "]" << "MEOWWWW !!!!" << std::endl;
	return;
}

WrongCat	&WrongCat::operator=( WrongCat const &WrongCat )
{
	if ( this != &WrongCat )
		WrongAnimal::operator=( WrongCat );
	return *this;
}

std::ostream &	operator<<(std::ostream & ssOutput, WrongCat const & o )
{
	ssOutput << o.getType();
	return ssOutput;
}
