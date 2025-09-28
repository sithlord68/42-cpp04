/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:19 by pascal            #+#    #+#             */
/*   Updated: 2025/09/28 11:25:16 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AMateria.hpp"

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

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

};

#endif