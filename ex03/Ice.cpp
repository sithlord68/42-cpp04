/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:59:23 by pascal            #+#    #+#             */
/*   Updated: 2025/09/29 21:50:50 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <string>
#include <iostream>

Ice::Ice( void ): AMateria( "ice" )
{
	return;
}

Ice::~Ice( void )
{
	return;
}

Ice::Ice( const Ice & rhs ): AMateria("ice")
{
// copy du nom et du reste
	return;
}

Ice &	Ice::operator=( const Ice & rhs )
{
	this->setType( rhs.getType() );
	return;
}

AMateria*	Ice::clone( void ) const
{
	AMateria * newMateria = new Ice();
	newMateria->setType( this->getType() );
	return;
}

void	Ice::debug( const std::string str, int level )
{
	if (!ICEDBG || ICEDBG < level )
		return;
	std::clog << str << std::endl;
	return;
}
