/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeq.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:14 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/21 18:55:58 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEDEQ_HPP
# define PMERGEMEDEQ_HPP

# include <cstdlib>
# include <iostream>
# include <utility>
# include <algorithm>
# include <functional>
# include <deque>

class PmergeMeDeq {
private:
	int									_numberOfPairs;
	int									_struggler;

	std::deque<std::pair <int, int> >	_pairs;
	std::deque<int>						_mainChain, _pend, _jacobsthalSuite, _insertionIndexes;

	clock_t								_start, _end;

	void						sortPairs( void );
	void						createMainChainAndPend( void );
	void						generateJacobsthalSuite( void );
	void						generateInsertionIndexes( void );
	std::deque<int>::iterator	getPositionInMain( const int& i );
	void						insertPendInMain( void );
	void						insertStruggler( void );

public:
	PmergeMeDeq( int argc, char **argv );
	PmergeMeDeq( const PmergeMeDeq& src );
	PmergeMeDeq& operator=( const PmergeMeDeq& src );
	~PmergeMeDeq();

	void	sort( void );

	int		getSize( void ) const;
	float	getTime( void ) const;

	void	displayAll( void ) const;
	void	displayHead( void ) const;
};

std::ostream&	operator<<(std::ostream& os, const PmergeMeDeq& src);

#endif
