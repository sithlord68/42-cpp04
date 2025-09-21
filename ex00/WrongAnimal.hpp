/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:23:13 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 18:00:23 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include <sstream>

# ifndef WANIMDBG
#  define WANIMDBG 1
# endif

// virtual sur destructeur pour eviter fuite memoire en heritage

class WrongAnimal
{
	public:

		WrongAnimal( void );									// canon constructeur par defaut
		virtual	~WrongAnimal( void );						// canon destructeur

		WrongAnimal( WrongAnimal const & ct );					// canon constructeur par co;pie

		WrongAnimal	& 		operator=( WrongAnimal const & rhs );		// canon operateur =

		std::string 	getType( void ) const;
		void			setType( std::string type );
		std::string 	getSound( void ) const;
		void			setSound( std::string sound );
		void			makeSound() const;

	protected:

		std::string	_type;
		std::string	_sound;

	private:
	
		static void	WrongAnimalDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, WrongAnimal const & object );

#endif
