/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:36 by pascal            #+#    #+#             */
/*   Updated: 2025/09/29 21:53:03 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <string>
#include <iostream>

MateriaSource::MateriaSource( void )
{

}

MateriaSource::~MateriaSource( void )
{

}

MateriaSource::MateriaSource( const MateriaSource & rhs )
{

}

MateriaSource &	MateriaSource::operator=( const MateriaSource & rhs )
{

}

void	MateriaSource::learnMateria( AMateria* materia )
{

}

AMateria* MateriaSource::createMateria( std::string const & type )
{

}

void	MateriaSource::debug( const std::string str, int level )
{
	if (!MSDBG || MSDBG < level )
		return;
	std::clog << str << std::endl;
	return;
}
