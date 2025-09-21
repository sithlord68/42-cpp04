/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:27:46 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 23:09:19 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
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

		Cat( const Cat & cat );					// canon constructor by copy
		void		makeSound() const;
		void		setBrain( void );
		void		getBrain( void );
		Cat & 		operator=( const Cat & cat );  // canon = operator	

	private:

		Brain		*_brain;
		static void	CatDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, Cat const & object );

#endif
