/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:29:39 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/07 18:42:35 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
void swap(T& a, T& b) {
	T	temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

template <class T>
T min (T a, T b) {
	return (a < b ? a : b);
}

template <class T>
T max (T a, T b) {
	return (a > b ? a : b);
}
