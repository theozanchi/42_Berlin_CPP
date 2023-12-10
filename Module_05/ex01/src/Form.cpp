/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:08 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/10 14:34:17 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Exception classes ******************************************************** */

class GradeTooHighException : public std::exception {
public:
	const char* what() const throw();
};

class GradeTooLowException : public std::exception {
	const char* what() const throw();
};

/* Constructors, assignment operator and destructor ************************* */

Form::Form() : _name( "no_name" ), _signed( 0 ), _signGrade( 0 ), _executeGrade( 0 ) {}

Form::Form( const std::string& name) : _name( name ), _signed( 0 ), _signGrade( 0 ), _executeGrade( 0 ) {}

Form::Form( const Form& src ) : _name( src._name ), _signed( src._signed ), _signGrade( src._signGrade ), _executeGrade( src._executeGrade ) {}

Form& Form::operator=( const Form& src ) {
	if (this != &src)
		_signed = src._signed;
	return (*this);
}

Form::~Form() {}

/* Accessors **************************************************************** */

const std::string&	Form::getName( void ) const { return _name; }

const bool&	Form::getSigned( void ) const { return _signed; }

const int&	Form::getSignGrade( void ) const { return _signGrade; }

const int&	Form::getExecuteGrade( void ) const { return _executeGrade; }

/* Member functions ********************************************************* */

void	Form::beSigned( const Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() <= _signGrade && !_signed)
		_signed = true;
	else
		throw (GradeTooLowException());
}

/* Redirection operator overload ******************************************** */

std::ostream&	operator<<(std::ostream& os, const Form& src) {
	os << "Form " << src.getName() << src.getSigned() ? "is signed. " : "isn't signed. ";
	os << src.getSignGrade() << " required to sign, " << src.getExecuteGrade() << " required to execute";
	return (os);
}
