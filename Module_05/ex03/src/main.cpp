/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:12:07 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/26 11:36:13 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

int	main( void ) {
	Bureaucrat*	workforce[3] = {NULL, NULL, NULL};
	Intern		someIntern;
	AForm*		forms[4] = {NULL, NULL, NULL, NULL};

	std::cout << "\033[1:32mInitialisation\033[0m" << std::endl;
	try {
		workforce[0] = new Bureaucrat("Michel", 1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		workforce[1] = new Bureaucrat("Gilbert", 150);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		workforce[2] = new Bureaucrat("Monique", 42);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << std::endl << "\033[1:32mInitialising forms\033[0m" << std::endl;
		forms[0] = someIntern.makeForm("presidential_pardon", "target");
		forms[1] = someIntern.makeForm("robotomy_request", "target");
		forms[2] = someIntern.makeForm("shrubbery_creation", "target");
		forms[3] = someIntern.makeForm("other", "target");
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "\033[1:32mForms recap\033[0m" << std::endl;
	for (size_t i = 0; i < 3; i++) {
		if (forms[i])
			std::cout << *forms[i] << std::endl;
	}

	std::cout << std::endl << "\033[1:32mSigning forms\033[0m" << std::endl;
	try {
		workforce[0]->signForm(*forms[0]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		workforce[2]->signForm(*forms[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		workforce[2]->signForm(*forms[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[1:32mUsing forms\033[0m" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		try {
			workforce[0]->executeForm(*forms[0]);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			workforce[1]->executeForm(*forms[0]);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			workforce[0]->executeForm(*forms[1]);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			workforce[0]->executeForm(*forms[2]);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
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
