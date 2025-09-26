/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:57:16 by pascal            #+#    #+#             */
/*   Updated: 2025/09/26 22:21:18 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

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
