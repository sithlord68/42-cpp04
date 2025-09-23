/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:57:10 by pascal            #+#    #+#             */
/*   Updated: 2025/09/23 17:53:01 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#ifndef	CURE_HPP
# define CURE_HPP

class cure : public AMateria
{
	public:

		cure( void );
		~cure( void );

		cure( const cure & rhs );
		cure &	operator=( const cure & rhs );

		cure &	clone( void );

	private:


};

#endif