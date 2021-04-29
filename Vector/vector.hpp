/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:37:15 by abourbou          #+#    #+#             */
/*   Updated: 2021/04/29 17:20:02 by abourbou         ###   ########lyon.fr   */
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
			typedef typename vector::value_type		value_type;
			typedef typename vector::difference_type difference_type;
			typedef typename vector::pointer		pointer;
			typedef typename vector::reference		reference;
			//
			vector_iterator(void) : _ptr(0)
			{}
			vector_iterator(const vector_iterator &rhs) : _ptr(rhs._ptr)
			{}
			vector_iterator(pointer c_ptr) : _ptr(c_ptr)
			{}
			~vector_iterator(void)
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
			vector_iterator		operator++(int)
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
			vector_iterator		operator--(int)
			{
				vector_iterator save = *this;
				_ptr--;
				return (save);
			}
			//
			vector_iterator		operator+(difference_type i) const
			{
				return (vector_iterator(_ptr + i));
			}
			vector_iterator		operator-(difference_type i) const
			{
				return (vector_iterator(_ptr - i));
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
			vector_iterator&	operator+=(difference_type i)
			{
				_ptr += i;
				return(*this);
			}
			vector_iterator&	operator-=(difference_type i)
			{
				_ptr -= i;
				return(*this);
			}
			//
			reference	operator[](difference_type index) const
			{
				return (*(_ptr + index));
			}

		protected:
			pointer	_ptr;
	};

template <typename vector>
	class reverse_vector_iterator : public vector_iterator<vector>
	{
		public:
			typedef vector_iterator<vector>				vector_iterator;
			typedef typename vector::value_type			value_type;
			typedef typename vector::pointer			pointer;
			typedef typename vector::difference_type	difference_type;
			typedef typename vector::reference			reference;
			//
			reverse_vector_iterator(void) : vector_iterator(0)
			{}
			reverse_vector_iterator(const reverse_vector_iterator &rhs) : vector_iterator(rhs._ptr)
			{}
			reverse_vector_iterator(pointer c_ptr) : vector_iterator(c_ptr)
			{}
			~reverse_vector_iterator(void)
			{}
			reverse_vector_iterator &operator++(void)
			{
				this->_ptr--;
				return (*this);
			}
			reverse_vector_iterator operator++(int)
			{
				reverse_vector_iterator save(*this);
				this->_ptr--;
				return (save);
			}
			reverse_vector_iterator &operator--(void)
			{
				this->_ptr++;
				return (*this);
			}
			reverse_vector_iterator operator--(int)
			{
				reverse_vector_iterator save(*this);
				this->_ptr++;
				return (save);
			}
			reverse_vector_iterator operator+(difference_type i) const
			{
				return (reverse_vector_iterator(this->_ptr - i));
			}
			reverse_vector_iterator operator-(difference_type i) const
			{
				return (reverse_vector_iterator(this->_ptr + i));
			}
			reverse_vector_iterator &operator+=(difference_type i)
			{
				this->_ptr -= i;
				return (*this);
			}
			reverse_vector_iterator &operator-=(difference_type i)
			{
				this->_ptr += i;
				return (*this);
			}
			reverse_vector_iterator &operator[](difference_type i) const
			{
				return (*(this->_ptr - i));
			}
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
			typedef vector_iterator< vector<T> >					iterator;
			//typedef iterator							reverse_iterator;
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
					for (unsigned long i = 0; i < _size; i++)
						_data[i]= val;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
			vector(iterator first, iterator last)
			{
				_size = last - first;
				_alloc_size = _size;
				try
				{
					_data = alloc.allocate(_alloc_size);
					int i = 0;
					for (first; first != last; ++first)
					{
						_data[i] = *first;
						i++;
					}
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			vector(const vector& x);
			~vector(void)
			{
				delete _data;
			}
			//iterator
			iterator	begin(void)
			{
				return (iterator(_data));
			}
			iterator	end(void)
			{
				return (iterator(_data + _size));
			}

		protected:
			pointer		_data;
			size_type	_size;
			size_type	_alloc_size;
			allocator_type	alloc;
	};
}


#endif