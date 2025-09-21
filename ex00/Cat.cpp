/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:35:27 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 17:44:46 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>
#include <sstream>

Cat::Cat( void ): Animal()
{
	this->setType("Cat");
	this->setSound("meow");
	CatDebug("Cat default constructor called", 1);
	return;
}

Cat::~Cat( void )
{
	CatDebug("Cat destroyer called", 1);
	return;
}

Cat::Cat( const Cat & cat ): Animal(cat)
{
	this->setType(cat.getType());
	this->setSound(cat.getSound());
	CatDebug("Cat copy constructor called", 1);
	return;
}

void	Cat::CatDebug( std::string output, int level )
{
	if (!CATDBG || level < CATDBG)
		return ;
	std::clog << output << std::endl;
}

std::ostream &	operator<<(std::ostream & ssOutput, Cat const & o )
{
	ssOutput << o.getType();
	return ssOutput;
}
