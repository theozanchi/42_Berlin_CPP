/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:33:10 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/25 12:27:50 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

# include "Exceptions.hpp"
# include "_utils.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_executeGrade;
	const std::string	_target;

public:
	AForm( const std::string& name, const int signGrade, const int execGrade, const std::string& target );
	AForm( const AForm& src );
	AForm& operator=( const AForm& src );
	virtual ~AForm();

	const std::string&	getName( void ) const;
	const bool&			getSigned( void ) const;
	const int&			getSignGrade( void ) const;
	const int&			getExecuteGrade( void ) const;
	const std::string&	getTarget( void ) const;

	void	beSigned( const Bureaucrat& bureaucrat );
	bool	isExecutable( const Bureaucrat& bureaucrat ) const;
	
	virtual void	execute( const Bureaucrat& executor ) const = 0;
};

std::ostream&	operator<<(std::ostream& os, const AForm& src);

#endif
