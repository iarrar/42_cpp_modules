/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:11:14 by iarrar            #+#    #+#             */
/*   Updated: 2024/05/07 16:11:15 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.class.hpp"

Serialize::Serialize()
{

}

Serialize::Serialize(Serialize const & src)
{
    *this = src;
}

Serialize::~Serialize()
{

}

Serialize & Serialize::operator=(Serialize const & src)
{
    this->i = src.i;
    return (*this);
}

uintptr_t   Serialize::serialize(Data* ptr)
{
    uintptr_t n = reinterpret_cast<uintptr_t>(ptr);
    return (n);
}

Data*   Serialize::deserialize(uintptr_t raw)
{
    Data* ptr;
    ptr = reinterpret_cast<Data*>(raw);
    return(ptr);
}