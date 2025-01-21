/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:05:48 by home              #+#    #+#             */
/*   Updated: 2024/03/25 20:12:49 by home             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector <int>tab;
	tab.push_back(1);
	tab.push_back(12);
	tab.push_back(30);
	easyfind(tab, 42);
	easyfind(tab, 30);
	return(0);
}