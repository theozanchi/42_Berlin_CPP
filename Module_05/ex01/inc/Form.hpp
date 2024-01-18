/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:10 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/18 13:00:28 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Exceptions.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_executeGrade;

public:
	Form();
	Form( const std::string& name );
	Form( const std::string& name, const int signGrade, const int executeGrade );
	Form( const Form& src );
	Form& operator=( const Form& src );
	~Form();

	const std::string&	getName( void ) const;
	const bool&			getSigned( void ) const;
	const int&			getSignGrade( void ) const;
	const int&			getExecuteGrade( void ) const;

	void	beSigned( const Bureaucrat& bureaucrat );
};

std::ostream&	operator<<(std::ostream& os, const Form& src);

#endif
