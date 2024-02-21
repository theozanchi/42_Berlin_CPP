/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:56:27 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/20 10:08:12 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_utils.hpp"

bool	CompairePairs::operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
	return (a.first > b.first);
}
