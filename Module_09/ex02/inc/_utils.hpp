/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:56:54 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/20 10:07:43 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_CPP
# define UTILS_CPP

# include "PmergeMeVec.hpp"

struct CompairePairs {
	bool	operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const;
};

#endif
