/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:12:12 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/09 17:05:00 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class GradeTooHighException : public std::exception {
public:
	const char* what() const throw();
};

class GradeTooLowException : public std::exception {
	const char* what() const throw();
};

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat( const std::string& name );
	Bureaucrat( int grade );
	Bureaucrat( const std::string& name, int grade );
	Bureaucrat( const Bureaucrat& src );
	Bureaucrat& operator=( const Bureaucrat& src );
	~Bureaucrat();

	const std::string&	getName( void ) const;
	const int&			getGrade( void ) const;

	void	upgrade( void );
	void	downgrade( void );
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& src);
