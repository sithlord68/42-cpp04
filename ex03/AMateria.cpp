/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:42 by pascal            #+#    #+#             */
/*   Updated: 2025/09/26 22:15:49 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <iostream>
#include <string>

AMateria::AMateria( void ): _type("")
{
	return;
}

AMateria::~AMateria ( void )
{
	return;
}

AMateria::AMateria( const AMateria & rhs ): _type( rhs.getType() )
{
	return;
}

AMateria &	AMateria::operator=( const AMateria & rhs )
{
	this->_type = rhs.getType();
	return;
}

AMateria::AMateria( const std::string & type ): _type( type )
{
	return ;
}

std::string const & AMateria::getType( void ) const
{
	return this->_type;
}

void	AMateria::setType( const std::string type )
{
	this->_type = type;
	return;
}

void AMateria::use( ICharacter& target )
{
	std::cout << "* users " << this->getType() << " materia at " << target.getName() << std::endl;
	return;
}
