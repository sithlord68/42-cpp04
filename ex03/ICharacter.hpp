/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:45:37 by pascal            #+#    #+#             */
/*   Updated: 2025/09/26 22:49:59 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class	AMateria;

class	ICharacter
{
	public:
		ICharacter( void );													// canon def const
		virtual ~ICharacter( void );										// canon destroyer
		ICharacter( const ICharacter &	rhs );								// canon copy by const
		ICharacter &				operator=( const ICharacter & rhs );	// canon operator =

		virtual std::string const & getName( void ) const = 0;	// pure virtual function

		virtual void				equip( AMateria* materia ) = 0;
		virtual void				unequip( int idx ) = 0;
		virtual void				use( int idx, ICharacter& target ) = 0;

	private:

		std::string	_name;
		AMateria *	_materia0;
		AMateria *	_materia1;
		AMateria *	_materia2;
		AMateria *	_materia3;

};




#endif