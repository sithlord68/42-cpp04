/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:19 by pascal            #+#    #+#             */
/*   Updated: 2025/09/29 21:53:16 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <string>

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# ifndef MSDBG
#  define MSDBG 1
# endif

class	AMateria;

class	MateriaSource
{

	public:

		MateriaSource( void );									// canon default cons
		virtual ~MateriaSource( void );							// canon destroyer

		MateriaSource( const MateriaSource & rhs );				// canon copy by cons
		MateriaSource &	operator=( const MateriaSource & rhs );	// canon copy by cons

		virtual void learnMateria(AMateria*);

		virtual AMateria* createMateria(std::string const & type);

	protected:

	private:

		static void			debug( const std::string str, int level );

};

#endif