/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:12:11 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/22 10:19:29 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* Constructors and destructor ********************************************** */

Bureaucrat::Bureaucrat() : _name( "no_name" ), _grade( 0 ) {
	std::cout << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat( const std::string& name ) : _name( name ), _grade( 0 ) {
	std::cout << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat( int grade ) : _name( "no_name" ), _grade( grade ) {
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	std::cout << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name( name ), _grade( grade ) {
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	std::cout << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : _name( src._name ), _grade( src._grade ) {
	std::cout << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& src ) {
	if (this != &src) 
		_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

/* Accessors **************************************************************** */

const std::string&	Bureaucrat::getName( void ) const { return _name; }

const int&			Bureaucrat::getGrade( void ) const { return _grade; }

/* Member functions ********************************************************* */

void	Bureaucrat::upgrade( void ) {
	if (_grade > 1) { //best grade is 1, worst grade is 150
		_grade--;
		std::cout << "Done";
	}
	else
		throw(GradeTooHighException());
}

void	Bureaucrat::downgrade( void ) {
	if (_grade < 150) { //best grade is 1, worst grade is 150
		_grade++;
		std::cout << "Done";
	}
	else
		throw(GradeTooLowException());
}

void	Bureaucrat::signForm( AForm& form ) const {
	try {
		form.beSigned(*this);
		std::cerr << "Bureaucrat " << getName() << " has signed form " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Bureaucrat " << getName() << " couldn't sign form " << form.getName();
		std::cerr << " because of following " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( const AForm& form ) const {
	try {
		form.execute(*this);
		std::cerr << "Bureaucrat " << getName() << " executed form " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Bureaucrat " << getName() << " couldn't execute form " << form.getName();
		std::cerr << " because of following " << e.what() << std::endl;
	}
}

/* Redirection operator overload ******************************************** */

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& src) {
	if (src.getGrade())
		os << src.getName() << ", bureaucrat grade " << src.getGrade();
	else
		os << src.getName() << ", bureaucrat not graded yet.";
	return (os);
}
