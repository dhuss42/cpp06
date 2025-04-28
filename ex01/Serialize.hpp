/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:49:37 by dhuss             #+#    #+#             */
/*   Updated: 2025/04/28 16:30:10 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include "Data.hpp"

/*--------------------------------------------------------------------------------------*/
/* reinterpret_cast 																	*/
/* 	- conversion operator that allows converting one type to another unrelated type		*/
/*	- does not modify the underlying bit representation									*/
/*	- used mainly for pointer conversions												*/
/*--------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------*/
/* Serialization 																				*/
/* 	- process of converting a complex data structure that can be easily stored or transferred	*/
/*	- here it takes a the address of a pointer and converts it to an int representation			*/
/*----------------------------------------------------------------------------------------------*/

/*--------------------------------------------------*/
/* Deserialization 									*/
/* 	- inverse process of serialization				*/
/*	- pointer now refers to original data structure */
/*--------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/* uintptr_t																		*/
/* 	- designed for storing memory addresses in int form								*/
/*	- unsigned integer type that is guaranteed to be large enough to hold a pointer	*/
/* 	- automatically adapts to the architecture 32/64 bits 							*/
/*----------------------------------------------------------------------------------*/

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& src);
		Serializer& operator=(Serializer& other);
		~Serializer();
	public:
		static	uintptr_t	serialize(Data* ptr);
		static	Data*		deserialize(uintptr_t raw);
};

#endif