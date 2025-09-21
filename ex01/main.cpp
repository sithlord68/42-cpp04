/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:21:39 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 18:54:19 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Unicorn.hpp"
#include <iostream>
#include <string>
#include <sstream>

void	myTests( void )
{
	std::cout << "################## my tests ##################" << std::endl;
	Cat		chat;
	Dog		chien;
	Unicorn	licorne;

	chat.makeSound();
	chien.makeSound();
	licorne.makeSound();
	
	Cat		chaton(chat);
	Dog		chiot(chien);
	Unicorn	licorneau(licorne);
}

int	main ( void )
{
	std::cout << "################## STD TESTS #################" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "TEST CHIEN " << j->getType() << " " << std::endl;
	std::cout << "TEST CHAT " << i->getType() << " " << std::endl;
	std::cout << "TEST CHAT ";
	i->makeSound(); //will output the cat sound!
	std::cout << "TEST CHIEN ";
	j->makeSound();
	std::cout << "TEST ANIMAL ";
	meta->makeSound();
	myTests();
	return 0;
}