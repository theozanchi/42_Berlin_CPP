/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:32:02 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/05 17:49:44 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

int main( void ) {
	Data*		ptr1 = new Data(42);
	uintptr_t	intptr;
	Data*		ptr2;

	intptr = Serializer::serialize(ptr1);
	std::cout << "Serializer output: " << intptr << std::endl;

	ptr2 = Serializer::deserialize(intptr);
	std::cout << "Deserializer output: " << ptr2->getValue() << std::endl;

	delete ptr1;
	delete ptr2;
}
