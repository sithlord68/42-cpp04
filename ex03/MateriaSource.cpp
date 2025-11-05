/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:36 by pascal            #+#    #+#             */
/*   Updated: 2025/11/05 20:13:11 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

static void	MSDebug( const std::string str )
{
	if (!MSDBG )
		return;
	std::clog << "[MateriaSource] " << str << std::endl;
	return;
}

MateriaSource::MateriaSource( void )
{
	MSDebug("default constructor");
}

MateriaSource::~MateriaSource( void )
{
	MSDebug("destructor");
}

MateriaSource::MateriaSource( const MateriaSource & rhs )
{
	MSDebug("copy constructor");
	(void)rhs;
}

MateriaSource &	MateriaSource::operator=( const MateriaSource & rhs )
{
	MSDebug("= operator");
	(void)rhs;
	return *this;
}

void	MateriaSource::learnMateria( AMateria* materia )
{
	MSDebug("leanrMateria m.function");
	(void)materia;
}

AMateria* MateriaSource::createMateria( std::string const & type )
{
	MSDebug("createMateria m.function");
	(void)type;
	return NULL;
}
