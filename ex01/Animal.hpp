/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:23:13 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/23 17:04:52 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# ifndef ANIMDBG
#  define ANIMDBG 1
# endif

// virtual sur destructeur pour eviter fuite memoire en heritage

class Animal
{
	public:

		Animal( void );												// canon constructeur par defaut
		virtual	~Animal( void );									// canon destructeur

		Animal( const std::string name );
		Animal( Animal const & ct );								// canon constructeur par co;pie

		Animal	&	operator=( Animal const & rhs );		// canon operateur =

		virtual std::string getType( void ) const;
		void				setType( std::string type );
		virtual void		makeSound( void ) const;
		virtual void		setSound( std::string sound );
		virtual std::string	getSound( void ) const;

		void				setName( const std::string );
		std::string			getName( void ) const;

	protected:

		std::string	_type;
		std::string	_name;

	private:

		std::string		_sound;
		static void	AnimalDebug( std::string output, int level );
		static int		__nbAnimals;
};

std::ostream &	operator<<(std::ostream & ssOutput, Animal const & object );

#endif
