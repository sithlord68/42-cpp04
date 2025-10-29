/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:03:32 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/23 17:04:13 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>
#include <sstream>

#ifndef	WRONGCAT_HPP
# define WRONGCAT_HPP

# ifndef WCATDBG
#  define WCATDBG 1
# endif

class WrongCat: virtual public WrongAnimal
{
	public:

		WrongCat( void );						// canon default constructor
		~WrongCat( void );						// canon destructor

		WrongCat( const WrongCat & wrongCat );	// canon constructor by copy
		void		makeSound() const;

		WrongCat	& operator=( WrongCat const & rhs );		// canon operateur =

		
	private:
	
		static void	WrongCatDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, WrongCat const & object );

#endif
