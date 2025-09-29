/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:36 by pascal            #+#    #+#             */
/*   Updated: 2025/09/29 21:43:25 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <string>
#include <iostream>

IMateriaSource::~IMateriaSource( void )
{

}

IMateriaSource::IMateriaSource( const IMateriaSource & rhs )
{

}

IMateriaSource &	IMateriaSource::operator=( const IMateriaSource & rhs )
{

}

void	IMateriaSource::learnMateria( AMateria* materia )
{

}

AMateria* IMateriaSource::createMateria( std::string const & type )
{

}

void	IMateriaSource::debug( const std::string str, int level )
{
	if (!IMSDBG || IMSDBG < level )
		return;
	std::clog << str << std::endl;
	return;
}
