/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:37:15 by abourbou          #+#    #+#             */
/*   Updated: 2021/04/12 13:30:13 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP


//! need iterator
#include <memory>

namespace ft
{
	template <typename vector>
	class vector_iterator
	{

		public:
			typedef vector::value_type	value_type;
			typedef vector::pointer		pointer;
			typedef vector::reference	reference;

			vector_iterator(pointer ptr) : _ptr(ptr)
			{}
			vector_iterator&	operator++(void)
			{
				_ptr++;
				return (*this);
			}
			vector_iterator&	operator++(int)
			{
				vector_iterator save = *this;
				_ptr++;
				return (save)
			}
			vector_iterator&	operator--(void)
			{
				_ptr--;
				return (*this);
			}
			vector_iterator&	operator--(int)
			{
				vector_iterator save = *this;
				_ptr--;
				return (save)
			}
			reference	operator[](int index) const
			{
				return (*(_ptr + index))
			}
			reference	operator->(void) const
			{
				return (_ptr);
			}
			reference	operator*(void) const
			{
				return (*_ptr);
			}
			bool		operator==(vector_iterator other) const
			{
				return (_ptr == other._ptr);
			}
			bool		operator!=(vector_iterator other) const
			{
				return (_ptr != other._ptr);
			}

	private:
		pointer	_ptr;

	};

	template <typename T>
	class	vector
	{
		public:
		//member types
			typedef T									value_type;
			typedef std::allocator<T>					allocator_type;
			typedef std::allocator<T>::reference		reference;
			typedef std::allocator<T>::const_reference	const_reference;
			typedef std::allocator<T>::pointer			pointer;
			typedef std::allocator<T>::const_pointer	const_pointer;
			typedef vector_iterator<vector<T>>			iterator;
			//typedef iterator							const_iterator;
			//typedef iterator							reverse_iterator;
			//typedef iterator							const_reverse_iterator;
			typedef std::ptrdiff_t						difference_type;
			typedef std::size_t							size_type


		//objects
			pointer		ptr_vect;

		//member functions
			vector(void);
			vector(size_type n);
			vector(size_type n, const value_type& val);
			template <class InputIterator>
			vector(InputIterator first, InputIterator last);
			vector(const vector& x);

			//iterator
			iterator	begin(void)
			{
				return (iterator());
			}
			iterator	end(void)
			{
				return (iterator(_data + _size))
			}

		private:
			pointer		_data;
			size_type	_size;
	};
}


#endif