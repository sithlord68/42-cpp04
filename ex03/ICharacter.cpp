/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:57:04 by pascal            #+#    #+#             */
/*   Updated: 2025/09/29 21:51:34 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <string>
#include <iostream>

ICharacter::ICharacter( void ):
	_name(""),
	_equip( NULL ),
	_floor( NULL )
{
	debug("Character " + this->getName() + " created by default constructor", 1);
	return;
}

ICharacter::~ICharacter( void )
{
	s_equip	*cur = this->_equip;
	s_equip *next = NULL;
	while ( cur )
	{
		next = cur->next;
		if (cur->materia)
		{
			debug("Materia " + cur->materia->getType() + " deleted equiped on " + this->getName(), 1);
			delete(cur->materia);
		}
		delete(cur);
		debug("Equipement slot deleted on " + this->getName(), 1);
		cur = next;
	}
	this->_equip = NULL;
	cur = this->_floor;
	while ( cur )
	{
		next = cur->next;
		if (cur->materia)
		{
			debug("Materia " + cur->materia->getType() + " deleted on the flor for " + this->getName(), 1);
			delete(cur->materia);
		}
		delete(cur);
		debug("Floor slot deleted for " + this->getName(), 1);
		cur = next;
	}
	this->_floor = NULL;
	debug("Character " + this->getName() + " deleted by destructor", 1);
	return;
}

ICharacter::ICharacter( const ICharacter &	rhs ):
	_name( rhs._name ),
	_equip( NULL ),
	_floor( NULL )
{
	debug("Character " + this->getName() + " copied by constructor", 1);
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
			debug("Materia " + cur->materia->getType() + " cloned and equiped on " + this->getName(), 1);
		}
		else
		{
			newEquip->materia = NULL;
			debug("Materia slot empty on" + this->getName(), 1);
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
			debug("Materia " + cur->materia->getType() + " cloned and deposit on floor for " + this->getName(), 1);
		}
		else
		{
			newEquip->materia = NULL;
			debug("Floor slot empty for " + this->getName(), 1);
		}
		newEquip->next = NULL;
		cur = cur->next;
	}
	return;
}

ICharacter &	ICharacter::operator=( const ICharacter & rhs )
{
	this->_name = rhs.getName();
	this->_equip = NULL;
	this->_floor = NULL;
	debug("Character " + this->getName() + " copied by = operator", 1);
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
			debug("Materia " + cur->materia->getType() + " cloned and equiped on " + this->getName(), 1);
		}
		else
		{
			newEquip->materia = NULL;
			debug("Materia slot empty on" + this->getName(), 1);
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
			debug("Materia " + cur->materia->getType() + " cloned and deposit on floor for " + this->getName(), 1);
		}
		else
		{
			newEquip->materia = NULL;
			debug("Floor slot empty for " + this->getName(), 1);
		}
		newEquip->next = NULL;
		cur = cur->next;
	}
	return;
}

void ICharacter::equip( AMateria* materia )
{
	s_equip	*equip = this->_equip;
	int		i = 0;
	while ( i < 4 && equip && equip->materia )
	{
		equip = equip->next;
		i++;
	}
	if ( equip && !equip->materia )
	{
		equip->materia = materia;
		debug("Materia " + materia->getType() + " equiped on character " + this->getName(), 2);
	}
	else
		debug("No Materia slot free for " + this->getName(), 2);
	return;
}

void ICharacter::unequip( int idx )
{
	debug("Character " + this->getName() + " unequip slot request", 1);
	if ( idx < 0 || idx > 3 )
	{
		debug("unequip slot request out of range", 1);
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
		if ( ! floor )
			this->_floor = equip->materia;
		else
			floor->next = equip->materia;
		equip->next = NULL;
		debug("slot with " + equip->materia->getType() + " has been put on the floor", 1);
	}
	else
		debug("slot was already empty", 1);
	return;
}

void ICharacter::use( int idx, ICharacter& target )
{
	debug("Character " + this->getName() + " use slot request", 1);
	if ( idx < 0 || idx > 3 )
	{
		debug("use slot request out of range", 1);
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
		debug("slot was already empty", 1);
	return;
}

void ICharacter::debug( std::string str, int level )
{
	if (!ICHDBG || ICHDBG < level )
		return;
	std::clog << str << std::endl;
	return;
}
