/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:03:11 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/04 21:48:42 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

void	Contact::addContact(size_t current_size)
{
	std::string		labels[] = {"First name", "Last name", "Nickname", \
								"Phone number", "Darkest secret"};
	std::string*	attributes[] = {&_first_name, &_last_name, &_nickname, \
								&_phone_number, &_darkest_secret};
	
	this->_index = current_size;
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

void	Contact::setIndex(size_t index) { _index = index; }

void	truncateAndDisplay( const std::string& str, size_t width )
{
	if (str.length() > width)
		std::cout << std::setw(width) << str.substr(0, width - 1) + ".";
	else
		std::cout << std::setw(width) << str;
	}

void	Contact::displayContactShort(void) const
{
	std::cout << std::setw(10) << _index;
	std::cout << " | ";
	truncateAndDisplay(_first_name, 10);
	std::cout << " | ";
	truncateAndDisplay(_last_name, 10);
	std::cout << " | ";
	truncateAndDisplay(_nickname, 10);
	std::cout << std::endl;
}

void	Contact::displayContactLong(void) const
{
	std::string			labels[] = {"First name", "Last name", "Nickname", \
								"Phone number", "Darkest secret"};
	const std::string*	attributes[] = {&_first_name, &_last_name, &_nickname, \
								&_phone_number, &_darkest_secret};
	
	for (size_t i = 0; i < 5; ++i)
		std::cout << labels[i] << ": " << *attributes[i] << std::endl;
	std::cout << std::endl;
}
