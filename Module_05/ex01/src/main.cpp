/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:12:07 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/26 11:58:24 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main( void ) {
	Bureaucrat*	workforce[3] = {NULL, NULL, NULL};
	Form*		forms[4] = {NULL, NULL, NULL, NULL};

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
		std::cout << std::endl << "\033[1:32mInitialising forms\033[0m" << std::endl;
		forms[0] = new Form("0A", 50, 50);
		forms[1] = new Form("1A", 100, 100);
		forms[2] = new Form();
		forms[3] = new Form("test", 200, 100);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "\033[1:32mForms recap\033[0m" << std::endl;
	for (size_t i = 0; i < 3; i++) {
		if (forms[i])
			std::cout << *forms[i] << std::endl;
	}

	std::cout << std::endl << "\033[1:32mWork on Forms\033[0m" << std::endl;
	try {
		workforce[1]->signForm(*forms[0]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		workforce[0]->signForm(*forms[0]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		workforce[0]->signForm(*forms[0]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		workforce[0]->signForm(*forms[2]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[1:32mForms recap\033[0m" << std::endl;
	for (size_t i = 0; i < 3; i++) {
		if (forms[i])
			std::cout << *forms[i] << std::endl;
	}
	
	std::cout << std::endl << "\033[1:32mCleanup\033[0m" << std::endl;
	for (size_t i = 0; i < 3; i++) {
		if (workforce[i])
			delete workforce[i];
	}
	for (size_t i = 0; i < 4; i++) {
		if (forms[i])
			delete forms[i];
	}
	
}
