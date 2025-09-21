/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:24:44 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 14:40:10 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>
#include <sstream>

Animal::Animal( void ): type("")
{
	AnimalDebug( "Animal \"" + this->type + "\" under construction", 9);
	return ;
}

Animal::~Animal ( void )
{
	AnimalDebug( "Animal \"" + this->type + "\" is beeing destructed", 9);
	return ;
}

Animal::Animal( Animal const & ct )
{
	this->type = ct.type;
	AnimalDebug( "Animal " + ct.type + " has been constructed", 9);
	return ;
}

Animal	& Animal::operator=( Animal const & rhs )
{
	this->type = rhs.type;
	AnimalDebug( "Animal " + rhs.type + " has been cloned", 9);
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
