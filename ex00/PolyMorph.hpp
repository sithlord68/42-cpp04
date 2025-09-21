/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:23:13 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/20 17:17:05 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <sstream>

# ifndef CLAPDBG
#  define CLAPDBG 1
# endif

// virtual sur destructeur pour eviter fuite memoire en heritage

class ClapTrap
{
	public:

		ClapTrap( void );									// canon constructeur par defaut
		ClapTrap( std::string name );
		ClapTrap( std::string name, int hit, int energy, int attack );
		virtual		~ClapTrap( void );						// canon destructeur

		ClapTrap( ClapTrap const & ct );					// canon constructeur par co;pie

		ClapTrap	& operator=( ClapTrap const & rhs );	// canon operateur =

		void		attack( const std::string & target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
		bool		isDestroyed( void );

		std::string	getName( void ) const;
		int			getHit( void ) const;
		int			getEnergy( void ) const;
		int			getAttack( void ) const;

		void		setName( std::string name );
		void		setHit( int value );
		void		setEnergy( int value );
		void		setAttack( int value );

	protected:

		std::string	_name;
		int			_hit;
		int			_energy;
		int			_attack;

	private:
	
		static void	ClapTrapDebug( std::string output, int level );

};

std::ostream &	operator<<(std::ostream & ssOutput, ClapTrap const & object );

#endif
