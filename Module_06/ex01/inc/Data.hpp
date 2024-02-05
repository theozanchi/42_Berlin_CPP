/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:36:23 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/05 16:48:10 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data {
private:
	int	_value;

public:
	Data( int value );
	Data( const Data& src );
	Data& operator=( const Data& src );
	~Data();

	const int&	getValue( void ) const;
};

#endif
