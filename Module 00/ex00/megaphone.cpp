/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:13:13 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/21 22:14:55 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int word_index = 1; word_index < argc; word_index++)
			for (int char_index = 0; argv[word_index][char_index]; char_index++)
				std::cout << (char)toupper(argv[word_index][char_index]) ;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" ;
	std::cout << std::endl ;
	return (0);
}
