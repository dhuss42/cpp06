/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:48:57 by dhuss             #+#    #+#             */
/*   Updated: 2025/04/03 08:49:04 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <fstream>

typedef struct s_Data
{
	int			i;
	float		f;
	double		d;
	char		c;
	std::string s;
} Data;

#endif