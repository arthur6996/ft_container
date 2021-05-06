/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:14:00 by abourbou          #+#    #+#             */
/*   Updated: 2021/05/06 16:41:44 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int		main(void)
{
	//TRUE VECTOR
	std::cout << std::endl << "TRUE VECTOR PART " << std::endl << std::endl;
	std::vector<int> tvect(6);

	tvect.resize(4);
	std::cout << tvect[6] << std::endl;
	std::vector<int>::reverse_iterator rev_it = tvect.rbegin();
	rev_it++;
	if (rev_it > tvect.rbegin())
		std::cout << 1;
	else
		std::cout << 0;
	std::cout << std::endl;
	std::cout << &rev_it[0] << " " << &(tvect.rbegin()[0]);

	std::cout << std::endl;
	std::vector<int>::iterator _it = tvect.begin();
	_it++;
	if (_it > tvect.begin())
		std::cout << 1;
	else
		std::cout << 0;
	std::cout << std::endl;
	std::cout << &_it[0] << " " << &(tvect.begin()[0]);

	//MY VECTOR
	std::cout << std::endl << std::endl << "MY VECTOR PART " << std::endl;
	//ft::vector<int>	my_vect(tvect.begin(), tvect.end());
	ft::vector<int>		my_vect(4, 3);

	std::cout << "size " << my_vect.size() << std::endl;
	std::cout << "max_size " << my_vect.max_size() << std::endl;
	my_vect.resize(6);
	for (ft::vector<int>::reverse_iterator it = my_vect.rbegin(); it < my_vect.rend(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = my_vect.begin(); it < my_vect.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << std::endl;
	return (0);
}