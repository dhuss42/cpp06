/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:49:24 by dhuss             #+#    #+#             */
/*   Updated: 2025/04/28 16:28:45 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int	main(void)
{
	Data data = {5, 42.2, 5000, 'Z', "test"};

	std::cout << "\033[34m[----------Tests----------]\033[37m" << std::endl;
	std::cout << "\033[33m- Initial Data of struct\033[37m" << std::endl;
	std::cout << "Data struct"
				<< "\n\tint i:\t\t" << data.i
				<< "\n\tfloat f:\t" << data.f
				<< "\n\tdouble d:\t" << data.d
				<< "\n\tchar c:\t\t" << data.c
				<< "\n\tstring s:\t" << data.s
				<< "\n\tAddress: \t" << &data
				<< std::endl;

	std::cout << "\033[33m- Serialized Data Address\033[37m" << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << raw << std::endl;

	std::cout << "\033[33m- Deserialized Data\033[37m" << std::endl;
	Data *data2 = Serializer::deserialize(raw);
	std::cout << "Data struct"
				<< "\n\tint i:\t\t" << data2->i
				<< "\n\tfloat f:\t" << data2->f
				<< "\n\tdouble d:\t" << data2->d
				<< "\n\tchar c:\t\t" << data2->c
				<< "\n\tstring s:\t" << data2->s
				<< "\n\tAddress: \t" << &data2
				<< std::endl;
	return (0);
}
