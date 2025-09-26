/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:48 by pascal            #+#    #+#             */
/*   Updated: 2025/09/26 22:14:09 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ICharacter.hpp"

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

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
		void				setType( const std::string type );
		
		virtual AMateria*	clone( void ) const = 0;		// pure virtual class

		virtual void		use( ICharacter& target );

	protected:

		std::string	_type;
};




#endif