/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bases.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:04:19 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/06 09:18:08 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASES_HPP
# define BASES_HPP

class Base {
public:
	virtual ~Base() {}
};

class A : public Base{
};

class B : public Base{
};

class C : public Base{
};

#endif
