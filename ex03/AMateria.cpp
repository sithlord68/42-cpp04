/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:42 by pascal            #+#    #+#             */
/*   Updated: 2025/11/05 20:10:16 by yoda             ###   ########.fr       */
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
	std::clog << "[Amateria] " << str << std::endl;
}

AMateria::AMateria( void ): _type("")
{
	AMDebug("default constructor");
	return;
}

AMateria::~AMateria ( void )
{
	AMDebug("destructor");
	return;
}

AMateria::AMateria( const AMateria & rhs ): _type( rhs.getType() )
{
	AMDebug("copy constructor");
	return;
}

AMateria &	AMateria::operator=( const AMateria & rhs )
{
	AMDebug("= operator " + rhs.getType());
//	this->_type = rhs._type;
	return *this;
}

AMateria::AMateria( const std::string & type ): _type( type )
{
	AMDebug("named constructor " + type);
	return ;
}

std::string const & AMateria::getType( void ) const
{
	AMDebug("getType m.function " + this->_type);
	return this->_type;
}

void	AMateria::use( ICharacter& target )
{
	std::cout << "* uses " << this->getType() << " materia at " << target.getName() << std::endl;
	return;
}
