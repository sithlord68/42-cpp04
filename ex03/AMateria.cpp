/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:42 by pascal            #+#    #+#             */
/*   Updated: 2025/11/05 18:16:24 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <iostream>
#include <string>

static void	AMDebug( const std::string str)
{
	if (!AMADBG)
		return;
	std::clog << str << std::endl;
}

AMateria::AMateria( void ): _type("")
{
	AMDebug("Amateria default constructor");
	return;
}

AMateria::~AMateria ( void )
{
	AMDebug("Amateria destructor");
	return;
}

AMateria::AMateria( const AMateria & rhs ): _type( rhs.getType() )
{
	AMDebug("Amateria copy constructor");
	return;
}

AMateria &	AMateria::operator=( const AMateria & rhs )
{
	AMDebug("Amaateria = operator " + rhs.getType());
	this->_type = rhs.getType();
	return;
}

AMateria::AMateria( const std::string & type ): _type( type )
{
	AMDebug("Amateria named constructor " + type);
	return ;
}

std::string const & AMateria::getType( void ) const
{
	AMDebug("Amateria getType m.function " + this->_type);
	return this->_type;
}

void	AMateria::use( ICharacter& target )
{
	std::cout << "* uses " << this->getType() << " materia at " << target.getName() << std::endl;
	return;
}
