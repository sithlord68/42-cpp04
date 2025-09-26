/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:57:10 by pascal            #+#    #+#             */
/*   Updated: 2025/09/26 12:14:58 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#ifndef	Cure_HPP
# define Cure_HPP

// tout en virtual pas obligatoire/necessaire, mais best practice
class Cure : public AMateria
{

	public:

		Cure( void );									// canon default const
		Cure( const Cure & rhs );							// canon copy const
	
		virtual	~Cure( void );							// canon dest

		Cure &			operator=( const Cure & rhs );	// canon = operator

		// type Amateria car base class renvoie Amateria
		virtual Amateria*	clone( void ) const;

	private:

};


#endif