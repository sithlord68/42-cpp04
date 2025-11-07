/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:45:37 by pascal            #+#    #+#             */
/*   Updated: 2025/11/07 17:58:00 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

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

		std::string			getName( void ) const;
		void				equip( AMateria* materia );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );
		Character( const Character & rhs );								// canon copy by const
		Character &					operator=( const Character & rhs );	// canon operator =

	private:


		std::string			_name;
		AMateria*			_inventory[4];

		static const std::string	className;

};

#endif
