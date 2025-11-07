/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:59:23 by pascal            #+#    #+#             */
/*   Updated: 2025/11/07 17:24:24 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "MyDebug.hpp"
#include "MyDisplay.hpp"
#include <string>
#include <iostream>

const std::string	Ice::className = "[Ice]";	// class name for debug

Ice::Ice( void ):
	AMateria( "ice" )
{
	MyDebug() << className << "default constructor";
	return;
}

Ice::~Ice( void )
{
	MyDebug() << className << "destructor";
	return;
}

Ice::Ice( const Ice & rhs ):
	AMateria(rhs)
{
	MyDebug() << className << "copy constructor";
	return;
}

Ice &	Ice::operator=( const Ice & rhs )
{
	MyDebug() << className << "= operator";
	if (this != &rhs)
	{
		// Appel à l'opérateur = de la classe parent
		AMateria::operator=(rhs);
	}
	return *this;
}

AMateria*	Ice::clone( void ) const
{
	MyDebug() << className << "clone m.function";
	return	new Ice(*this);
}

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
