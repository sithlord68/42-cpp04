/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:59:23 by pascal            #+#    #+#             */
/*   Updated: 2025/09/26 12:15:29 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ): Amateria( "ice" )
{
	return;
}

~Ice::Ice( void )
{
	return;
}

Ice::Ice( const Ice & rhs ): Amateria("ice")
{
// copy du nom et du reste
	return;
}

Ice &	Ice::operator=( const Ice & rhs )
{
	Amateria("ice");
// copy du nom et du reste
	return;
}

virtual Amateria*	clone( void ) const
{
// copy du materia
	return;
}
