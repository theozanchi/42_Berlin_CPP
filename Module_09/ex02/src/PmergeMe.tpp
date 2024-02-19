/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:16 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/19 21:33:17 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* Constructors, assignment operator and destructor ************************* */

template <class Container>
PmergeMe<Container>::PmergeMe( int argc, char **argv ) {
	if (argc % 2 == 0) {
		_numberOfPairs = argc / 2;
		_struggler = -1;
	}
	else {
		_numberOfPairs = (argc - 1) / 2;
		_struggler = atoi(argv[argc - 1]);
	}
	_pairs = new std::pair<int, int>[_numberOfPairs];
	for (int i = 0; i < _numberOfPairs; ++i) {
		_pairs[i] = std::make_pair(atoi(argv[i * 2]), atoi(argv[i * 2 + 1]));
	}
	_jacobsthalSuite = NULL;
}

template <class Container>
PmergeMe<Container>::PmergeMe( const PmergeMe& src )
:	_numberOfPairs( src._numberOfPairs ),
	_struggler ( src._struggler )
{
	_pairs = new std::pair<int, int>[_numberOfPairs];
	for (int i = 0; i < _numberOfPairs; ++i) {
		_pairs[i] = src._pairs[i];
	}
	_mainChain = src._mainChain;
	_pend = src._pend;
}

template <class Container>
PmergeMe<Container>& PmergeMe<Container>::operator=( const PmergeMe& src ) {
	if (this != &src) {
		delete[] _pairs;
		_numberOfPairs = src._numberOfPairs;
		_pairs = new std::pair<int, int>[_numberOfPairs];
		for (int i = 0; i < _numberOfPairs; ++i) {
			_pairs[i] = src._pairs[i];
		}
		_mainChain = src._mainChain;
		_pend = src._pend;
		_struggler = src._struggler;
	}
	return (*this);
}

template <class Container>
PmergeMe<Container>::~PmergeMe() {
	delete[] _pairs;
	if (_jacobsthalSuite)
		delete[] _jacobsthalSuite;
}

/* Public functions ********************************************************* */

template <typename Container>
void	PmergeMe<Container>::sort( void ) {
	sortElementsInPairs();
	sortPairs();
	createMainChainAndPend();
	generateJacobsthalSuite();
}

/* Private functions ******************************************************** */

template <typename Container>
void	PmergeMe<Container>::sortElementsInPairs( void ) {
	for (int i = 0; i < _numberOfPairs; ++i) {
		if (_pairs[i].first < _pairs[i].second)
			std::swap(_pairs[i].first, _pairs[i].second);
	}
}

template <typename Container>
void	PmergeMe<Container>::sortPairs( void ) {
	for (int i = 1; i < _numberOfPairs; ++i) {
		for (int j = i; i > 0 && _pairs[j].first < _pairs[j - 1].first; --j) {
			std::swap(_pairs[j], _pairs[j - 1]);
		}
	}
}

template <typename Container>
void	PmergeMe<Container>::createMainChainAndPend( void ) {
	for (int i = 0; i < _numberOfPairs; ++i) {
		_mainChain.push_back(_pairs[i].first);
		_pend.push_back(_pairs[i].second);
	}
}

template <typename Container>
void	PmergeMe<Container>::generateJacobsthalSuite( void ) {
	int	pend_size = _pend.size();
	if (pend_size < 3)
		pend_size = 3;
	_jacobsthalSuite = new int[pend_size];
	_jacobsthalSuite[0] = 0;
	_jacobsthalSuite[1] = 1;
	for (int i = 2; i < pend_size; ++i) {
		_jacobsthalSuite[i] = _jacobsthalSuite[i - 1] + 2 * _jacobsthalSuite[i - 2];
	}
}

/* Debug functions ********************************************************** */

template <typename Container>
void	PmergeMe<Container>::displayPairs( void ) const {
	for (int i = 0; i < _numberOfPairs; ++i) {
		std::cout << "{ " << _pairs[i].first << " , " << _pairs[i].second << " }" << std::endl;
	}
	if (_struggler > 0)
		std::cout << "{ " << _struggler << " , }" << std::endl;
}

template <typename Container>
void	PmergeMe<Container>::displayContainers( void ) const {
	{
		typename Container::const_iterator it = _mainChain.begin();
		std::cout << "Main chain: ";
		for (it = _mainChain.begin(); it < _mainChain.end(); ++it) {
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
	{
		typename Container::const_iterator it = _pend.begin();
		std::cout << "Pend      : ";
		for (it = _pend.begin(); it < _pend.end(); ++it) {
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
	{
		typename Container::const_iterator it = _pend.begin();
		int i = 0;
		std::cout << "Jacbosthal: ";
		for (it = _pend.begin(); it < _pend.end(); ++i, ++it) {
			std::cout << _jacobsthalSuite[i] << " ";
		}
	}
}
