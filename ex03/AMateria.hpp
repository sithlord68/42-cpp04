/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:48 by pascal            #+#    #+#             */
/*   Updated: 2025/11/05 18:17:05 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ICharacter.hpp"

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# ifndef AMADBG
#  define AMADBG 1
# endif

// class non care il y une fonction 'pure virtual'

class AMateria
{
	public:

		AMateria( void );								// canon default cons
		virtual ~AMateria ( void );								// canon destructor

		AMateria( const AMateria & rhs );				// canon copy by constructor
		AMateria &	operator=( const AMateria & rhs );	// canon operator =
		AMateria( std::string const & type );

		std::string const & getType( void ) const;		//Returns the materia type
		
		virtual AMateria*	clone( void ) const = 0;		// pure virtual class

		virtual void		use( ICharacter& target );

	protected:

		const std::string	_type;

	private:

};

#endif