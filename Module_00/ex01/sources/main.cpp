/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:48:55 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/24 09:49:40 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>

int	main(void)
{
	PhoneBook	book;
	std::string	input;

	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input == "ADD")
			book.addContact();
		else if (input == "SEARCH")
			book.searchContact();
		else if (input == "EXIT" || std::cin.eof())
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
}