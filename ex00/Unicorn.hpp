/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unicorn.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:27:46 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/23 17:03:42 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>
#include <sstream>

#ifndef	UNICORN_HPP
# define UNICORN_HPP

# ifndef UNICORNDBG
#  define UNICORNDBG 1
# endif

class Unicorn: virtual public Animal
{
	public:

		Unicorn( void );							// canon default constructor
		~Unicorn( void );							// canon destructor

		Unicorn( const Unicorn & Unicorn );			// canon constructor by copy
		void		makeSound( void ) const;

	private:
	
		static void	UnicornDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, Unicorn const & object );

#endif
