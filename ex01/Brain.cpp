/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:51:00 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 23:11:56 by pjolidon         ###   ########.fr       */
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

Brain::Brain( const Brain & ct )
{
	brainDebug("Brain by copy constructor called", 1);
	return;
}

Brain & Brain::operator=( const Brain & brain )
{
	if ( this != &brain )
	{
		Brain	newBrain = new Brain ( brain );
		this->_brain = newBrain;
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
}
