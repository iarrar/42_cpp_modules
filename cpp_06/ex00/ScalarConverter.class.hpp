/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:10:45 by iarrar            #+#    #+#             */
/*   Updated: 2024/05/07 16:10:47 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>

class ScalarConverter
{
	public:
		virtual				 ~ScalarConverter();
		static void				convert(char *str) ;
		static std::string	&		setParam(char *str);
		static void				CheckType(char *str); 
		static bool		 		IsFloat(char *str) ; 
		static void				PrintFloat(char *str) ;
		static bool		 		IsInt(char *str) ;
		static void				PrintInt(char *str) ;
		static bool				IsDouble(char *str) ;
		static void				PrintDouble(char *str) ;
		static bool				IsChar(char *str) ;
		static void				PrintChar(char *str) ;

	private:
		
		ScalarConverter& 	operator=(ScalarConverter const & src);
							ScalarConverter();
							ScalarConverter(ScalarConverter const & src);
		std::string			_type;
		std::string			_param;

};

#endif