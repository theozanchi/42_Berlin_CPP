/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:12:12 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/10 19:26:23 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include "Exceptions.hpp"

class Form;

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

	void	signForm( Form& Form );
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& src);

#endif
