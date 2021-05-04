/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:14:00 by abourbou          #+#    #+#             */
/*   Updated: 2021/04/29 16:23:03 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int		main(void)
{
	//TRUE VECTOR
	std::cout << std::endl << "TRUE VECTOR PART " << std::endl << std::endl;
	std::vector<int> tvect(6);

	std::vector<int>::reverse_iterator rev = tvect.rbegin();
	std::cout << "address reverse iterator "  << &rev[0] << std::endl;
	std::cout << "address tvect " << &tvect[5] << std::endl;
	//MY VECTOR
	std::cout << std::endl << std::endl << "MY VECTOR PART " << std::endl;
	//ft::vector<int>	my_vect(tvect.begin(), tvect.end());
	ft::vector<int>		my_vect(4, 3);

	ft::vector<int>::reverse_iterator r_iter = my_vect.rbegin();
	r_iter++;
	*r_iter = 1;
	ft::vector<int>::iterator iter = my_vect.begin();
	iter++;
	for (ft::vector<int>::iterator iter = my_vect.begin();  iter != my_vect.end(); iter++)
	{
		std::cout << *iter << " ";
	}


	std::cout << std::endl;
	return (0);
}