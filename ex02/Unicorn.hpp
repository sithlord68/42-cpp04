/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unicorn.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:27:46 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/22 17:08:56 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	UNICORN_HPP
# define UNICORN_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>
# include <sstream>

# ifndef UNICORNDBG
#  define UNICORNDBG 1
# endif

class Unicorn: virtual public Animal
{
	public:

		Unicorn( void );								// canon default constructor
		~Unicorn( void );								// canon destructor

		Unicorn( const Unicorn & Unicorn );				// canon constructor by copy
		Unicorn( const std::string name );

		void		makeSound( void ) const;
		Unicorn & operator=( const Unicorn & unicorn );  // canon = operator
		void		setSound( std::string sound );
		std::string	getSound( void ) const;

	private:

		Brain		*_brain;
		std::string	_sound;
		static void	UnicornDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, Unicorn const & object );

#endif
