/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:14 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/22 17:08:06 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstdlib>
# include <iostream>
# include <utility>
# include <algorithm>
# include <functional>
# include <stdexcept>
# include <limits>

template <typename Container, typename Pair>
class PmergeMe {
private:
	int			_struggler;

	Pair		_pairs;
	Container	_mainChain, _pend, _jacobsthalSuite, _insertionIndexes;

	clock_t		_start, _end;

	int								extractAndCheckArg( const char* str );
	static bool						comparePairs( std::pair<int, int>& a, std::pair<int, int>& b);

	void							createMainChainAndPend( void );
	void							generateJacobsthalSuite( void );
	void							generateInsertionIndexes( void );
	typename Container::iterator	getPositionInMain( const int& i );
	void							insertPendInMain( void );
	void							insertStruggler( void );

public:
	PmergeMe();
	PmergeMe( int argc, char **argv );
	PmergeMe( const PmergeMe& src );
	PmergeMe& operator=( const PmergeMe& src );
	~PmergeMe();

	void	sort( void );

	int		getSize( void ) const;
	float	getTime( void ) const;

	void	displayAll( void ) const;
	void	displayHead( void ) const;
};

# include "PmergeMe.tpp"

template <typename Container, typename Pair>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<Container, Pair>& src);

#endif
