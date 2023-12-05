/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:38:40 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/05 13:04:04 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>

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
