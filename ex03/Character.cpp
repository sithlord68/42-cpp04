/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:57:04 by pascal            #+#    #+#             */
/*   Updated: 2025/11/07 16:38:10 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "MyDebug.hpp"
#include "MyDisplay.hpp"
#include <string>
#include <iostream>

const std::string	Character::className = "[Character]";	// class name for debug

std::string	Character::getName( void ) const
{
	return this->_name;
}

Character::Character( const std::string name ):
	_name( name ),
	_equip( NULL ),
	_floor( NULL )
{
	MyDebug() << className << this->getName() << "created by default constructor";
	return;
}

Character::~Character( void )
{
	s_equip	*cur = this->_equip;
	s_equip *next = NULL;
	while ( cur )
	{
		next = cur->next;
		if (cur->materia)
		{
			MyDebug() << className << "Materia" << cur->materia->getType() << "deleted equiped on" << this->getName();
			delete(cur->materia);
		}
		delete(cur);
		MyDebug() << className << "Equipement slot deleted on " << this->getName();
		cur = next;
	}
	this->_equip = NULL;
	cur = this->_floor;
	while ( cur )
	{
		next = cur->next;
		if (cur->materia)
		{
			MyDebug() << className << "Materia" << cur->materia->getType() << "deleted on the floor for" << this->getName();
			delete(cur->materia);
		}
		delete(cur);
		MyDebug() << className << "Floor slot deleted for " << this->getName();
		cur = next;
	}
	this->_floor = NULL;
	MyDebug() << className << this->getName() << "deleted by destructor";
	return;
}

Character::Character( const Character &	rhs ):
	_name( rhs._name ),
	_equip( NULL ),
	_floor( NULL )
{
	MyDebug() << className << this->getName() << "copied by constructor";
	s_equip	*cur = rhs._equip;
	s_equip	*newEquip = NULL;
	s_equip *mem = NULL;
	while ( cur )
	{
		newEquip = new( s_equip );
		if (mem)
			mem->next = newEquip;
		else
			this->_equip = newEquip;
		mem = newEquip;
		newEquip->id = cur->id;
		if (cur->materia)
		{
			newEquip->materia = cur->materia->clone();
			MyDebug() << className << "Materia" << cur->materia->getType() << "cloned and equiped on" << this->getName();
		}
		else
		{
			newEquip->materia = NULL;
			MyDebug() << className << "Materia slot empty on" << this->getName();
		}
		newEquip->next = NULL;
		cur = cur->next;
	}
	cur = rhs._floor;
	mem = NULL;
	while ( cur )
	{
		newEquip = new( s_equip );
		if (mem)
			mem->next = newEquip;
		else
			this->_floor = newEquip;
		mem = newEquip;
		newEquip->id = cur->id;
		if (cur->materia)
		{
			newEquip->materia = cur->materia->clone();
			MyDebug() << className << "Materia" << cur->materia->getType() << "cloned and deposit on floor for" << this->getName();
		}
		else
		{
			newEquip->materia = NULL;
			MyDebug() << className << "Floor slot empty for" << this->getName();
		}
		newEquip->next = NULL;
		cur = cur->next;
	}
	return;
}

Character &	Character::operator=( const Character & rhs )
{
	this->_name = rhs.getName();
	this->_equip = NULL;
	this->_floor = NULL;
	MyDebug() << className << this->getName() << " copied by = operator";
	s_equip	*cur = rhs._equip;
	s_equip	*newEquip = NULL;
	s_equip *mem = NULL;
	while ( cur )
	{
		newEquip = new( s_equip );
		if (mem)
			mem->next = newEquip;
		else
			this->_equip = newEquip;
		mem = newEquip;
		newEquip->id = cur->id;
		if (cur->materia)
		{
			newEquip->materia = cur->materia->clone();
			MyDebug() << className << "Materia" << cur->materia->getType() << "cloned and equiped on" << this->getName();
		}
		else
		{
			newEquip->materia = NULL;
			MyDebug() << className << "Materia slot empty on" << this->getName();
		}
		newEquip->next = NULL;
		cur = cur->next;
	}
	cur = rhs._floor;
	mem = NULL;
	while ( cur )
	{
		newEquip = new( s_equip );
		if (mem)
			mem->next = newEquip;
		else
			this->_floor = newEquip;
		mem = newEquip;
		newEquip->id = cur->id;
		if (cur->materia)
		{
			newEquip->materia = cur->materia->clone();
			MyDebug() << className << "Materia" << cur->materia->getType() << "cloned and deposit on floor for" << this->getName();
		}
		else
		{
			newEquip->materia = NULL;
			MyDebug() << className << "Floor slot empty for" << this->getName();
		}
		newEquip->next = NULL;
		cur = cur->next;
	}
	return *this;
}

void Character::equip( AMateria* materia )
{
	s_equip	*equip = this->_equip;
    if (!materia)
    {
        MyDebug() << className << "Cannot equip NULL materia";
        return;
    }
	int		i = 0;
	while ( i < 4 && equip && equip->materia )
	{
		equip = equip->next;
		i++;
	}
	if ( equip && !equip->materia )
	{
		equip->materia = materia;
		MyDebug() << className << "Materia" << materia->getType() << "equiped on character" << this->getName();
	}
	else if (i < 4)
	{
		s_equip	*newEquip = new s_equip;
		newEquip->materia = equip->materia;
		if (equip)
			equip->next = newEquip;
		else
			this->_equip = newEquip;
		newEquip->next = NULL;
	}
	else
		MyDebug() << className << "No Materia slot free for" << this->getName();
	return;
}

void Character::unequip( int idx )
{
	MyDebug() << className << this->getName() << "unequip slot request";
	if ( idx < 0 || idx > 3 )
	{
		MyDebug() << className << "unequip slot request out of range";
		return;
	}
	s_equip	*equip = this->_equip;
	s_equip *prev = NULL;
	int	i = 0;
	while ( i != idx && i < 4 && equip )
	{
		prev = equip;
		equip = equip->next;
		i++;
	}
	if ( equip && equip->materia )
	{
		if ( prev )
			prev->next = equip->next;
		else
			this->_equip = equip->next;
		s_equip	*floor = this->_floor;
		while ( floor && floor->next )
			floor = floor->next;
		s_equip	*newFloor = new s_equip;
		newFloor->materia = equip->materia;
		newFloor->next = this->_floor;
		if ( ! floor )
			this->_floor = newFloor;
		else
			this->_floor->next = newFloor;
		equip->next = NULL;
		MyDebug() << className << "slot with" << equip->materia->getType() << "has been put on the floor";
	}
	else
		MyDebug() << className << "slot was already empty";
	return;
}

void Character::use( int idx, ICharacter& target )
{
	MyDebug() << className << this->getName() << "use slot request";
	if ( idx < 0 || idx > 3 )
	{
		MyDebug() << className << "use slot request out of range";
		return;
	}
	s_equip	*equip = this->_equip;
	int	i = 0;
	while ( i != idx && i < 4 && equip )
	{
		equip = equip->next;
		i++;
	}
	if ( equip && equip->materia )
	{
		if ( equip->materia->getType() == "cure" )
			std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
		else if ( equip->materia->getType() == "ice")
			std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
		else
			std::cout << "* used un unknown type of materia (" << equip->materia->getType() << ") on " << target.getName() << " *" << std::endl;
	}
	else
		MyDebug() << className << "slot was already empty";
	return;
}
