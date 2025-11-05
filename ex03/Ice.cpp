/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:59:23 by pascal            #+#    #+#             */
/*   Updated: 2025/11/05 17:31:07 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <string>
#include <iostream>

static void	IcDebug( const std::string str )
{
	if (!ICEDBG)
		return;
	std::clog << "[ice] " << str << std::endl;
	return;
}

Ice::Ice( void ):
	AMateria( "ice" )
{
	IcDebug("default constructor");
	return;
}

Ice::~Ice( void )
{
	IcDebug("destructor");
	return;
}

Ice::Ice( const Ice & rhs ):
	AMateria("ice")
{
	IcDebug("copy constructor");
	(void)rhs;
// copy du nom et du reste
	return;
}

Ice &	Ice::operator=( const Ice & rhs )
{
	IcDebug("= operator");
	if (this != *rhs)
	{
		this->setType( rhs.getType() );
	}
	return this;
}

AMateria*	Ice::clone( void ) const
{
	IcDebug("clone m.function");
	AMateria * new = new Cure();
	new->setType( this->getType() );
	return	new;
}
