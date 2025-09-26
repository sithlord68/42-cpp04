/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:57:04 by pascal            #+#    #+#             */
/*   Updated: 2025/09/26 22:55:09 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

ICharacter::ICharacter( void ):
	_name(""),
	_materia0( NULL ),
	_materia1( NULL ),
	_materia2( NULL ),
	_materia3( NULL )
{
	return;
}

ICharacter::~ICharacter( void )
{
	if ( this->_materia0 )
		delete( this->_materia0 );
	if ( this->_materia1 )
		delete( this->_materia1 );
	if ( this->_materia2 )
		delete( this->_materia2 );
	if ( this->_materia3 )
		delete( this->_materia3 );
}

ICharacter::ICharacter( const ICharacter &	rhs ):
	_name( rhs._name ),
	_materia0( NULL ),
	_materia1( NULL ),
	_materia2( NULL ),
	_materia3( NULL )
{
	if ( rhs._materia0 )
		this->_materia0 = rhs._materia0->clone();
	if ( rhs._materia1 )
		this->_materia1 = rhs._materia1->clone();
	if ( rhs._materia2 )
		this->_materia2 = rhs._materia2->clone();
	if ( rhs._materia3 )
		this->_materia3 = rhs._materia3->clone();
}

ICharacter &	ICharacter::operator=( const ICharacter & rhs )
{
	this->_name = rhs.getName();
	if ( rhs._materia0 )
		this->_materia0 = rhs._materia0->clone();
	if ( rhs._materia1 )
		this->_materia1 = rhs._materia1->clone();
	if ( rhs._materia2 )
		this->_materia2 = rhs._materia2->clone();
	if ( rhs._materia3 )
		this->_materia3 = rhs._materia3->clone();
}

void ICharacter::equip( AMateria* materia )
{
	bool	equiped = false;
	if ( !this->_materia0 )
	{
		equiped = true;
		this->_materia0 = materia->clone();
	}
	if ( !this->_materia1 && !equiped)
	{
		equiped = true;
		this->_materia1 = materia->clone();
	}
	if ( !this->_materia2 && !equiped )
	{
		equiped = true;
		this->_materia2 = materia->clone();
	}
	if ( !this->_materia3 && !equiped )
	{
		equiped = true;
		this->_materia3 = materia->clone();
	}
}

void ICharacter::unequip( int idx )
{

}

void ICharacter::use( int idx, ICharacter& target )
{

}
