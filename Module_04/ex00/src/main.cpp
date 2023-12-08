/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:56:01 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 13:47:05 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include <iostream>

int	main( void ) {
	{
		std::cout << "\033[1;32mCorrect animals\033[0m" << std::endl;
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		std::cout << std::endl;
		
		std::cout << animal->getType() << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl << std::endl;

		animal->makeSound();
		dog->makeSound();
		cat->makeSound();
		std::cout << std::endl;

		delete animal, delete dog, delete cat;
	}
		{
		std::cout << std::endl << "\033[1;31mWrong animals\033[0m" << std::endl;
		const WrongAnimal* wrong_animal = new WrongAnimal();
		const WrongAnimal* wrong_dog = new WrongDog();
		const WrongAnimal* wrong_cat = new WrongCat();
		std::cout << std::endl;
		
		std::cout << wrong_animal->getType() << std::endl;
		std::cout << wrong_dog->getType() << " " << std::endl;
		std::cout << wrong_cat->getType() << " " << std::endl << std::endl;

		wrong_animal->makeSound();
		wrong_dog->makeSound();
		wrong_cat->makeSound();
		std::cout << std::endl;

		delete wrong_animal, delete wrong_dog, delete wrong_cat;
	}
}
