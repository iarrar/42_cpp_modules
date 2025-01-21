/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imad <imad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:43:26 by home              #+#    #+#             */
/*   Updated: 2024/05/09 16:40:03 by imad             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"
int main()
{
	Array <int>A(10);
	Array <int>B;
	A[3] = 2097;
	Array <int>C(A);
	std::cout << A[3] << std::endl;
	B = A;
	std::cout << B[3] << std::endl;
	B[3] = 1000;
	std::cout << "A[3] = " << A[3] << "\nB[3] = " << B[3] << std::endl;
	Array <int>D;
	try
	{
		D[0] = 90;
		A[11] = 98;
	}
	catch(const Array<int>::NonReachable& e)
	{
		std::cerr << e.what() << '\n';
	}
	
//	std::cout << "non reachable ici : " << A[11] << std::endl;
	std::cout << B[3] << std::endl;
	std::cout << C[3] << std::endl;


}