/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:02:13 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/26 11:34:27 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Exceptions.hpp"

/* Constructors, assignment operator and destructor ************************* */

Intern::Intern() {
	formCreators.insert(std::make_pair("presidential_pardon", &createPresidentialPardonForm));
	formCreators.insert(std::make_pair("robotomy_request", &createRobotomyRequestForm));
	formCreators.insert(std::make_pair("shrubbery_creation", &createShrubberyCreationForm));
}

Intern::Intern( const Intern& src ) { (void)src; }

Intern& Intern::operator=( const Intern& src ) { 
	(void)src;
	return (*this);
}

Intern::~Intern() {}

/* Member functions ********************************************************* */

AForm* Intern::createPresidentialPardonForm( const std::string& target ) {
	return (new PresidentialPardonForm( target ));
}

AForm* Intern::createRobotomyRequestForm( const std::string& target ) {
	return (new RobotomyRequestForm( target ));
}

AForm* Intern::createShrubberyCreationForm( const std::string& target ) {
	return (new ShrubberyCreationForm( target ));
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) const {
	std::map<std::string, FormCreateFunction>::const_iterator	it = formCreators.find(name);
	if (it != formCreators.end()) {
		return (it->second(target));
	}
	else
		throw(FormNameNotFound(name));
}
