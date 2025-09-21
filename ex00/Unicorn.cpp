/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unicorn.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:35:27 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 17:41:18 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unicorn.hpp"
#include <iostream>
#include <string>
#include <sstream>

Unicorn::Unicorn( void ): Animal()
{
	this->setType("Unicorn");
	this->setSound("whinny");
	UnicornDebug("Unicorn default constructor called", 1);
	return;
}

Unicorn::~Unicorn( void )
{
	UnicornDebug("Unicorn destroyer called", 1);
	return;
}

Unicorn::Unicorn( const Unicorn & unicorn ): Animal(unicorn)
{
	this->setType(unicorn.getType());
	this->setSound(unicorn.getSound());
	UnicornDebug("Unicorn copy constructor called", 1);
	return;
}

void	Unicorn::UnicornDebug( std::string output, int level )
{
	if (!UNICORNDBG || level < UNICORNDBG)
		return ;
	std::clog << output << std::endl;
}

std::ostream &	operator<<(std::ostream & ssOutput, Unicorn const & o )
{
	ssOutput << o.getType();
	return ssOutput;
}
