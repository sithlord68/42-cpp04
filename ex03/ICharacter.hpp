/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:45:37 by pascal            #+#    #+#             */
/*   Updated: 2025/09/26 11:50:41 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class	AMateria;

class	ICharacter
{
	public:
    	virtual ~ICharacter() {}
		ICharacter( void );										// canon def const
		virtual ~ICharacter() {}								// canon destroyer
		ICharacter( const ICharacter &	rhs );					// canon copy by const
		ICharacter &	operator=( const ICharacter & rhs );	// canon operator =

		virtual std::string const & getName() const = 0;		// pure virtual function

		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

	private:

		std::string	_name;
};




#endif