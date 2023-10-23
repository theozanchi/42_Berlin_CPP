/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:18:41 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/23 19:30:41 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	size_t	current_size;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(void);
	void	searchContact(void);
};

#endif
