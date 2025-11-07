/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:36 by pascal            #+#    #+#             */
/*   Updated: 2025/11/07 18:04:44 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "MyDebug.hpp"
#include "MyDisplay.hpp"
#include <string>
#include <iostream>

const std::string MateriaSource::className = "[MateriaSource]";

MateriaSource::MateriaSource( void )
{
	int	i = -1;
	while (++i < 4)
		_learnedMaterias[i] = NULL;
	MyDebug() << className << "default constructor";
}

MateriaSource::~MateriaSource( void )
{
	int	i = -1;
	while (++i < 4)
	{
		if (_learnedMaterias[i])
		{
			delete _learnedMaterias[i];
			_learnedMaterias[i] = NULL;
		}
	}
	MyDebug() << className << "destructor";
}

MateriaSource::MateriaSource( const MateriaSource & rhs )
{
	int	i = -1;
	while (++i < 4)
		_learnedMaterias[i] = NULL;
	
	i = -1;
	while (++i < 4)
	{
		if (rhs._learnedMaterias[i])
			_learnedMaterias[i] = rhs._learnedMaterias[i]->clone();
	}
	MyDebug() << className << "copy constructor";
}

MateriaSource & MateriaSource::operator=( const MateriaSource & rhs )
{
	MyDebug() << className << "= operator";
	if (this != &rhs)
	{
		// Cleanup existing materias
		int	i = -1;
		while (++i < 4)
		{
			if (_learnedMaterias[i])
			{
				delete _learnedMaterias[i];
				_learnedMaterias[i] = NULL;
			}
		}
		
		// Copy new materias
		i = -1;
		while (++i < 4)
		{
			if (rhs._learnedMaterias[i])
				_learnedMaterias[i] = rhs._learnedMaterias[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria( AMateria* materia )
{
	MyDebug() << className << "learnMateria m.function";
	if (!materia)
		return;
		
	int	i = -1;
	while (++i < 4)
	{
		if (!_learnedMaterias[i])
		{
			_learnedMaterias[i] = materia;
			MyDebug() << className << "Learned" << materia->getType();
			return;
		}
	}
	// No space left
	// delete materia;   // suppression a gerer par l'appelant
	MyDebug() << className << "No space to learn new materia";
}

AMateria* MateriaSource::createMateria( std::string const & type )
{
	MyDebug() << className << "createMateria m.function" << type;
	int	i = -1;
	while (++i < 4)
	{
		if (_learnedMaterias[i] && _learnedMaterias[i]->getType() == type)
		{
			MyDebug() << className << "Creating" << type;
			return _learnedMaterias[i]->clone();
		}
	}
	MyDebug() << className << type << "not found";
	return NULL;
}
