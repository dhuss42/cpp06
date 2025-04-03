/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:48:48 by dhuss             #+#    #+#             */
/*   Updated: 2025/04/03 08:48:50 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string.h>
#include <sstream>
#include <limits.h>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		enum e_scalar
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			SPECIALDOUBLE,
			SPECIALFLOAT,
			INVALID,
		};

		static double	charConversion(std::string str, int type);
		static double	intConversion(std::string str, int type);
		static double	floatConversion(std::string str, int type);
		static double	doubleConversion(std::string str, int type);
		static int		detectType(std::string str);
		static void		printType(int type);
		static double	initialConversion(std::string str, int type);
		static void 	parsing(std::string str, int& type);
		static void		convert(std::string str);

};


#endif