/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:27:46 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/23 17:03:17 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>
#include <sstream>

#ifndef	CAT_HPP
# define CAT_HPP

# ifndef CATDBG
#  define CATDBG 1
# endif

class Cat: virtual public Animal
{
	public:

		Cat( void );							// canon default constructor
		~Cat( void );							// canon destructor

		Cat( const Cat & cat );					// canon constructor by copy
		void		makeSound() const;

	private:
	
		static void	CatDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, Cat const & object );

#endif
