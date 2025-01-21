/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:17:15 by home              #+#    #+#             */
/*   Updated: 2024/03/20 20:02:23 by home             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.class.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
		return (0);
	else
	{
		ScalarConverter::convert(argv[1]);
		return (0);
	}
}