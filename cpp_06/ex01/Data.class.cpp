/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:10:54 by iarrar            #+#    #+#             */
/*   Updated: 2024/05/07 16:10:55 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.class.hpp"

Data::Data()
{

}

Data::Data(Data const & src)
{
    *this = src;
}

Data::~Data()
{

}

Data & Data::operator=(Data const & src)
{
    this->member = src.member;
    return (*this);
}
