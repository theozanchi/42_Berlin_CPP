/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:52:25 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/25 12:28:09 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int	PresidentialPardonForm::_counter = 0;

/* Constructors, assignment operator and destructor ************************* */

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) :
	AForm(	"presidential_pardon_form_" + to_string(_counter++),
			25,
			5,
			target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) : AForm( src ) {}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& src ) {
	if (this != &src) {
		AForm::operator=(src);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* Member functions ********************************************************* */

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const {
	if (isExecutable(executor)) {
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}
