/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:57:16 by pascal            #+#    #+#             */
/*   Updated: 2025/11/05 18:50:37 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <string>
#include <iostream>

static void	CrDebug( const std::string str )
{
	if (!CURDBG)
		return;
	std::clog << "[cure] " << str << std::endl;
	return;
}

Cure::Cure( void ):
	AMateria( "cure" )
{
	CrDebug("defautl constructor");
	return;
}

Cure::~Cure( void )
{
	CrDebug("destructor");
	return;
}

Cure::Cure( const Cure & rhs ):
	AMateria(rhs)
{
	CrDebug("copy constructor");
	return;
}

Cure &	Cure::operator=( const Cure & rhs )
{
	CrDebug("= operator");
	if (this != &rhs)
	{
//		this->setType( rhs.getType() ); 
//		type n'est pas modifiable. suppression du setType
	}
	return *this;
}

AMateria*	Cure::clone( void ) const
{
	return	new Cure(*this);
}
