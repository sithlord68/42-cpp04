/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:57:04 by pascal            #+#    #+#             */
/*   Updated: 2025/09/29 21:50:02 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

#include <string>
#include <iostream>

Character::Character( void )
{

}

Character::~Character()
{

}

std::string const &	Character::getName( void )
{

}

void	Character::equip(AMateria* materia)
{

}

void	Character::unequip( int idx )
{

}

void	Character::use( int idx, Character& target )
{

}

Character::Character( const Character &	rhs )
{

}

Character &	Character::operator=( const Character & rhs )
{

}

void	Character::debug( const std::string str, int level )
{
	if (!CHADBG || CHADBG < level )
		return;
	std::clog << str << std::endl;
	return;
}
