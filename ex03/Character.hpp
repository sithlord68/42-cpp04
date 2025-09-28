/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:45:37 by pascal            #+#    #+#             */
/*   Updated: 2025/09/28 11:27:32 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class	AMateria;

// classe d'utilisation 'character' qui utilise l'interface ICharacter
class	Character: public ICharacter
{
	public:

		Character( void );										// canon def const
		virtual ~Character( void );									// canon destroyer

		std::string const &	getName( void );
		void				equip( AMateria* materia );
		void				unequip( int idx );
		void				use( int idx, Character& target );

	private:

		std::string			_name;
		AMateria *			_invent[4];

		// private pour empecher copie du character
		Character( const Character &	rhs );			// canon copy by const
		Character &	operator=( const Character & rhs );	// canon operator =

};




#endif