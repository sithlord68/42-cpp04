/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:19 by pascal            #+#    #+#             */
/*   Updated: 2025/09/29 21:52:41 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <string>

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# ifndef IMSDBG
#  define IMSDBG 1
# endif

class	AMateria;

class	IMateriaSource
{

	public:

		IMateriaSource( void );											// canon default cons
		virtual ~IMateriaSource( void );								// canon destroyer

		IMateriaSource( const IMateriaSource & rhs );					// canon copy by cons
		IMateriaSource &	operator=( const IMateriaSource & rhs );	// canon copy by cons

		virtual void learnMateria( AMateria* materia ) = 0;

		virtual AMateria* createMateria( std::string const & type ) = 0;

	protected:

	private:

		static void			debug( const std::string str, int level );

		void	IMateriaSource::debug( const std::string str, int level );

};

#endif