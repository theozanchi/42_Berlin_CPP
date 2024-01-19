/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:28:03 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/19 14:49:08 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	static int	_counter;

public:
	RobotomyRequestForm( const std::string& target );
	RobotomyRequestForm( const RobotomyRequestForm& src );
	RobotomyRequestForm& operator=( const RobotomyRequestForm& src );
	~RobotomyRequestForm();

	void	beSigned( const Bureaucrat& bureaucrat );
};

#endif
