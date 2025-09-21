/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:27:46 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 14:46:01 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>
# include <sstream>

# ifndef CATDBG
#  define CATDBG 1
# endif

class Cat: virtual public Animal
{
	public:

	Cat( void );							// canon default constructor
	~Cat( void );							// canon destructor

	Cat( const Cat & Cat );					// canon constructor by copy

	private:
	
		static void	CatDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, Cat const & object );

#endif
