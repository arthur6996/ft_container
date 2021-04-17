/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:37:15 by abourbou          #+#    #+#             */
/*   Updated: 2021/04/17 15:58:47 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP


//! need iterator
#include <memory>
#include <iostream>
//#include <vector>

namespace ft
{
	# define ALLOC_CAP(x) x < std::size_t(8) ? std::size_t(8) : std::size_t(x * 2)

	template <typename vector>
	class vector_iterator
	{

		public:
			typedef typename vector::value_type	value_type;
			typedef typename vector::pointer		pointer;
			typedef typename vector::reference	reference;
			//
			vector_iterator(void) : _ptr(0)
			{}
			vector_iterator(pointer ptr) : _ptr(ptr)
			{}
			vector_iterator&	operator=(vector_iterator& rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			}
			//
			bool		operator==(vector_iterator other) const
			{
				return (_ptr == other._ptr);
			}
			bool		operator!=(vector_iterator other) const
			{
				return (_ptr != other._ptr);
			}
			//
 			reference	operator*(void) const
			{
				return (*_ptr);
			}
			reference	operator->(void)
			{
				return (_ptr);
			}
			//
			vector_iterator&	operator++(void)
			{
				_ptr++;
				return (*this);
			}
			vector_iterator&	operator++(int)
			{
				vector_iterator save = *this;
				_ptr++;
				return (save);
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
				return (save);
			}
			//
			vector_iterator&	operator+(int i)
			{
				_ptr += i;
				return (*this);
			}
			vector_iterator&	operator-(int i)
			{
				_ptr -= i;
				return (*this);
			}
			//
			bool			operator<(vector_iterator& rhs) const
			{
				return (_ptr < rhs._ptr);
			}
			bool			operator>(vector_iterator& rhs) const
			{
				return (_ptr > rhs._ptr);
			}
			bool			operator<=(vector_iterator& rhs) const
			{
				return (_ptr <= rhs._ptr);
			}
			bool			operator>=(vector_iterator& rhs) const
			{
				return (_ptr >= rhs._ptr);
			}
			//
			vector_iterator&	operator+=(int i)
			{
				_ptr += i;
				return(*this);
			}vector_iterator&	operator-=(int i)
			{
				_ptr -= i;
				return(*this);
			}
			//
			reference	operator[](int index) const
			{
				return (*(_ptr + index));
			}

		private:
			pointer	_ptr;
	};

	template <typename T>
	class	vector
	{
		public:
		//member types
			typedef T											value_type;
			typedef std::allocator<T>							allocator_type;
			typedef typename std::allocator<T>::reference		reference;
			typedef typename std::allocator<T>::const_reference	const_reference;
			typedef typename std::allocator<T>::pointer			pointer;
			typedef typename std::allocator<T>::const_pointer	const_pointer;
			typedef vector_iterator<vector<T> >					iterator;
			//typedef iterator							const_iterator;
			//typedef iterator							reverse_iterator;
			//typedef iterator							const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

		//objects
			pointer		ptr_vect;

		//member functions
			vector(void)
			{
				_data = 0;
				_size = 0;
				_alloc_size = 0;
			}
			vector(size_type n)
			{
				_size = n;
				_alloc_size = n;
				try
				{
					_data = alloc.allocate(_alloc_size);
					for (int i = 0; i < _size; i++)
						_data[i]= 0;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			vector(size_type n, const value_type& val)
			{
				_size = n;
				_alloc_size = n;
				try
				{
					_data = alloc.allocate(_alloc_size);
					for (int i = 0; i < _size; i++)
						_data[i]= val;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
			/*
			vector(iterator first, iterator last)
			{
				
			}*/
			vector(const vector& x);

			//iterator
			iterator	begin(void)
			{
				return (iterator(_data));
			}
			iterator	end(void)
			{
				return (iterator(_data + _size));
			}

		private:
			pointer		_data;
			size_type	_size;
			size_type	_alloc_size;
			allocator_type	alloc;
	};
}


#endif