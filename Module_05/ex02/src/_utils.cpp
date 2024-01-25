/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:24:51 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/25 12:27:31 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_utils.hpp"

std::string	to_string(int value) {
	std::stringstream	ss;

	ss << value;
	return (ss.str());
}
