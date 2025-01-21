/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:11:05 by iarrar            #+#    #+#             */
/*   Updated: 2024/05/07 16:11:06 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.class.hpp"
#include <iostream>
int main()
{
	Data* ptr = new(Data);
	uintptr_t raw;
	std::cout << "original adress ptr = " << ptr << std::endl;
	raw = Serialize::serialize(ptr);
	std::cout << "raw = " << raw << std::endl;
	std::cout << "Adresse de deserialize : " << Serialize::deserialize(raw) << std::endl;
	delete ptr;
}