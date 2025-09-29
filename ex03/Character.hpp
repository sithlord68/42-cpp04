/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:45:37 by pascal            #+#    #+#             */
/*   Updated: 2025/09/29 22:37:35 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <string>

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# ifndef CHADBG
#  define CHADBG 1
# endif

class	AMateria;

struct	s_equip
{
	AMateria	*materia;
	int			id;
	s_equip		*next;
};

// classe d'utilisation 'character' qui utilise l'interface ICharacter
class	Character: public ICharacter
{
	public:

		Character( std::string name );										// canon def const
		virtual ~Character( void );											// canon destroyer

		std::string const &				getName( void ) const;

	private:


		std::string						_name;
		s_equip							*_equip;
		s_equip							*_floor;

		// private pour empecher copie du character
		Character( const Character &	rhs );								// canon copy by const
		Character &						operator=( const Character & rhs );	// canon operator =

		static void	debug( std::string str, int level );

};


#endif
