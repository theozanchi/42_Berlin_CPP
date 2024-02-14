/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:39:11 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/14 08:48:10 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <class T>
typename T::iterator	easyfind( T& container, const int& i ) {
	return (std::find(container.begin(), container.end(), i));
}
