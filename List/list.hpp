/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:56:34 by abourbou          #+#    #+#             */
/*   Updated: 2021/04/08 17:46:17 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_HPP
# define FT_LIST_HPP

namespace ft
{
	template <typename T>
	class list
	{
		public:
			list(void);
			list(size_type n);
			list(size_type n, const T &val);
		private:
			T	*node;

	};
}

#endif