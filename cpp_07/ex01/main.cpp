/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:43:00 by home              #+#    #+#             */
/*   Updated: 2024/03/25 13:43:18 by home             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "iter.hpp"

int main()
{
	char str[] = "test char";
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	float arrayf[3] = {0.1f, 0.2f, 0.3f};

	std::cout <<"********Test Char*********" << std::endl;
	iter(str, 9, getT);
	std::cout <<"********Test Int*********" << std::endl;
	iter<int>(array, 10, getT);
	std::cout <<"********Test Float*********" << std::endl;
	iter<float>(arrayf, 3, getT);

}