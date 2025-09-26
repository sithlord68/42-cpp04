/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:45:37 by pascal            #+#    #+#             */
/*   Updated: 2025/09/26 21:47:15 by yoda             ###   ########.fr       */
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
    	virtual ~Character( void );
		Character( void );										// canon def const
		virtual ~Character( void );									// canon destroyer

		virtual std::string const &	getName( void );
		virtual void				equip( AMateria* materia ) = 0;
		virtual void				unequip( int idx ) = 0;
		virtual void				use( int idx, Character& target ) = 0;

	private:

		std::string					_name;
		AMateria *					_invent[4];

		// private pour empecher copie du character
		Character( const Character &	rhs );			// canon copy by const
		Character &	operator=( const Character & rhs );	// canon operator =

};




#endif