/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:33:07 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/26 11:55:47 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* Constructors, assignment operator and destructor ************************* */

AForm::AForm(
	const std::string& name,
	const int signGrade,
	const int execGrade,
	const std::string& target
) :	_name( name ),
	_signed( 0 ),
	_signGrade( signGrade ),
	_executeGrade( execGrade ),
	_target( target ) {
	if (_signGrade < 1 || _executeGrade < 1)
		throw (GradeTooHighException());
	else if (_signGrade > 150 || _executeGrade > 150)
		throw (GradeTooLowException());
	}

AForm::AForm(
	const AForm& src
) :	_name( src._name ),
	_signed( src._signed ),
	_signGrade( src._signGrade ),
	_executeGrade( src._executeGrade ),
	_target( src._target )
{}

AForm& AForm::operator=( const AForm& src ) {
	if (this != &src)
		_signed = src._signed;
	return (*this);
}

AForm::~AForm() {
	std::cout << "AForm " << _name << " destroyed" << std::endl;
}

/* Accessors **************************************************************** */

const std::string&	AForm::getName( void ) const { return _name; }

const bool&	AForm::getSigned( void ) const { return _signed; }

const int&	AForm::getSignGrade( void ) const { return _signGrade; }

const int&	AForm::getExecuteGrade( void ) const { return _executeGrade; }

const std::string&	AForm::getTarget( void ) const { return _target; }

/* Member functions ********************************************************* */

void	AForm::beSigned( const Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() <= _signGrade) {
		if (!_signed)
			_signed = true;
		else
			throw (FormSignedException());
	}
	else
		throw (GradeTooLowException());
}

bool	AForm::isExecutable( const Bureaucrat& bureaucrat ) const {
	if (!getSigned()) {
		throw (FormNotSignedException());
	}
	if (bureaucrat.getGrade() >= getExecuteGrade()) {
		throw (GradeTooLowException());
	}
	return (true);
}

/* Redirection operator overload ******************************************** */

std::ostream&	operator<<(std::ostream& os, const AForm& src) {
	os << "AForm " << src.getName() << (src.getSigned() ? " is signed. " : " isn't signed. ");
	os << src.getSignGrade() << " required to sign, " << src.getExecuteGrade() << " required to execute";
	return (os);
}
