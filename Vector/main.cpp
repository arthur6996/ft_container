/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:14:00 by abourbou          #+#    #+#             */
/*   Updated: 2021/04/17 16:29:52 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int		main(void)
{
	//TRUE VECTOR
	std::vector<int> tvect(6);
	if (!tvect.empty())
	{
		for (std::vector<int>::iterator it = tvect.begin(); it != tvect.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	std::cout << tvect.size() << " " << tvect.max_size() << std::endl;
	try
	{
		std::vector<int> tvect2(tvect.end(), tvect.begin());
		if (!tvect2.empty())
		{
			for (std::vector<int>::iterator it = tvect2.begin(); it != tvect2.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//MY VECTOR
	//ft::vector<int>	my_vect(tvect.begin(), tvect.end());
	ft::vector<int>		my_vect(4, 3);

	ft::vector<int>::iterator iter = my_vect.begin();
	std::cout << *(iter += 2);
	*iter = 6;
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = my_vect.begin(); it != my_vect.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return (0);
}