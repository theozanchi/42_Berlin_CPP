/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:16 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/20 10:54:53 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeVec.hpp"
#include "_utils.hpp"

/* Constructors, assignment operator and destructor ************************* */

PmergeMeVec::PmergeMeVec( int argc, char **argv ) {
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

PmergeMeVec::PmergeMeVec( const PmergeMeVec& src )
:	_numberOfPairs( src._numberOfPairs ),
	_struggler ( src._struggler )
{
	_pairs = src._pairs;
	_mainChain = src._mainChain;
	_pend = src._pend;
	_jacobsthalSuite = src._jacobsthalSuite;
}

PmergeMeVec& PmergeMeVec::operator=( const PmergeMeVec& src ) {
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

PmergeMeVec::~PmergeMeVec() {}

/* Public functions ********************************************************* */

void	PmergeMeVec::sort( void ) {
	sortPairs();
	createMainChainAndPend();
	generateJacobsthalSuite();
}

/* Private functions ******************************************************** */

void	PmergeMeVec::sortPairs( void ) {
	std::vector<std::pair<int, int> >::iterator	it;
	for (it = _pairs.begin(); it < _pairs.end(); ++it) {
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
	std::sort(_pairs.begin(), _pairs.end());
}

void	PmergeMeVec::createMainChainAndPend( void ) {
	for (int i = 0; i < _numberOfPairs; ++i) {
		_mainChain.push_back(_pairs[i].first);
		_pend.push_back(_pairs[i].second);
	}
	_mainChain.insert(_mainChain.begin(), _pend[0]);
}

void	PmergeMeVec::generateJacobsthalSuite( void ) {
	std::vector<int>::iterator	it;
	int							i = 0;

	for (it = _pend.begin(); it < _pend.end(); ++it, ++i) {
		if (i == 0 || i == 1)
			_jacobsthalSuite.push_back(i);
		else
			_jacobsthalSuite.push_back(_jacobsthalSuite[i - 1] + 2 * _jacobsthalSuite[i - 2]);
		_indexesSuite.push_back(i);
	}
}

/* Debug functions ********************************************************** */

void	PmergeMeVec::displayPairs( void ) const {
	for (int i = 0; i < _numberOfPairs; ++i) {
		std::cout << "{ " << _pairs[i].first << " , " << _pairs[i].second << " }" << std::endl;
	}
	if (_struggler > 0)
		std::cout << "{ " << _struggler << " , }" << std::endl;
}

void	PmergeMeVec::displayContainers( void ) const {
	{
		std::vector<int>::const_iterator it;
		std::cout << "Main chain: ";
		for (it = _mainChain.begin(); it < _mainChain.end(); ++it) {
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
	{
		std::vector<int>::const_iterator it;
		std::cout << "Pend      : ";
		for (it = _pend.begin(); it < _pend.end(); ++it) {
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
	{
		std::vector<int>::const_iterator it;
		std::cout << "Jacobsthal: ";
		for (it = _jacobsthalSuite.begin(); it < _jacobsthalSuite.end(); ++it) {
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
	{
		std::vector<int>::const_iterator it;
		int i = 0;
		std::cout << "Indexes   : ";
		for (it = _indexesSuite.begin(); it < _indexesSuite.end(); ++i, ++it) {
			std::cout << *it << " ";
		}
	}
}
