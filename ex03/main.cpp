/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:21:39 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/23 10:59:56 by pascal           ###   ########.fr       */
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
// test pour verifier si classe de base purement virtuelle
// la compilation ne se fait pas car on essaierait de creer une instance
//  de Animal si on enleve le commentaire de la ligne suivante:
//	Animal		instanceAnimale;
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
	std::cout << "#### RESULTS ####" << std::endl;
	i = 0;
	while (i < limit)
	{
		std::cout << "[Animal " << i << "] " << (*animaux[i]).getName() << " / ";
		std::cout << (*animaux[i]).getType() << " - ";
		std::cout << (*animaux[i]).getSound() << std::endl;
		i++;
	}
	std::cout << "#### END OF RESULTS ####" << std::endl;

	while (++i < limit)
		delete animaux[i];

	std::cout << "############## AUTRES TESTS ##############" << std::endl;
	Dog	d1("Rintintin");
	Dog d2 = d1;
	Dog d3("Bill");
	Dog	d4(d3);

	std::cout << "#### RESULTS ####" << std::endl;
	std::cout << "Dog1 " << d1.getName() << " / ";
	std::cout << d1.getType() << " - ";
	std::cout << d1.getSound() << std::endl;
	std::cout << "Dog2 (D1=) " << d2.getName() << " / ";
	std::cout << d2.getType() << " - ";
	std::cout << d2.getSound() << std::endl;
	std::cout << "Dog3 " << d3.getName() << " / ";
	std::cout << d3.getType() << " - ";
	std::cout << d3.getSound() << std::endl;
	std::cout << "Dog4 (D3 const copy) " << d4.getName() << " / ";
	std::cout << d4.getType() << " - ";
	std::cout << d4.getSound() << std::endl;
	std::cout << "#### END OF RESULTS ####" << std::endl;

	Cat c1("Gandalf");
	Cat	c2 = c1;
	Cat	c3("Athena");
	Cat c4(c3);

	std::cout << "#### RESULTS ####" << std::endl;
	std::cout << "Cat1 " << c1.getName() << " / ";
	std::cout << c1.getType() << " - ";
	std::cout << c1.getSound() << std::endl;
	std::cout << "Cat2 (C1=) " << c2.getName() << " / ";
	std::cout << c2.getType() << " - ";
	std::cout << c2.getSound() << std::endl;
	std::cout << "Cat3 " << c3.getName() << " / ";
	std::cout << c3.getType() << " - ";
	std::cout << c3.getSound() << std::endl;
	std::cout << "Cat4 (C3 const copy) " << c4.getName() << " / ";
	std::cout << c4.getType() << " - ";
	std::cout << c4.getSound() << std::endl;
	std::cout << "#### END OF RESULTS ####" << std::endl;

	Unicorn u1("Black");
	Unicorn u2 = u1;
	Unicorn	u3("White");
	Unicorn u4(u3);

	std::cout << "#### RESULTS ####" << std::endl;
	std::cout << "Unicorn1 " << u1.getName() << " / ";
	std::cout << u1.getType() << " - ";
	std::cout << u1.getSound() << std::endl;
	std::cout << "Unicorn2 (U1=) " << u2.getName() << " / ";
	std::cout << u2.getType() << " - ";
	std::cout << u2.getSound() << std::endl;
	std::cout << "Unicorn3 " << u3.getName() << " / ";
	std::cout << u3.getType() << " - ";
	std::cout << u3.getSound() << std::endl;
	std::cout << "Unicorn4 (U3 const copy) " << u4.getName() << " / ";
	std::cout << u4.getType() << " - ";
	std::cout << u4.getSound() << std::endl;
	std::cout << "#### END OF RESULTS ####" << std::endl;


	return 0;
}
