/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:12:20 by iarrar            #+#    #+#             */
/*   Updated: 2024/05/07 16:16:28 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.class.hpp"
#include "A.class.hpp"
#include "C.class.hpp"
#include "Base.class.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>
#include <exception>

Base	*generate()
{
	int a;
	int random;
	time_t *ptr = NULL;

	srand(time(ptr));
	random = rand();
	Base *Base = NULL;
	a = random % 3;
	std::cout << "random = " << random << std::endl;
	std::cout << "a = " << a << std::endl;
	if (a == 0)
		Base = new A();
	else if (a == 1)
		Base = new B();
	else
		Base = new C();
	return (Base);
}

void	identify(Base * p)
{
	A *Alpha = dynamic_cast<A*>(p);
	if (Alpha != NULL)
	{
		std::cout << "*Base is type A" << std::endl;
		return ;
	}
	B *Bravo = dynamic_cast<B*>(p);
	if (Bravo != NULL)
	{
		std::cout << "*Base is type B" << std::endl;
		return;
	}
	C *Charlie = dynamic_cast<C*>(p);
	if (Charlie != NULL)
	{
		std::cout << "*Base is type C" << std::endl;
		return;
	}
	std::cout << "Base is neither A B or C" << std::endl;
	return ;
}

void	identify(Base& p)
{
	try
	{
		A& Alpha = dynamic_cast<A&>(p);
		std::cout << "&Base is type A" << std::endl;
		(void)Alpha;
	}
	catch(const std::exception& e)
	{
		std::cerr << "&Base isn't of type A " << e.what() << std::endl;
	}
	try
	{
		B& Bravo = dynamic_cast<B&>(p);
		std::cout << "&Base is type B" << std::endl;
		(void)Bravo;

	}
	catch(const std::exception& e)
	{
		std::cerr << "&Base isn't of type B " << e.what() << std::endl;
	}
	try
	{
		C& Charlie = dynamic_cast<C&>(p);
		std::cout << "&Base is type C" << std::endl;
		(void)Charlie;
	}
	catch(const std::exception& e)
	{
		std::cerr << "&Base isn't of type C " << e.what() << std::endl;
	}
	
	
}





int main ()
{
	Base *ptr = generate();

	identify(*ptr);
	identify(ptr);
	delete	(ptr);

}