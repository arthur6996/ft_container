/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:15:03 by abourbou          #+#    #+#             */
/*   Updated: 2021/04/12 11:20:09 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <iterator>

int		main(void)
{
	std::vector<int> vect(4);

	std::vector<int>::value_type i = 4;
	std::cout << i << std::endl;
	return (0);
}