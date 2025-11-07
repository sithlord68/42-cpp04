/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:42 by pascal            #+#    #+#             */
/*   Updated: 2025/11/07 17:46:54 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "MyDebug.hpp"
#include "MyDisplay.hpp"
#include <iostream>
#include <string>

const std::string	AMateria::className = "[AMateria]";	// class name for debug

AMateria::AMateria( void ): _type("")
{
	MyDebug() << className << "default constructor";
	return;
}

AMateria::~AMateria ( void )
{
	MyDebug() << className << "destructor";
	return;
}

AMateria::AMateria( const AMateria & rhs ): _type( rhs.getType() )
{
	MyDebug() << className << "copy constructor";
	return;
}

AMateria &	AMateria::operator=( const AMateria & rhs )
{
	MyDebug() << className << "= operator" << rhs.getType();
	// On ne peut pas copier _type car il est const
	// Juste pour la compatibilite, on laisse vide
	// Les classes doivent gerer leur propre assignment
	return *this;
}

AMateria::AMateria( const std::string & type ): _type( type )
{
	MyDebug() << className << "named constructor" << type;
	return ;
}

std::string const & AMateria::getType( void ) const
{
//	MyDebug() << className << "getType m.function" << this->_type;
//	desactive, sinon trop d'affichage, car getType est used pour les display
	return this->_type;
}

void	AMateria::use( ICharacter& target )
{
	(void)target;
	return;
}
