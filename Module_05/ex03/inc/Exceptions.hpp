/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:41:56 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/26 11:44:20 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>
# include <string>

class GradeTooHighException : public std::exception {
public:
	const char* what() const throw();
};

class GradeTooLowException : public std::exception {
public:
	const char* what() const throw();
};

class FormSignedException : public std::exception {
public:
	const char* what() const throw();
};

class FormNotSignedException : public std::exception {
public:
	const char* what() const throw();
};

class FormNameNotFound : public std::exception {
private:
	std::string	message;

public:
	FormNameNotFound( const std::string& name );
	~FormNameNotFound() throw() {}
	const char* what() const throw();
};

#endif
