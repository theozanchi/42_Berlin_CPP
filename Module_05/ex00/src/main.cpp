/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:12:07 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/09 17:16:18 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main( void ) {
	Bureaucrat*	workforce[5];
	for (size_t i = 0; i < 5; i++) {
		workforce[i] = NULL;
	}

	std::cout << "\033[1:32mInitialisation\033[0m" << std::endl;
	try {
		std::cout << "Trying Michel, grade 1: ";
		workforce[0] = new Bureaucrat("Michel", 1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << "Trying Gilbert, grade 150: ";
		workforce[1] = new Bureaucrat("Gilbert", 150);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << "Trying Monique, grade 42: ";
		workforce[2] = new Bureaucrat("Monique", 42);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << "Trying Isabelle, grade -1: ";
		workforce[3] = new Bureaucrat("Isabelle", -1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << "Trying Camille, grade 160: ";
		workforce[4] = new Bureaucrat("Camille", 160);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "\033[1:32mGrade changes\033[0m" << std::endl;
	try {
		std::cout << "Trying to upgrade " << *workforce[0] << ": ";
		workforce[0]->upgrade();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << "Trying to downgrade " << *workforce[1] << ": ";
		workforce[1]->downgrade();
	}
	catch(const std::exception& e) {
		std::cerr <<  e.what() << '\n';
	}
	try {
		std::cout << "Trying to upgrade " << *workforce[2] << ": ";
		workforce[2]->upgrade();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << std::endl << "\033[1:32mRecap\033[0m" << std::endl;
	for (size_t i = 0; i < 5; i++) {
		if (workforce[i])
			std::cout << *workforce[i] << std::endl;
	}
	
	std::cout << std::endl << std::endl << "\033[1:32mCleanup\033[0m" << std::endl;
	for (size_t i = 0; i < 5; i++) {
		if (workforce[i])
			delete workforce[i];
	}
	
}
