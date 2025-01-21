/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:42:57 by home              #+#    #+#             */
/*   Updated: 2024/03/25 13:43:30 by home             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void	iter(T* array, int size, void(*f)(T))
{
	int i = 0;
	while (i < size)
	{
		f(array[i]);
		i++;
	}
	return ;
}

template <typename T>
void	getT(T t)
{
	std::cout << t << std::endl;
	return;
}


#endif