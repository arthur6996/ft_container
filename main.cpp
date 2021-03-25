/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:15:03 by abourbou          #+#    #+#             */
/*   Updated: 2021/03/25 12:05:04 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <iterator>

template <typename T>
static void showlist(std::list<T> l)
{
	typename std::list<T>::iterator it;
	for (it = l.begin(); it != l.end(); ++it)
		std::cout << "  " << *it;
	std::cout << std::endl;
}

int		main(void)
{
	std::list<int> i_list;

	i_list.push_back(1);
	i_list.push_back(2);
	i_list.push_front(3);
	showlist<int>(i_list);

	return (0);
};