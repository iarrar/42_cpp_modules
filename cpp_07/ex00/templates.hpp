/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:43:04 by home              #+#    #+#             */
/*   Updated: 2024/03/25 13:43:17 by home             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template <typename T>
void	swap(T & a, T & b)
{
	T cup;
	cup = a;
	a = b;
	b = cup;
}
template <typename T>
T const &	max(T const & a,T const & b)
{
	return(a >= b ? a : b);
}

template <typename T>
T const & min (T const & a, T const & b)
{
	return (a <= b ? a : b);
}

#endif