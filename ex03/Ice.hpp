/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:00:18 by pascal            #+#    #+#             */
/*   Updated: 2025/09/23 17:52:52 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#ifndef ICE_HPP
# define ICE_HPP

class ice : public AMateria
{

	public:

		ice( void );
		~ice( void );
	
		ice( const ice & rhs );
		ice &	operator=( const ice & rhs );

		ice &	clone( void );

	private:

};

#endif