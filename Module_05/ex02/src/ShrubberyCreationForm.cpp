/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:28:04 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/22 10:16:01 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

int	ShrubberyCreationForm::_counter = 0;

/* Constructors, assignment operator and destructor ************************* */

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) :
	AForm(	"shrubbery_creation_form_" + std::to_string(_counter++),
			145,
			137,
			target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : AForm( src ) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& src ) {
	if (this != &src) {
		AForm::operator=(src);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* Member functions ********************************************************* */

void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
	if (isExecutable(executor)) {
		std::ofstream	ofs;
		ofs.open(getTarget() + "_shrubbery", std::ofstream::out);
		ofs << "   *" << std::endl;
		ofs << "  ***" << std::endl;
		ofs << " *****" << std::endl;
		ofs << "*******" << std::endl;
		ofs << "   |" << std::endl;
		ofs.close();
	}
}
