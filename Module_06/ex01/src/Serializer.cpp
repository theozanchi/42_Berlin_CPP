/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:31:52 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/05 16:34:51 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* Member functions ********************************************************* */

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t	intptr;

	intptr = reinterpret_cast<uintptr_t>(ptr);
	return (intptr);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	Data*	ptr;

	ptr = new Data( *reinterpret_cast<int*>(raw) );
	return (ptr);
}
