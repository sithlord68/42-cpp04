/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:27:46 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/23 17:03:31 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>
#include <sstream>

#ifndef	DOG_HPP
# define DOG_HPP

# ifndef DOGDBG
#  define DOGDBG 1
# endif

class Dog: virtual public Animal
{
	public:

		Dog( void );							// canon default constructor
		~Dog( void );							// canon destructor

		Dog( const Dog & dog );					// canon constructor by copy
		void		makeSound( void ) const;

	private:
	
		static void	DogDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, Dog const & object );

#endif
