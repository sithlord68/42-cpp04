/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:35:27 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 14:43:42 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>
#include <sstream>

Dog::Dog( void )
{

}

Dog::~Dog( void )
{

}

Dog::Dog( const Dog & dog )
{

}

void	Dog::DogDebug( std::string output, int level )
{
	if (!DOGDBG || level < DOGDBG)
		return ;
	std::clog << output << std::endl;
}

std::ostream &	operator<<(std::ostream & ssOutput, Dog const & o )
{
	ssOutput << o.getType();
	return ssOutput;
}
