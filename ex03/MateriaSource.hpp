/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:19 by pascal            #+#    #+#             */
/*   Updated: 2025/09/26 21:57:35 by yoda             ###   ########.fr       */
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

		virtual void learnMateria(AMateria*) = 0;

		virtual AMateria* createMateria(std::string const & type) = 0;

	protected:

	private:

};

#endif