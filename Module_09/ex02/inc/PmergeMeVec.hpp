/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:14 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/20 10:28:03 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEVEC_HPP
# define PMERGEMEVEC_HPP

# include <cstdlib>
# include <iostream>
# include <utility>
# include <algorithm>
# include <functional>
# include <vector>

class PmergeMeVec {
private:
	int									_numberOfPairs;
	std::vector<std::pair <int, int> >	_pairs;
	std::vector<int>					_mainChain;
	std::vector<int>					_pend;
	int									_struggler;
	std::vector<int>					_jacobsthalSuite;
	std::vector<int>					_indexesSuite;

	void	sortPairs( void );
	void	createMainChainAndPend( void );
	void	generateJacobsthalSuite( void );

public:
	PmergeMeVec( int argc, char **argv );
	PmergeMeVec( const PmergeMeVec& src );
	PmergeMeVec& operator=( const PmergeMeVec& src );
	~PmergeMeVec();

	void	sort( void );

	void	displayPairs( void ) const;
	void	displayContainers( void ) const;
};

#endif
