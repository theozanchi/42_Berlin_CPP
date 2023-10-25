/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:03:11 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/25 13:02:26 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

void	Contact::addContact(size_t current_size)
{
	std::string		labels[] = {"First name", "Last name", "Nickname", \
								"Phone number", "Darkest secret"};
	std::string*	attributes[] = {&first_name, &last_name, &nickname, \
								&phone_number, &darkest_secret};
	
	this->index = current_size;
	for (size_t i = 0; i < 5; ++i)
	{
		do
		{
			std::cout << labels[i] << ": ";
			if (!std::getline(std::cin, *attributes[i]) || std::cin.eof())
				break ;
		} while (attributes[i]->empty());
	}
	std::cout << std::endl;
}

void	Contact::setIndex(size_t index)
{
	this->index = index;
}

static std::string	format_string(std::string str)
{
	size_t	length = str.length();

	if (length == 10)
		return (str);
	else if (length < 10)
		return (std::string(10 - length, ' ') + str);
	else
		return (str.substr(0, 9) + ".");
}

void	Contact::displayContactShort(void) const
{
	std::cout << std::string(9, ' ') << this->index << " | ";
	std::cout << format_string(this->first_name) << " | ";
	std::cout << format_string(this->last_name) << " | ";
	std::cout << format_string(this->nickname) << std::endl;
}

void	Contact::displayContactLong(void) const
{
	std::string			labels[] = {"First name", "Last name", "Nickname", \
								"Phone number", "Darkest secret"};
	const std::string*	attributes[] = {&first_name, &last_name, &nickname, \
								&phone_number, &darkest_secret};
	
	for (size_t i = 0; i < 5; ++i)
		std::cout << labels[i] << ": " << *attributes[i] << std::endl;
	std::cout << std::endl;
}
