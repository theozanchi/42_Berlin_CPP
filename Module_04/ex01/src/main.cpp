/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:56:01 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 16:08:44 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

#include <iostream>
#define TEST_STRING "This is a test idea"

int	main( void ) {
	size_t			size = 3;
	const Animal*	array[size];
	{
		std::cout << "\033[1;32mCreating an array of animals\033[0m" << std::endl;
		
		for (size_t i = 0; i < size / 2; i++) {
			array[i] = new Dog();
			std::cout << std::endl;
		}
		for (size_t i = size / 2; i < size; i++) {
			array[i] = new Cat();
			std::cout << std::endl;
		}
		
		std::cout << std::endl;
	}
	{
		std::cout << "\033[1;32mChecking the array\033[0m" << std::endl;
		for (size_t i = 0; i < size; i++)
		{
			array[i]->getType();
			array[i]->makeSound();
		}

		std::cout << std::endl;
	}
	{
		std::cout << "\033[1;32mChecking that copies are deep copies\033[0m" << std::endl;
		
		Dog	basic;
		{
			Dog	tmp = basic;
		}
	}
	{
		std::cout << std::endl << "\033[1;32mProperly deleting\033[0m" << std::endl;
		for (size_t i = 0; i < size; i++) {
			delete array[i];
			std::cout << std::endl;
		}
	}
}
