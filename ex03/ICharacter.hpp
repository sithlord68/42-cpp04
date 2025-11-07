/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:45:37 by pascal            #+#    #+#             */
/*   Updated: 2025/11/07 15:45:47 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "MyDebug.hpp"

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class	AMateria;

class	ICharacter
{
	public:

		virtual ~ICharacter( void );

		virtual std::string			getName( void ) const = 0;

		virtual void				equip( AMateria* materia ) = 0;
		virtual void				unequip( int idx ) = 0;
		virtual void				use( int idx, ICharacter& target ) = 0;

	private:

		static const std::string	className;

};

#endif
