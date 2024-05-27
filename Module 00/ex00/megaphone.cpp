/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:13:13 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/27 12:47:58 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

std::string upper_string(std::string lower_string) {
	std::string upper_string;

	for (int i = 0; i < lower_string[i]; i++)
		upper_string += (char)toupper(lower_string[i]);

	return (upper_string);
}

int main(int argc, char **argv) {
	std::string output;

	if (argc > 1) {
		for (int word_index = 1; word_index < argc; word_index++)
			output.append(upper_string(argv[word_index])).append(" ");
	} else
		output += "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	std::cout << output << std::endl;

	return (0);
}
