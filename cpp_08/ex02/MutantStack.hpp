/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:46:38 by home              #+#    #+#             */
/*   Updated: 2024/03/28 12:34:34 by home             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <deque>
#include <stack>
#include <list>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, std::deque <T> >
{
	public :
		MutantStack()
		{}
		MutantStack(MutantStack const & src) 
		{
			*this = src;
		}
		MutantStack & operator=(MutantStack &src)
		{
			std::stack<T, Container>::operator=(src);
			return(*this);
		}
		~MutantStack() {}

		typedef typename Container::iterator iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}
		iterator	end()
		{
			return (this->c.end());
		}
};







#endif