/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:35:36 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/14 12:48:09 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <list>

int RandomNumber () { return (std::rand()%100); }

int	main( void ) {
	{
		std::cout << "\033[1;32mTest 1\033[0m: stack filled randomly and iterated" << std::endl;
		std::srand ( unsigned ( std::time(0) ) );
		MutantStack<int>	mstack;

		for (size_t i = 0; i < 10; ++i) {
			mstack.push(RandomNumber());
		}

		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << std::endl;
		}
	}
	{
		std::cout << std::endl << "\033[1;32mTest 2\033[0m: eval sheet test (MutantStack::)" << std::endl;
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Top of stack: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size of stack after poping: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "Stack after operations: " << std::endl;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int>	s(mstack);
	}
	{
		std::cout << std::endl << "\033[1;32mTest 3\033[0m: eval sheet test (std::list)" << std::endl;
		std::list<int>	lstack;

		lstack.push_back(5);
		lstack.push_back(17);

		std::cout << "Top of stack: " << lstack.back() << std::endl;

		lstack.pop_back();

		std::cout << "Size of stack after poping: " << lstack.size() << std::endl;

		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		lstack.push_back(0);

		std::list<int>::iterator it = lstack.begin();
		std::list<int>::iterator ite = lstack.end();

		++it;
		--it;

		std::cout << "Stack after operations: " << std::endl;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
}
