/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:19 by pascal            #+#    #+#             */
/*   Updated: 2025/11/05 17:24:42 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

#include <string>

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# ifndef MSDBG
#  define MSDBG 1
# endif

class	AMateria;

class	MateriaSource: public IMateriaSource
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

};

#endif