/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:57:04 by pascal            #+#    #+#             */
/*   Updated: 2025/11/05 20:20:14 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

static void	ChDebug( const std::string str )
{
	if (!CHADBG)
		return;
	std::clog << "[Character] " << str << std::endl;
	return;
}

std::string	Character::getName( void ) const
{
	return this->_name;
}

Character::Character( const std::string name ):
	_name( name ),
	_equip( NULL ),
	_floor( NULL )
{
	ChDebug(this->getName() + " created by default constructor");
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
			ChDebug("Materia " + cur->materia->getType() + " deleted equiped on " + this->getName());
			delete(cur->materia);
		}
		delete(cur);
		ChDebug("Equipement slot deleted on " + this->getName());
		cur = next;
	}
	this->_equip = NULL;
	cur = this->_floor;
	while ( cur )
	{
		next = cur->next;
		if (cur->materia)
		{
			ChDebug("Materia " + cur->materia->getType() + " deleted on the flor for " + this->getName());
			delete(cur->materia);
		}
		delete(cur);
		ChDebug("Floor slot deleted for " + this->getName());
		cur = next;
	}
	this->_floor = NULL;
	ChDebug(this->getName() + " deleted by destructor");
	return;
}

Character::Character( const Character &	rhs ):
	_name( rhs._name ),
	_equip( NULL ),
	_floor( NULL )
{
	ChDebug(this->getName() + " copied by constructor");
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
			ChDebug("Materia " + cur->materia->getType() + " cloned and equiped on " + this->getName());
		}
		else
		{
			newEquip->materia = NULL;
			ChDebug("Materia slot empty on" + this->getName());
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
			ChDebug("Materia " + cur->materia->getType() + " cloned and deposit on floor for " + this->getName());
		}
		else
		{
			newEquip->materia = NULL;
			ChDebug("Floor slot empty for " + this->getName());
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
	ChDebug(this->getName() + " copied by = operator");
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
			ChDebug("Materia " + cur->materia->getType() + " cloned and equiped on " + this->getName());
		}
		else
		{
			newEquip->materia = NULL;
			ChDebug("Materia slot empty on" + this->getName());
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
			ChDebug("Materia " + cur->materia->getType() + " cloned and deposit on floor for " + this->getName());
		}
		else
		{
			newEquip->materia = NULL;
			ChDebug("Floor slot empty for " + this->getName());
		}
		newEquip->next = NULL;
		cur = cur->next;
	}
	return *this;
}

void Character::equip( AMateria* materia )
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
		ChDebug("Materia " + materia->getType() + " equiped on character " + this->getName());
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
		ChDebug("No Materia slot free for " + this->getName());
	return;
}

void Character::unequip( int idx )
{
	ChDebug(this->getName() + " unequip slot request");
	if ( idx < 0 || idx > 3 )
	{
		ChDebug("unequip slot request out of range");
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
		ChDebug("slot with " + equip->materia->getType() + " has been put on the floor");
	}
	else
		ChDebug("slot was already empty");
	return;
}

void Character::use( int idx, ICharacter& target )
{
	ChDebug(this->getName() + " use slot request");
	if ( idx < 0 || idx > 3 )
	{
		ChDebug("use slot request out of range");
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
		ChDebug("slot was already empty");
	return;
}
