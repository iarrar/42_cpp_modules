/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:57:40 by home              #+#    #+#             */
/*   Updated: 2024/03/25 21:33:02 by home             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EASYFIND_H
#define EASYFIND_H
#include <algorithm>
#include <iostream>

template <typename T>
void	easyfind(T t, int i)
{
	if (find(t.begin(), t.end(), i) == t.end())
	{
		std::cerr << i << " absang !" << std::endl;
		return ;
	}
	else
		std::cout << i <<  " presang !" << std::endl;
}

#endif