/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:21:39 by pjolidon          #+#    #+#             */
/*   Updated: 2025/09/21 14:14:07 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <string>
#include <sstream>

int	main ( void )
{
	ClapTrap	c1("Joe");
	ClapTrap	c2("Sam");
	ClapTrap	c3("Max", 5, 5, 5);

	ClapTrap	c4 = c3;
	c4 = c2;

	std::cout << " C1: " << c1 << std::endl;
	std::cout << " C2: " << c2 << std::endl;
	std::cout << " C3: " << c3 << std::endl;
	std::cout << " C4: " << c4 << std::endl;
	c3.attack("bad guy");
	c2.takeDamage(3);
	if (c2.isDestroyed())
		std::cout << c2 << " has been destroyed" << std::endl;
	c2.beRepaired(1);
	c3.attack("bad guy");

	ScavTrap	g1("Ma'at");
	ScavTrap	g2("Heimdall");
	ScavTrap	g3("Cerberus", 300, 400, 500);

	ScavTrap	g4 = g1;
	g4 = g3;

	std::cout << " G1: " << g1 << std::endl;
	std::cout << " G2: " << g2 << std::endl;
	std::cout << " G3: " << g3 << std::endl;
	std::cout << " G4: " << g4 << std::endl;
	g3.attack("ShapeShifter");
	g2.takeDamage(3);
	if (g2.isDestroyed())
		std::cout << g2 << " has been destroyed" << std::endl;
	g2.beRepaired(1);
	g3.attack("ShapeShifter");
	g3.beRepaired(1);

	g2.guardGate();
	g4.guardGate();

	g4.takeDamage(11);
	if (g4.isDestroyed())
		std::cout << g4 << " has been destroyed" << std::endl;

	g4.takeDamage(1000);
	if (g4.isDestroyed())
		std::cout << g4 << " has been destroyed" << std::endl;

	FragTrap	f1("Johnny 5");
	FragTrap	f2("T-800");
	std::cout << " F1: " << f1 << std::endl;
	std::cout << " F2: " << f2 << std::endl;
	f1.highFivesGuys();
	f2.highFivesGuys();

	DiamondTrap d0;
	DiamondTrap	d1("Dr Who");
	DiamondTrap	d2("DoubleFace");
	std::cout << " D0: " << d0 << std::endl;
	std::cout << " D1: " << d1 << std::endl;
	std::cout << " D2: " << d2 << std::endl;
	d1.whoAmI();
	d2.attack("You !!!");
	d1.highFivesGuys();
	d2.guardGate();
	return 0;
}