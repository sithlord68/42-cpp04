/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:45:37 by pascal            #+#    #+#             */
/*   Updated: 2025/09/27 01:44:45 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# ifndef ICHDBG
#  define ICHDBG 1
# endif

class	AMateria;

struct	s_equip
{
	AMateria	*materia;
	int			id;
	s_equip		*next;
};

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
		s_equip		*_equip;
		s_equip		*_floor;

		static void	debug( std::string str, int level );

};




#endif