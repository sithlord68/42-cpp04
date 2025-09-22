/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:51:58 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/22 09:29:10 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	BRAIN_HPP
# define BRAIN_HPP

# ifndef BRNDBG
#  define BRNDBG 1
# endif

# include <iostream>
# include <string>
# include <sstream>

class Brain
{

	public:

		Brain( void );							// canon default constructor
		~Brain( void );							// canon destructor

		Brain( const Brain & ct );				// canon copy constructor
		Brain & operator=( const Brain & ct );	// canon operator =

		std::string	ideas[100];

	private:
		void	brainDebug( std::string str, int level );
};

std::ostream & operator<<(std::ostream & o, const Brain & object );

#endif