/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:48:48 by dhuss             #+#    #+#             */
/*   Updated: 2025/04/28 14:27:35 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string.h>
#include <sstream>
#include <limits.h>
#include <cmath>
#include "enum.hpp"

/*------------------------------------------------------*/
/* static member function								*/
/* 	can be called even if no obj of the class exists	*/
/*------------------------------------------------------*/

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void		convert(std::string str);
};


#endif