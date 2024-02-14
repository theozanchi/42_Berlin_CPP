/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:18:52 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/14 11:02:46 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main( void ) {
	{
		std::cout << "\033[1;32mTest 1\033[0m: span of size 4, filled manually" << std::endl;
		Span	span = Span(4);
		try {
			span.addNumber(42);
			span.addNumber(24);
			span.addNumber(205);
			span.addNumber(485);
			span.addNumber(1);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
		{
		std::cout << std::endl << "\033[1;32mTest 2\033[0m: span of size 10, filled randomly" << std::endl;
		Span	span = Span(10);
		span.fillSpan();
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << "\033[1;32mTest 3\033[0m: span of size 10000, filled randomly" << std::endl;
		Span	span = Span(10000);
		span.fillSpan();
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
}
