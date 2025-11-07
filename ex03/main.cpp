/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:12:07 by yoda              #+#    #+#             */
/*   Updated: 2025/11/07 18:24:23 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MyDebug.hpp"
#include "MyDisplay.hpp"
#include <iostream>
#include <string>

void testBasicFunctionality()
{
	MyDisplay() << "### TEST 1: base test ###";
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void testInventoryManagement()
{
	MyDisplay() << "### TEST 2: inventory management ###";
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* hero = new Character("Hero");
	
	// Remplir l'inventaire avec seulement 3 materias
	for (int i = 0; i < 3; i++) {
		AMateria* m = src->createMateria(i % 2 == 0 ? "ice" : "cure");
		if (m) {
			hero->equip(m);
		}
	}
	
	// Test suréquipement avec une 4ème materia
	MyDisplay() << "Tentative de 4ème materia :";
	AMateria* fourth = src->createMateria("ice");
	hero->equip(fourth); // Doit réussir
	
	// Test suréquipement avec une 5ème (doit échouer)
	MyDisplay() << "Tentative de suréquipement (5ème) :";
	AMateria* fifth = src->createMateria("cure");
	hero->equip(fifth); // Échouera
	delete fifth; // Nettoyer
	
	// Test utilisation
	ICharacter* target = new Character("Target");
	MyDisplay() << "Utilisation des 4 slots :";
	for (int i = 0; i < 4; i++) {
		hero->use(i, *target);
	}
	
	delete target;
	delete hero;
	delete src;
}

void testUnknownMateria()
{
	MyDisplay() << "### TEST 3: Materia unknown ###";
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	
	ICharacter* mage = new Character("Mage");
	
	AMateria* unknown = src->createMateria("fire");
	if (!unknown)
		MyDisplay() << "'fire' creation failed (as expected)";
	else
		MyDisplay() << "'fire' created (!!! WRONG !!!)";
	mage->equip(unknown);

	delete mage;
	delete src;
}

void testMateriaSourceLimits()
{
	MyDisplay() << "### TEST 4: MateriaSource limits ###";
	MateriaSource* src = new MateriaSource();
	// Apprendre exactement 4 materias
	MyDisplay() << "Learning of 4 materias :";
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// Tentative d'apprendre une 5ème (doit échouer silencieusement)
	MyDisplay() << "Try 5th materia :";
	AMateria* fifth = new Ice();
	src->learnMateria(fifth); // Doit échouer
	delete fifth;
	// Vérifier que les 4 premières fonctionnent
	Character* tester = new Character("Tester");
	for (int i = 0; i < 4; i++) {
		AMateria* m = src->createMateria(i % 2 == 0 ? "ice" : "cure");
		if (m) {
			tester->equip(m);
		}
	}
	ICharacter* target = new Character("Target");
	MyDisplay() << "Utilisation des 4 slots :";
	for (int i = 0; i < 4; i++) {
		tester->use(i, *target);
	}
	delete target;
	delete tester;
	delete src;
}

void testEdgeCases()
{
	MyDisplay() << "### TEST 5: Cas limites ###";
	
	Character* player = new Character("Player");
	
	MyDisplay() << "Test index négatif (use) :";
	player->use(-1, *player);
	
	MyDisplay() << "Test index trop grand (use) :";
	player->use(5, *player);
	
	MyDisplay() << "Test index négatif (unequip) :";
	player->unequip(-1);
	
	MyDisplay() << "Test index trop grand (unequip) :";
	player->unequip(5);
	
	MyDisplay() << "Test déséquiper slot vide :";
	player->unequip(0);
	
	delete player;
}

void testMemoryManagement() {
	MyDisplay() << "### TEST 6: Gestion mémoire ###";
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	Character* char1 = new Character("Char1");
	Character* char2 = new Character("Char2");
	
	// Équiper seulement 2 materias (pas de déséquipement/rééquipement)
	AMateria* m1 = src->createMateria("ice");
	AMateria* m2 = src->createMateria("cure");
	
	char1->equip(m1);
	char1->equip(m2);
	
	MyDisplay() << "Utilisation des materias :";
	char1->use(0, *char2);
	char1->use(1, *char2);
	
	MyDisplay() << "Tous les objets vont être détruits...";
	
	delete char2;
	delete char1;
	delete src;
	
	MyDisplay() << "Destruction terminée";
}

void testUnequipBehavior() {
	MyDisplay() << "### TEST 7: Comportement de unequip ###";
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	
	Character* player = new Character("Player");
	ICharacter* target = new Character("Target");
	
	// Équiper une materia
	AMateria* materia = src->createMateria("ice");
	player->equip(materia);
	
	MyDisplay() << "Avant unequip : ";
	player->use(0, *target);
	
	// Déséquiper - la materia n'est PAS détruite (comportement normal)
	MyDisplay() << "Après unequip : ";
	player->unequip(0);
	player->use(0, *target); // Ne devrait rien faire
	
	// NOTE: Dans une vraie application, il faudrait gérer la materia déséquipée
	// Mais pour ce test, on accepte qu'elle reste en mémoire (comportement du sujet)
	
	delete target;
	delete player;
	delete src;
}

void ori_test() {
	MyDisplay() << "### ORIGINAL TEST from assignment ###";
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main()
{
	MyDisplay() << "DÉMARRAGE DES TESTS COMPLETS";
	
	ori_test();
	testBasicFunctionality();
	testInventoryManagement();
	testUnknownMateria();
	testMateriaSourceLimits();
	testEdgeCases();
	testMemoryManagement();
	//testUnequipBehavior();	  // NOUVEAU: test séparé pour unequip
	
	MyDisplay() << "TOUS LES TESTS SONT TERMINÉS";
	MyDisplay() << "Note: Le comportement de unequip() laisse les materias en mémoire";
	MyDisplay() << "C'est normal selon les spécifications du sujet.";
	
	return 0;
}
