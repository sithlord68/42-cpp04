/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:19 by pascal            #+#    #+#             */
/*   Updated: 2025/09/29 22:36:19 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <string>

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

class	AMateria;

class	IMateriaSource
{

	public:

		virtual ~IMateriaSource( void );

		virtual void learnMateria( AMateria* materia ) = 0;

		virtual AMateria* createMateria( std::string const & type ) = 0;

	protected:

	private:

};

#endif