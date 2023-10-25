/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:19:02 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/25 11:39:04 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	current_size = 0;
	index = 0;
	std::cout << "Welcome to Klingeln 3000 📞" << std::endl;
	std::cout << "Type 'ADD', 'SEARCH' or 'EXIT' to use" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << std::endl << "Closing phonebook, Tschüß! 👋" << std::endl;
}

void	PhoneBook::addContact(void)
{
	contacts[index].addContact(index);
	index = (index + 1) % 8;
	if (current_size < 8)
		current_size++;
}

static bool	input_is_valid(std::string str, int current_size)
{
	if (str.length() > 1)
		return (false);
	if (!isdigit(str[0]))
		return (false);
	if (str[0] - '0' < 0 || str[0] - '0' > (int)current_size - 1)
		return (false);
	return (true);
}

void	PhoneBook::searchContact(void) const
{
	std::string	search_index;

	if (!index)
		std::cout << "🪹  Phonebook is empty" << std::endl;
	else
	{
		std::cout << "     Index | First name |  Last Name |   Nickname";
		std::cout << std::endl;
		for (size_t i = 0; i < this->current_size; ++i)
			contacts[i].displayContactShort();
		std::cout << std::endl << "Enter an index > ";
		std::cin >> search_index;
		if (!input_is_valid(search_index, (int)current_size))
			std::cout << search_index << " is not a valid index" << std::endl;
		else
			contacts[search_index[0] - '0'].displayContactLong();
	}
}
