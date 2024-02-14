/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:38:37 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/14 09:10:55 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <list>

int	main( void ) {
	{
		std::cout << "\033[1;32measyFind with std::vector\033[0m" << std::endl;
		std::vector<int>	vec;
		vec.push_back(42);
		vec.push_back(24);
		vec.push_back(0);
		std::cout << "Looking for 42: ";
		if (easyfind(vec, 42) != vec.end())
			std::cout << "found" << std::endl;
		else
			std::cout << "not found" << std::endl;
		std::cout << "Looking for 84: ";
		if (easyfind(vec, 84) != vec.end())
			std::cout << "found" << std::endl;
		else
			std::cout << "not found" << std::endl;
	}
	{
		std::cout << std::endl << "\033[1;32measyFind with std::deque\033[0m" << std::endl;
		std::deque<int>	deq;
		deq.push_back(42);
		deq.push_back(24);
		deq.push_back(0);
		std::cout << "Looking for 42: ";
		if (easyfind(deq, 42) != deq.end())
			std::cout << "found" << std::endl;
		else
			std::cout << "not found" << std::endl;
		std::cout << "Looking for 84: ";
		if (easyfind(deq, 84) != deq.end())
			std::cout << "found" << std::endl;
		else
			std::cout << "not found" << std::endl;
	}
	{
		std::cout << std::endl << "\033[1;32measyFind with std::list\033[0m" << std::endl;
		std::list<int>	lst;
		lst.push_back(42);
		lst.push_back(24);
		lst.push_back(0);
		std::cout << "Looking for 42: ";
		if (easyfind(lst, 42) != lst.end())
			std::cout << "found" << std::endl;
		else
			std::cout << "not found" << std::endl;
		std::cout << "Looking for 84: ";
		if (easyfind(lst, 84) != lst.end())
			std::cout << "found" << std::endl;
		else
			std::cout << "not found" << std::endl;
	}
}
