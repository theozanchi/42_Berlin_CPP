/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:27:44 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/22 10:15:33 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>

int	RobotomyRequestForm::_counter = 0;

/* Constructors, assignment operator and destructor ************************* */

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) :
	AForm(	"robotomy_request_form_" + std::to_string(_counter++),
			72,
			45,
			target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) : AForm( src ) {}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& src ) {
	if (this != &src) {
		AForm::operator=(src);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* Member functions ********************************************************* */

void	RobotomyRequestForm::execute( const Bureaucrat& executor ) const {
	if (isExecutable(executor)) {
		std::cout << "***Drilling noises***" << std::endl;
		std::cout << "Robotomy performed by form " << getName();
		if (_counter % 2 == 0)
			std::cout << " was successful" << std::endl;
		else
			std::cout << " failed" << std::endl;
	}
}
