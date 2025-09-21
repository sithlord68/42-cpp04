/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:27:46 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 18:43:03 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>
# include <sstream>

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
