/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:52:53 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 14:23:01 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Brain
{
private:
	std::string	_ideas[100];
	size_t		_index;

public:
	std::string	getIdea( size_t index ) const;
	void		setIdea( std::string idea );

	Brain();
	Brain( const Brain& src );
	Brain& operator=( const Brain &src );
	~Brain();
};
