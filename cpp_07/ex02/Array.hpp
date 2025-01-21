/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imad <imad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:42:48 by home              #+#    #+#             */
/*   Updated: 2024/05/09 16:38:46 by imad             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>


template <typename T>
class Array
{
	public:
		Array() : _n(0)
		{
			this->array = new T [0];
		}
		Array(unsigned int n) : _n(n)
		{
			this->array = new T [_n];
		}
		Array(Array const & src)
		{
			unsigned int i = 0;
			this->_n = src.size();
			this->array = new T [_n];
			while(i < _n)
			{
				this->array[i] = src.array[i];
				i++;
			}
		}
		~Array()
		{
			delete [] array;
		}
		T& 		operator[](unsigned int index)
		{
			if (index >= this->_n)
			{
				std::cout << "Max index is " << _n << std::endl;
				throw Array<T>::NonReachable();
			}
				return (array[index]);
		}
		Array&		operator=(Array const & src)
		{
			this->_n = src.size();
			delete [] array;
			this->array = new T [_n];
			unsigned int i = 0;
			while (i < _n)
			{
				this->array[i] = src.array[i];
				i++;
			}
			return (*this);
		}

		unsigned int	size(void) const
		{
			return (this->_n);
		}

		class NonReachable : public std::exception
		{
			public :
			const char*	what() const throw()
			{
				return ("Target is out of range");
			}
		};
		
		// T&		operator[](unsigned int index) const
		// {
		// 	try
		// 	{
				
		// 		T type = array[index];
		// 		array[index] = type;
		// 	}
		// 	catch(const Array<T>::NonReachable& e)
		// 	{
		// 		std::cerr << e.what() << '\n';
		// 	}
		// 	return (array[index]);
			
		// }


	protected:
		unsigned int	_n;
		T* array;
};

#endif