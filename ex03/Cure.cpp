/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:57:16 by pascal            #+#    #+#             */
/*   Updated: 2025/09/29 21:50:26 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <string>
#include <iostream>

Cure::Cure( void ): AMateria( "cure" )
{
	return;
}

Cure::~Cure( void )
{
	return;
}

Cure::Cure( const Cure & rhs ): AMateria("Cure")
{
	this->_type = rhs.getType();
	return;
}

Cure &	Cure::operator=( const Cure & rhs )
{
	this->setType( rhs.getType() );
	return;
}

AMateria*	Cure::clone( void ) const
{
	AMateria * newMateria = new Cure();
	newMateria->setType( this->getType() );
	return;
}

void	Cure::debug( const std::string str, int level )
{
	if (!CURDBG || CURDBG < level )
		return;
	std::clog << str << std::endl;
	return;
}

