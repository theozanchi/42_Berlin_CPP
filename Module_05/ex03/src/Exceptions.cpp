/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:42:00 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/26 11:44:03 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

const char*	GradeTooHighException::what( void ) const throw() {
	return "error: grade too high";
}

const char*	GradeTooLowException::what( void ) const throw() {
	return "error: grade too low";
}

const char*	FormSignedException::what( void ) const throw() {
	return "error: Form already signed";
}

const char*	FormNotSignedException::what( void ) const throw() {
	return "error: Form not signed";
}

FormNameNotFound::FormNameNotFound( const std::string& name ) :
	message("error: " + name + " is not a valid form name") {}

const char*	FormNameNotFound::what( void ) const throw() {
	return (message.c_str());
}
