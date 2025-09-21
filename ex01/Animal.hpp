/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:23:13 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 23:09:15 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <sstream>

# ifndef ANIMDBG
#  define ANIMDBG 1
# endif

// virtual sur destructeur pour eviter fuite memoire en heritage

class Animal
{
	public:

		Animal( void );									// canon constructeur par defaut
		virtual	~Animal( void );						// canon destructeur

		Animal( Animal const & ct );					// canon constructeur par co;pie

		Animal	& 		operator=( Animal const & rhs );		// canon operateur =

		std::string 	getType( void ) const;
		void			setType( std::string type );
		virtual void	makeSound() const;

	protected:

		std::string	_type;

	private:
	
		static void	AnimalDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, Animal const & object );

#endif
