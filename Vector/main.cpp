/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:14:00 by abourbou          #+#    #+#             */
/*   Updated: 2021/05/06 17:33:22 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int		main(void)
{
	//TRUE VECTOR
	std::cout << std::endl << "TRUE VECTOR PART " << std::endl << std::endl;
	std::vector<int> tvect(4, 3);

	std::cout << "size " << tvect.size() << std::endl;
	std::cout << "max_size " << tvect.max_size() << std::endl;
	tvect.resize(15);
	for (std::vector<int>::reverse_iterator it = tvect.rbegin(); it < tvect.rend(); ++it)
	{
		std::cout << " " << *it;
	}


	//MY VECTOR
	std::cout << std::endl << std::endl << "MY VECTOR PART " << std::endl;
	//ft::vector<int>	my_vect(tvect.begin(), tvect.end());
	ft::vector<int>		my_vect(4, 3);

	std::cout << "size " << my_vect.size() << std::endl;
	std::cout << "max_size " << my_vect.max_size() << std::endl;
	my_vect.resize(15);
	for (ft::vector<int>::reverse_iterator it = my_vect.rbegin(); it < my_vect.rend(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	return (0);
}