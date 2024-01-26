/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:08 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/26 11:53:42 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Constructors, assignment operator and destructor ************************* */

Form::Form() : _name( "no_name" ), _signed( 0 ), _signGrade( 0 ), _executeGrade( 0 ) {}

Form::Form(
	const std::string& name
) :	_name( name ),
	_signed( 0 ),
	_signGrade( 0 ),
	_executeGrade( 0 )
{}

Form::Form(
	const std::string& name,
	const int signGrade,
	const int executeGrade
) :	_name( name ),
	_signGrade( signGrade ),
	_executeGrade( executeGrade ) {
	if (signGrade < 1 || executeGrade < 1)
		throw (GradeTooHighException());
	else if (signGrade > 150 || executeGrade > 150)
		throw (GradeTooLowException());
}

Form::Form(
	const Form& src
) :	_name( src._name ),
	_signed( src._signed ),
	_signGrade( src._signGrade ),
	_executeGrade( src._executeGrade ) {}

Form& Form::operator=( const Form& src ) {
	if (this != &src)
		_signed = src._signed;
	return (*this);
}

Form::~Form() {
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

/* Accessors **************************************************************** */

const std::string&	Form::getName( void ) const { return _name; }

const bool&	Form::getSigned( void ) const { return _signed; }

const int&	Form::getSignGrade( void ) const { return _signGrade; }

const int&	Form::getExecuteGrade( void ) const { return _executeGrade; }

/* Member functions ********************************************************* */

void	Form::beSigned( const Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() <= _signGrade) {
		if (!_signed)
			_signed = true;
		else
			throw (FormSignedException());
	}
	else
		throw (GradeTooLowException());
}

/* Redirection operator overload ******************************************** */

std::ostream&	operator<<(std::ostream& os, const Form& src) {
	os << "Form " << src.getName() << (src.getSigned() ? " is signed. " : " isn't signed. ");
	os << src.getSignGrade() << " required to sign, " << src.getExecuteGrade() << " required to execute";
	return (os);
}
