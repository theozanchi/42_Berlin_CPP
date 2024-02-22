/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:16 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/22 09:35:21 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* Constructors, assignment operator and destructor ************************* */

template <typename Container, typename Pair>
PmergeMe<Container, Pair>::PmergeMe( int argc, char **argv ) {
	if (argc % 2 == 0) {
		_numberOfPairs = argc / 2;
		_struggler = -1;
	}
	else {
		_numberOfPairs = (argc - 1) / 2;
		_struggler = atoi(argv[argc - 1]);
	}
	for (int i = 0; i < _numberOfPairs; ++i) {
		_pairs.push_back(std::make_pair(atoi(argv[i * 2]), atoi(argv[i * 2 + 1])));
	}
}

template <typename Container, typename Pair>
PmergeMe<Container, Pair>::PmergeMe( const PmergeMe& src )
:	_numberOfPairs( src._numberOfPairs ),
	_struggler ( src._struggler )
{
	_pairs = src._pairs;
	_mainChain = src._mainChain;
	_pend = src._pend;
	_jacobsthalSuite = src._jacobsthalSuite;
}

template <typename Container, typename Pair>
PmergeMe<Container, Pair>& PmergeMe<Container, Pair>::operator=( const PmergeMe& src ) {
	if (this != &src) {
		_numberOfPairs = src._numberOfPairs;
		_pairs = src._pairs;
		_mainChain = src._mainChain;
		_pend = src._pend;
		_struggler = src._struggler;
		_jacobsthalSuite = src._jacobsthalSuite;
	}
	return (*this);
}

template <typename Container, typename Pair>
PmergeMe<Container, Pair>::~PmergeMe() {}

/* Public functions ********************************************************* */

template <typename Container, typename Pair>
void	PmergeMe<Container, Pair>::sort( void ) {
	_start = clock();

	sortPairs();
	createMainChainAndPend();
	generateJacobsthalSuite();
	generateInsertionIndexes();
	insertPendInMain();
	insertStruggler();

	_end = clock();
}

/* Private functions ******************************************************** */

template <typename Container, typename Pair>
void	PmergeMe<Container, Pair>::sortPairs( void ) {
	typename Pair::iterator	it;

	for (it = _pairs.begin(); it < _pairs.end(); ++it) {
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
	std::sort(_pairs.begin(), _pairs.end());
}

template <typename Container, typename Pair>
void	PmergeMe<Container, Pair>::createMainChainAndPend( void ) {
	for (int i = 0; i < _numberOfPairs; ++i) {
		_mainChain.push_back(_pairs[i].first);
		_pend.push_back(_pairs[i].second);
	}
	_mainChain.insert(_mainChain.begin(), _pend[0]);
}

template <typename Container, typename Pair>
void	PmergeMe<Container, Pair>::generateJacobsthalSuite( void ) {
	typename Container::iterator	it;
	int								i = 0;
	int								jacobsthal_number = 0;

	for (it = _pend.begin(); jacobsthal_number < static_cast<int>(_pend.size()); ++it, ++i) {
		if (i == 0 || i == 1)
			jacobsthal_number = i;
		else
			jacobsthal_number = _jacobsthalSuite[i - 1] + 2 * _jacobsthalSuite[i - 2];
		_jacobsthalSuite.push_back(jacobsthal_number);
	}
}

template <typename Container, typename Pair>
void	PmergeMe<Container, Pair>::generateInsertionIndexes( void ) {
	typename Container::const_iterator	it;
	int									last_jacobsthal = 1;

	for (it = _jacobsthalSuite.begin() + 3; it < _jacobsthalSuite.end(); ++it) {
		for (int i = *it; i > last_jacobsthal; --i) {
			if (i <= static_cast<int>(_pend.size()))
				_insertionIndexes.push_back(i - 1);
		}
		last_jacobsthal = *it;
	}
}

template <typename Container, typename Pair>
typename Container::iterator	PmergeMe<Container, Pair>::getPositionInMain( const int& i ) {
	typename Container::iterator	it;

	for (it = _mainChain.begin(); it < _mainChain.end() && *it < i; ++it);
	return (it);
}

template <typename Container, typename Pair>
void	PmergeMe<Container, Pair>::insertPendInMain( void ) {
	typename Container::const_iterator	it;
	typename Container::iterator			position_in_main;
	
	for (it = _insertionIndexes.begin(); it < _insertionIndexes.end(); ++it) {
		position_in_main = getPositionInMain(_pend[*it]);	
		_mainChain.insert(position_in_main, _pend[*it]);
	}
}

template <typename Container, typename Pair>
void	PmergeMe<Container, Pair>::insertStruggler( void ) {
	if (_struggler > 0) {
		typename Container::iterator	it = getPositionInMain(_struggler);
		_mainChain.insert(it, _struggler);
	}
}

/* Accessors **************************************************************** */

template <typename Container, typename Pair>
int	PmergeMe<Container, Pair>::getSize( void ) const { 
	if (!_mainChain.empty())
		return (_mainChain.size());
	else
		return (_struggler == -1 ? _pairs.size() * 2 : _pairs.size() * 2 + 1);
}

template <typename Container, typename Pair>
float	PmergeMe<Container, Pair>::getTime( void ) const {
	return (static_cast<float>(_end - _start) / CLOCKS_PER_SEC * 1000);
}

/* Display functions ******************************************************** */

template <typename Container, typename Pair>
void	PmergeMe<Container, Pair>::displayAll( void ) const {
	if (!_mainChain.empty()) {
		typename Container::const_iterator	mit;

		for (mit = _mainChain.begin(); mit < _mainChain.end(); ++mit) {
			std::cout << *mit << " ";
		}
	}
	else {
		typename Pair::const_iterator	pit;

		for (pit = _pairs.begin(); pit < _pairs.end(); ++pit) {
			std::cout << pit->first << " " << pit->second << " ";
		}
		if (_struggler > 0)
			std::cout << _struggler;
	}
}

template <typename Container, typename Pair>
void	PmergeMe<Container, Pair>::displayHead( void ) const {
	if (!_mainChain.empty()) {
		typename Container::const_iterator	mit = _mainChain.begin();

		for (int i = 0; i < 4 && mit < _mainChain.end(); ++i, ++mit) {
			std::cout << *mit << " ";
		}
	}
	else {
		typename Pair::const_iterator	pit = _pairs.begin();

		for (int i = 0; i < 2 && pit < _pairs.end(); ++i, ++pit) {
			std::cout << pit->first << " " << pit->second << " ";
		}
	}
	if (getSize() > 4)
		std::cout << "[...]";
}

/* Redirection operator overload functions ********************************** */

template <typename Container, typename Pair>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<Container, Pair>& src) {
	src.displayHead();

	return (os);
}
