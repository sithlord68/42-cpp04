/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:51:00 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/22 13:03:50 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>
#include <string>
#include <sstream>

Brain::Brain( void )
{
	brainDebug("Brain constructor called", 1);
	return;
}

Brain::~Brain( void )
{
	brainDebug("Brain destructor called", 1);
	return;
}

Brain::Brain( const Brain & rhs )
{
	int	i = 0;
	while ( i < 100 )
	{
		this->ideas[i]  = rhs.ideas[i];
		i++;
	}
	brainDebug("Brain by copy constructor called", 1);
	return;
}

Brain & Brain::operator=( const Brain & rhs )
{
	if ( this != &rhs )
	{
		int	i = 0;
		while ( i < 100 )
		{
			this->ideas[i]  = rhs.ideas[i];
			i++;
		}
	}
	return *this;
}

void	Brain::brainDebug( std::string str, int level )
{
	if (!BRNDBG || BRNDBG > level)
		return;
	std::clog << str << std::endl;
}

std::ostream & operator<<(std::ostream & o, const Brain & object )
{
	int	i = 0;
	while (i < 100)
	{
		if ( !(object.ideas[i]).empty())
			o << object.ideas[i];
		i++;
	}
	return o;
}
