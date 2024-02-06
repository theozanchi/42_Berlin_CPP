/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:30:56 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/06 09:17:58 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bases.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base*	generate( void ) {
	std::srand(static_cast<unsigned>(std::time(0)));
	int	random = std::rand() % 3;

	if (random == 0) {
		std::cout << "A randomly instanciated" << std::endl;
		return (new A());
	}
	else if (random == 1) {
		std::cout << "B randomly instanciated" << std::endl;
		return (new B());
	}
	else {
		std::cout << "C randomly instanciated" << std::endl;
		return (new C());
	}
}

void	identify( Base* p ) {
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer of type C" << std::endl;
}

void	identify( Base& p ) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference of type A" << std::endl;
	}
	catch (const std::exception& e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference of type B" << std::endl;
	}
	catch (const std::exception& e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference of type C" << std::endl;
	}
	catch (const std::exception& e) {}
}

int	main( void ) {
	Base*	p = generate();

	identify(p);
	identify(*p);
	delete p;
}
