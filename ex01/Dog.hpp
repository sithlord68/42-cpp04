/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:27:46 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/23 17:05:32 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
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
		Dog( const std::string name );
		void		makeSound( void ) const;
		void		setBrain( void );
		void		getBrain( void );
		Dog & 		operator=( const Dog & dog );  // canon = operator	

		void		setSound( std::string sound );
		std::string	getSound( void ) const;

	private:

		Brain		*_brain;
		std::string	_sound;
		static void	DogDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, Dog const & object );

#endif
