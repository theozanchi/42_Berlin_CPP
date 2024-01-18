/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:41:56 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/10 18:52:33 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP
# include <exception>

class GradeTooHighException : public std::exception {
public:
	const char* what() const throw();
};

class GradeTooLowException : public std::exception {
	const char* what() const throw();
};

class FormSignedException : public std::exception {
	public:
		const char* what() const throw();
};

#endif
