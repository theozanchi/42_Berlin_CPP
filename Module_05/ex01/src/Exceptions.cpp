/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:42:00 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/10 18:48:58 by tzanchi          ###   ########.fr       */
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
