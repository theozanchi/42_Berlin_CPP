/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:19:02 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/23 19:31:05 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	current_size = 0;
	std::cout << "Welcome to Klingeln 3000 📞" << std::endl;
	std::cout << "Type 'ADD', 'SEARCH' or 'EXIT' to use" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Tschüß! 👋";
}

void	PhoneBook::addContact(void)
{
	
}

void	PhoneBook::searchContact(void)
{
	std::cout << "First name |  Last Name |   Nickname" << std::endl;
	if (current_size)
	{
		for (size_t i = 0; i <= this->current_size; i++)
			contacts[i].displayContact();
	}
	else
		std::cout << "🪹 Phonebook is empty" << std::endl;
}
