/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:00:18 by pascal            #+#    #+#             */
/*   Updated: 2025/09/26 21:48:47 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#ifndef Ice_HPP
# define Ice_HPP

// tout en virtual pas obligatoire/necessaire, mais best practice
class Ice : public AMateria
{

	public:

		Ice( void );										// canon default const
		Ice( const Ice & rhs );								// canon copy const
	
		virtual	~Ice( void );								// canon dest

		Ice &				operator=( const Ice & rhs );	// canon = operator

		// type AMateria car base class renvoie AMateria
		virtual AMateria*	clone( void ) const;

	private:

};

#endif