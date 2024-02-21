/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:14 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/21 19:07:58 by tzanchi          ###   ########.fr       */
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
# include <stdexcept>

class PmergeMeVec {
private:
	int									_numberOfPairs;
	int									_struggler;

	std::vector<std::pair <int, int> >	_pairs;
	std::vector<int>					_mainChain, _pend, _jacobsthalSuite, _insertionIndexes;

	clock_t								_start, _end;

	void						sortPairs( void );
	void						createMainChainAndPend( void );
	void						generateJacobsthalSuite( void );
	void						generateInsertionIndexes( void );
	std::vector<int>::iterator	getPositionInMain( const int& i );
	void						insertPendInMain( void );
	void						insertStruggler( void );

public:
	PmergeMeVec( int argc, char **argv );
	PmergeMeVec( const PmergeMeVec& src );
	PmergeMeVec& operator=( const PmergeMeVec& src );
	~PmergeMeVec();

	void	sort( void );

	int		getSize( void ) const;
	float	getTime( void ) const;

	void	displayAll( void ) const;
	void	displayHead( void ) const;
};

std::ostream&	operator<<(std::ostream& os, const PmergeMeVec& src);

#endif
