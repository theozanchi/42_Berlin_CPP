/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:52:29 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/22 10:13:57 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
	static int	_counter;

public:
	PresidentialPardonForm( const std::string& target );
	PresidentialPardonForm( const PresidentialPardonForm& src );
	PresidentialPardonForm& operator=( const PresidentialPardonForm& src );
	~PresidentialPardonForm();

	void	execute( const Bureaucrat& executor ) const;
};

#endif
