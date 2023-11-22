/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:38:40 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/22 21:05:21 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void )
{
	Harl	Harl0;

	Harl0.complain("DEBUG");
	Harl0.complain("INFO");
	Harl0.complain("WARNING");
	Harl0.complain("ERROR");
	Harl0.complain("TEST");

	return (EXIT_SUCCESS);
}
