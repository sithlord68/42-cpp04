/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:57:16 by pascal            #+#    #+#             */
/*   Updated: 2025/11/07 17:17:59 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "MyDebug.hpp"
#include "MyDisplay.hpp"
#include <string>
#include <iostream>

const std::string	Cure::className = "[Cure]";	// class name for debug

Cure::Cure( void ):
	AMateria( "cure" )
{
	MyDebug() << className << "default constructor";
	return;
}

Cure::~Cure( void )
{
	MyDebug() << className << "destructor";
	return;
}

Cure::Cure( const Cure & rhs ):
	AMateria(rhs)
{
	MyDebug() << className << "copy constructor";
	return;
}

Cure &	Cure::operator=( const Cure & rhs )
{
	MyDebug() << className << "= operator";
	if (this != &rhs)
	{
		// Appel à l'opérateur = de la classe parent
		AMateria::operator=(rhs);
	}
	return *this;
}

AMateria*	Cure::clone( void ) const
{
	MyDebug() << className << "clone m.function";
	return	new Cure(*this);
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
