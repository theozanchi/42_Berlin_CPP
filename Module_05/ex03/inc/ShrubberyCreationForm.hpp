/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:28:06 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/22 10:14:08 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	static int	_counter;

public:
	ShrubberyCreationForm( const std::string& target );
	ShrubberyCreationForm( const ShrubberyCreationForm& src );
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& src );
	~ShrubberyCreationForm();

	void	execute( const Bureaucrat& executor ) const;
};

#endif

