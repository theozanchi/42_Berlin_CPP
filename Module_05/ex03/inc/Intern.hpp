/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:02:04 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/25 19:21:52 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <map>

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
private:
	static AForm* createPresidentialPardonForm( const std::string& target );
	static AForm* createRobotomyRequestForm( const std::string& target );
	static AForm* createShrubberyCreationForm( const std::string& target );

	typedef AForm*	(*FormCreateFunction)(const std::string&);

	std::map<std::string, FormCreateFunction> formCreators;

public:
	Intern();
	Intern( const Intern& src );
	Intern& operator=( const Intern& src );
	~Intern();

	AForm*	makeForm(const std::string& name, const std::string& target) const;
};

#endif
