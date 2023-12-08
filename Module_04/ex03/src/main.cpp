/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:12:11 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 20:31:04 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main( void ) {
	{
		std::cout << "\033[1;32mEval sheet tests\033[0m" << std::endl;
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
		std::cout << std::endl;
	}
	{
		std::cout << "\033[1;32mSome other tests\033[0m" << std::endl;
		IMateriaSource* src2 = new MateriaSource();
		src2->learnMateria(new Ice());
		src2->learnMateria(new Cure());
		src2->learnMateria(new Cure());
		src2->learnMateria(new Ice());

		Character*	anon = new Character();

		AMateria*	tmp2;
		
		tmp2 = src2->createMateria("ice");
		anon->equip(tmp2);
		anon->unequip(0);
		
		Character*	gilles = new Character("Gilles");
		anon->use(0, *gilles);
		anon->use(120, *gilles);

		delete gilles;
		delete anon;
		delete src2;
	}
	return 0;
}
