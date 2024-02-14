/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:36:23 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/14 12:33:06 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <class T>
class MutantStack : public std::stack<T> {
private:

public:
	MutantStack();
	MutantStack( const MutantStack<T>& src );
	MutantStack& operator=( const MutantStack<T>& src );
	~MutantStack();

	typedef typename std::deque<T>::iterator iterator;
	iterator	begin();
	iterator	end();
	
	typedef typename std::deque<T>::const_iterator const_iterator;
	const_iterator	cbegin() const;
	const_iterator	cend() const;

	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	reverse_iterator	rbegin();
	reverse_iterator	rend();
	
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator	crbegin() const;
	const_reverse_iterator	crend() const;
};

# include "MutantStack.tpp"

#endif
