/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:19 by pascal            #+#    #+#             */
/*   Updated: 2025/11/07 16:39:34 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include <string>
#include "MyDebug.hpp"

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

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

		AMateria					*_learnedMaterias[4];
		static const std::string	className;
};

#endif
