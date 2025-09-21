/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:21:39 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 17:39:07 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Unicorn.hpp"
#include <iostream>
#include <string>
#include <sstream>

int	main ( void )
{
	Cat		chat;
	Dog		chien;
	Unicorn	licorne;

	chat.makeSound();
	chien.makeSound();
	licorne.makeSound();
	
	Cat		chaton(chat);
	Dog		chiot(chien);
	Unicorn	licorneau(licorne);

	return 0;
}