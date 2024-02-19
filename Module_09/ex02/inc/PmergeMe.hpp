/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:14 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/19 21:13:11 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstdlib>
# include <iostream>
# include <utility>

template <typename Container>
class PmergeMe {
private:
	int						_numberOfPairs;
	std::pair<int, int>*	_pairs;
	Container				_mainChain;
	Container				_pend;
	int						_struggler;
	int*					_jacobsthalSuite;

	void	sortElementsInPairs( void );
	void	sortPairs( void );
	void	createMainChainAndPend( void );
	void	generateJacobsthalSuite( void );

public:
	PmergeMe( int argc, char **argv );
	PmergeMe( const PmergeMe& src );
	PmergeMe& operator=( const PmergeMe& src );
	~PmergeMe();

	void	sort( void );

	void	displayPairs( void ) const;
	void	displayContainers( void ) const;
};

# include "PmergeMe.tpp"

#endif
