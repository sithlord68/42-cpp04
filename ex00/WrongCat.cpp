/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:04:31 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 18:17:23 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>
#include <string>
#include <sstream>

WrongCat::WrongCat( void ): WrongAnimal()
{
	this->setType("WrongCat");
	this->setSound("meow");
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
	this->setSound(wrongcat.getSound());
	WrongCatDebug("WrongCat copy constructor called", 1);
	return;
}

void	WrongCat::WrongCatDebug( std::string output, int level )
{
	if (!WCATDBG || level < WCATDBG)
		return ;
	std::clog << output << std::endl;
}

std::ostream &	operator<<(std::ostream & ssOutput, WrongCat const & o )
{
	ssOutput << o.getType();
	return ssOutput;
}
