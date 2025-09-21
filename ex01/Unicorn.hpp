/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unicorn.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:27:46 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 23:09:17 by pjolidon         ###   ########.fr       */
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
		void		makeSound( void ) const;
		Unicorn & operator=( const Unicorn & unicorn );  // canon = operator	

	private:

		Brain		*_brain;
		static void	UnicornDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, Unicorn const & object );

#endif
