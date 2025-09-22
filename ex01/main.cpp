/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:21:39 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/22 15:16:01 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Unicorn.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>    // for atoi0

int	main ( int argc, char **argv )
{
	int			limit = 30;
	if ( argc < 2)
		limit = 30;
	else
		limit = atoi( argv[1]);
	Animal *	animaux[limit + 8];
	int			i = 0;
		while (i < limit / 3)
	{
		animaux[i] = new Dog;
		i++;
	}
	while (i < limit / 3 * 2)
	{
		animaux[i] = new Cat;
		i++;
	}
	while (i < limit)
	{
		animaux[i] = new Unicorn;
		i++;
	}
	animaux[i++] = new Animal;
	animaux[i++] = new Cat( animaux[limit / 3 - 1] );
	animaux[i++] = new Dog( animaux[limit / 3 * 2 - 1] );
	animaux[i++] = new Unicorn( animaux[limit - 1] );
	*animaux[i++] = *animaux[limit];
	*animaux[i++] = *animaux[limit / 3 - 1];
	*animaux[i++] = *animaux[limit / 3 * 2 - 1];
	*animaux[i++] = *animaux[limit - 1];
	i = 0;
	while (i < limit + 8)
	{
		std::cout << "[Animal " << i << "] " << (*animaux[i]).getType() << " - ";
		std::cout << (*animaux[i]).getSound() << std::endl;
		i++;
	}
	while (++i < limit + 8)
		delete animaux[i];
	return 0;
}