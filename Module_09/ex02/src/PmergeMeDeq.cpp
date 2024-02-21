/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeq.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:16 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/21 19:06:00 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeDeq.hpp"

/* Constructors, assignment operator and destructor ************************* */

PmergeMeDeq::PmergeMeDeq( int argc, char **argv ) {
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

PmergeMeDeq::PmergeMeDeq( const PmergeMeDeq& src )
:	_numberOfPairs( src._numberOfPairs ),
	_struggler ( src._struggler )
{
	_pairs = src._pairs;
	_mainChain = src._mainChain;
	_pend = src._pend;
	_jacobsthalSuite = src._jacobsthalSuite;
}

PmergeMeDeq& PmergeMeDeq::operator=( const PmergeMeDeq& src ) {
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

PmergeMeDeq::~PmergeMeDeq() {}

/* Public functions ********************************************************* */

void	PmergeMeDeq::sort( void ) {
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

void	PmergeMeDeq::sortPairs( void ) {
	std::deque<std::pair<int, int> >::iterator	it;
	for (it = _pairs.begin(); it < _pairs.end(); ++it) {
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
	std::sort(_pairs.begin(), _pairs.end());
}

void	PmergeMeDeq::createMainChainAndPend( void ) {
	for (int i = 0; i < _numberOfPairs; ++i) {
		_mainChain.push_back(_pairs[i].first);
		_pend.push_back(_pairs[i].second);
	}
	_mainChain.insert(_mainChain.begin(), _pend[0]);
}

void	PmergeMeDeq::generateJacobsthalSuite( void ) {
	std::deque<int>::iterator	it;
	int							i = 0;
	int							jacobsthal_number = 0;

	for (it = _pend.begin(); jacobsthal_number < static_cast<int>(_pend.size()); ++it, ++i) {
		if (i == 0 || i == 1)
			jacobsthal_number = i;
		else
			jacobsthal_number = _jacobsthalSuite[i - 1] + 2 * _jacobsthalSuite[i - 2];
		_jacobsthalSuite.push_back(jacobsthal_number);
	}
}

void	PmergeMeDeq::generateInsertionIndexes( void ) {
	std::deque<int>::const_iterator	it;
	int									last_jacobsthal = 1;
	for (it = _jacobsthalSuite.begin() + 3; it < _jacobsthalSuite.end(); ++it) {
		for (int i = *it; i > last_jacobsthal; --i) {
			if (i <= static_cast<int>(_pend.size()))
				_insertionIndexes.push_back(i - 1);
		}
		last_jacobsthal = *it;
	}
}

std::deque<int>::iterator	PmergeMeDeq::getPositionInMain( const int& i ) {
	std::deque<int>::iterator	it;
	for (it = _mainChain.begin(); it < _mainChain.end() && *it < i; ++it);
	return (it);
}

void	PmergeMeDeq::insertPendInMain( void ) {
	std::deque<int>::const_iterator	it;
	std::deque<int>::iterator			position_in_main;
	
	for (it = _insertionIndexes.begin(); it < _insertionIndexes.end(); ++it) {
		position_in_main = getPositionInMain(_pend[*it]);	
		_mainChain.insert(position_in_main, _pend[*it]);
	}
}

void	PmergeMeDeq::insertStruggler( void ) {
	if (_struggler > 0) {
		std::deque<int>::iterator	it = getPositionInMain(_struggler);
		_mainChain.insert(it, _struggler);
	}
}

/* Accessors **************************************************************** */

int	PmergeMeDeq::getSize( void ) const { 
	if (!_mainChain.empty())
		return (_mainChain.size());
	else
		return (_struggler == -1 ? _pairs.size() * 2 : _pairs.size() * 2 + 1);
}

float	PmergeMeDeq::getTime( void ) const {
	return (static_cast<float>(_end - _start) / CLOCKS_PER_SEC * 1000);
}

/* Display functions ******************************************************** */

void	PmergeMeDeq::displayAll( void ) const {
	if (!_mainChain.empty()) {
		std::deque<int>::const_iterator	mit;

		for (mit = _mainChain.begin(); mit < _mainChain.end(); ++mit) {
			std::cout << *mit << " ";
		}
	}
	else {
		std::deque<std::pair<int, int> >::const_iterator	pit;

		for (pit = _pairs.begin(); pit < _pairs.end(); ++pit) {
			std::cout << pit->first << " " << pit->second << " ";
		}
		if (_struggler > 0)
			std::cout << _struggler;
	}
}

void	PmergeMeDeq::displayHead( void ) const {
	if (!_mainChain.empty()) {
		std::deque<int>::const_iterator	mit = _mainChain.begin();

		for (int i = 0; i < 4 && mit < _mainChain.end(); ++i, ++mit) {
			std::cout << *mit << " ";
		}
	}
	else {
		std::deque<std::pair<int, int> >::const_iterator	pit = _pairs.begin();

		for (int i = 0; i < 2 && pit < _pairs.end(); ++i, ++pit) {
			std::cout << pit->first << " " << pit->second << " ";
		}
	}
	if (getSize() > 4)
		std::cout << "[...]";
}

/* Redirection operator overload functions ********************************** */

std::ostream&	operator<<(std::ostream& os, const PmergeMeDeq& src) {
	src.displayHead();

	return (os);
}
