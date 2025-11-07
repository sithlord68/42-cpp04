/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:57:04 by pascal            #+#    #+#             */
/*   Updated: 2025/11/07 17:29:45 by yoda             ###   ########.fr       */
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

std::string Character::getName( void ) const
{
	return this->_name;
}

Character::Character( const std::string name ): _name( name )
{
	int	i = -1;
	while (++i < 4)
		_inventory[i] = NULL;
	MyDebug() << className << this->getName() << "created by default constructor";
}

Character::~Character( void )
{
	int	i = -1;
	while (++i < 4)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	MyDebug() << className << this->getName() << "deleted by destructor";
}

Character::Character( const Character & rhs ): _name( rhs._name )
{
	int	i = -1;
	while (++i < 4)
		_inventory[i] = NULL;
	
	i = -1;
	while (++i < 4)
	{
		if (rhs._inventory[i])
			_inventory[i] = rhs._inventory[i]->clone();
	}
	MyDebug() << className << this->getName() << "copied by constructor";
}

Character & Character::operator=( const Character & rhs )
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		// Cleanup existing inventory
		int	i = -1;
		while (++i < 4)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		// Copy new inventory
		i = -1;
		while (++i < 4)
		{
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	MyDebug() << className << this->getName() << "copied by = operator";
	return *this;
}

void Character::equip( AMateria* materia )
{
	if (!materia)
	{
		MyDebug() << className << "Cannot equip NULL materia";
		return;
	}
	int	i = -1;
	while (++i < 4)
	{
		if (!_inventory[i])
		{
			_inventory[i] = materia;
			MyDebug() << className << "Materia" << materia->getType() << "equiped on slot" << i << "for" << this->getName();
			return;
		}
	}
	MyDebug() << className << "No free slot to equip materia for" << this->getName();
}

void Character::unequip( int idx )
{
	MyDebug() << className << this->getName() << "unequip slot" << idx << "request";
	if ( idx < 0 || idx > 3 )
	{
		MyDebug() << className << "unequip slot request out of range";
		return;
	}
	if (_inventory[idx])
	{
		MyDebug() << className << "Unequipped" << _inventory[idx]->getType() << "from slot" << idx;
		_inventory[idx] = NULL;
	}
	else
		MyDebug() << className << "Slot" << idx << "was already empty";
}

void Character::use( int idx, ICharacter& target )
{
	MyDebug() << className << this->getName() << "use slot" << idx << "request on" << target.getName();
	if ( idx < 0 || idx > 3 )
	{
		MyDebug() << className << "use slot request out of range";
		return;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		MyDebug() << className << "Slot" << idx << "is empty";
}
