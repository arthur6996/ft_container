/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:37:15 by abourbou          #+#    #+#             */
/*   Updated: 2021/05/06 17:32:50 by abourbou         ###   ########lyon.fr   */
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
			vector_iterator&	operator=(const vector_iterator& rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			}
			//
			bool		operator==(const vector_iterator other) const
			{
				return (_ptr == other._ptr);
			}
			bool		operator!=(const vector_iterator other) const
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
			bool			operator<(const vector_iterator& rhs) const
			{
				return (_ptr < rhs._ptr);
			}
			bool			operator>(const vector_iterator& rhs) const
			{
				return (_ptr > rhs._ptr);
			}
			bool			operator<=(const vector_iterator& rhs) const
			{
				return (_ptr <= rhs._ptr);
			}
			bool			operator>=(const vector_iterator& rhs) const
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
	class const_vector_iterator
	{

		public:
			typedef typename vector::value_type			value_type;
			typedef typename vector::difference_type	difference_type;
			typedef typename vector::const_pointer		pointer;
			typedef typename vector::const_reference	reference;
			//
			const_vector_iterator(void) : _ptr(0)
			{}
			const_vector_iterator(const const_vector_iterator &rhs) : _ptr(rhs._ptr)
			{}
			const_vector_iterator(pointer c_ptr) : _ptr(c_ptr)
			{}
			~const_vector_iterator(void)
			{}
			const_vector_iterator&	operator=(const const_vector_iterator& rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			}
			//
			bool		operator==(const const_vector_iterator other) const
			{
				return (_ptr == other._ptr);
			}
			bool		operator!=(const const_vector_iterator other) const
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
			const_vector_iterator&	operator++(void)
			{
				_ptr++;
				return (*this);
			}
			const_vector_iterator		operator++(int)
			{
				const_vector_iterator save = *this;
				_ptr++;
				return (save);
			}
			const_vector_iterator&	operator--(void)
			{
				_ptr--;
				return (*this);
			}
			const_vector_iterator		operator--(int)
			{
				const_vector_iterator save = *this;
				_ptr--;
				return (save);
			}
			//
			const_vector_iterator		operator+(difference_type i) const
			{
				return (const_vector_iterator(_ptr + i));
			}
			const_vector_iterator		operator-(difference_type i) const
			{
				return (const_vector_iterator(_ptr - i));
			}
			//
			bool			operator<(const const_vector_iterator& rhs) const
			{
				return (_ptr < rhs._ptr);
			}
			bool			operator>(const const_vector_iterator& rhs) const
			{
				return (_ptr > rhs._ptr);
			}
			bool			operator<=(const const_vector_iterator& rhs) const
			{
				return (_ptr <= rhs._ptr);
			}
			bool			operator>=(const const_vector_iterator& rhs) const
			{
				return (_ptr >= rhs._ptr);
			}
			//
			const_vector_iterator&	operator+=(difference_type i)
			{
				_ptr += i;
				return(*this);
			}
			const_vector_iterator&	operator-=(difference_type i)
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
			typedef ft::vector_iterator<vector >		vector_iterator;
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
			reverse_vector_iterator&	operator=(const reverse_vector_iterator& rhs)
			{
				this->_ptr = rhs._ptr;
				return (*this);
			}
			//
			bool		operator==(const reverse_vector_iterator other) const
			{
				return (this->_ptr == other._ptr);
			}
			bool		operator!=(const reverse_vector_iterator other) const
			{
				return (this->_ptr != other._ptr);
			}
			//
 			reference	operator*(void) const
			{
				return (*this->_ptr);
			}
			reference	operator->(void)
			{
				return (this->_ptr);
			}
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
			//
			bool			operator<(const reverse_vector_iterator& rhs) const
			{
				return (this->_ptr > rhs._ptr);
			}
			bool			operator>(const reverse_vector_iterator& rhs) const
			{
				return (this->_ptr < rhs._ptr);
			}
			bool			operator<=(const reverse_vector_iterator& rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			}
			bool			operator>=(const reverse_vector_iterator& rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			}
			//
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

	template <typename vector>
	class const_reverse_vector_iterator : public const_vector_iterator<vector>
	{
		public:
			typedef ft::const_vector_iterator<vector >		const_vector_iterator;
			typedef typename vector::value_type			value_type;
			typedef typename vector::const_pointer		pointer;
			typedef typename vector::difference_type	difference_type;
			typedef typename vector::const_reference	reference;
			//
			const_reverse_vector_iterator(void) : const_vector_iterator(0)
			{}
			const_reverse_vector_iterator(const const_reverse_vector_iterator &rhs) : const_vector_iterator(rhs._ptr)
			{}
			const_reverse_vector_iterator(pointer c_ptr) : const_vector_iterator(c_ptr)
			{}
			~const_reverse_vector_iterator(void)
			{}
			const_reverse_vector_iterator&	operator=(const const_reverse_vector_iterator& rhs)
			{
				this->_ptr = rhs._ptr;
				return (*this);
			}
			//
			bool		operator==(const const_reverse_vector_iterator other) const
			{
				return (this->_ptr == other._ptr);
			}
			bool		operator!=(const const_reverse_vector_iterator other) const
			{
				return (this->_ptr != other._ptr);
			}
			//
 			reference	operator*(void) const
			{
				return (*this->_ptr);
			}
			reference	operator->(void)
			{
				return (this->_ptr);
			}
			const_reverse_vector_iterator &operator++(void)
			{
				this->_ptr--;
				return (*this);
			}
			const_reverse_vector_iterator operator++(int)
			{
				const_reverse_vector_iterator save(*this);
				this->_ptr--;
				return (save);
			}
			const_reverse_vector_iterator &operator--(void)
			{
				this->_ptr++;
				return (*this);
			}
			const_reverse_vector_iterator operator--(int)
			{
				const_reverse_vector_iterator save(*this);
				this->_ptr++;
				return (save);
			}
			const_reverse_vector_iterator operator+(difference_type i) const
			{
				return (const_reverse_vector_iterator(this->_ptr - i));
			}
			const_reverse_vector_iterator operator-(difference_type i) const
			{
				return (const_reverse_vector_iterator(this->_ptr + i));
			}
			//
			bool			operator<(const const_reverse_vector_iterator& rhs) const
			{
				return (this->_ptr > rhs._ptr);
			}
			bool			operator>(const const_reverse_vector_iterator& rhs) const
			{
				return (this->_ptr < rhs._ptr);
			}
			bool			operator<=(const const_reverse_vector_iterator& rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			}
			bool			operator>=(const const_reverse_vector_iterator& rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			}
			//
			const_reverse_vector_iterator &operator+=(difference_type i)
			{
				this->_ptr -= i;
				return (*this);
			}
			const_reverse_vector_iterator &operator-=(difference_type i)
			{
				this->_ptr += i;
				return (*this);
			}
			const_reverse_vector_iterator &operator[](difference_type i) const
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
			typedef ft::vector_iterator< vector<T> >			iterator;
			typedef ft::const_vector_iterator< vector<T> >		const_iterator;
			typedef ft::reverse_vector_iterator< vector<T> >	reverse_iterator;
			typedef ft::const_reverse_vector_iterator< vector<T> >	const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

		//objects
			pointer		ptr_vect;

		//member functions
			vector(void)
			{
				_data = 0;
				_size = 0;
				_capacity = 0;
			}
			vector(size_type n)
			{
				_size = n;
				_capacity = ALLOC_CAP(n);
				try
				{
					_data = _allocate(_capacity);
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
				_capacity = ALLOC_CAP(n);
				try
				{
					_data = _allocate(_capacity);
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
				_capacity = _size;
				try
				{
					_data = _allocate(_capacity);
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
			//iterators
			iterator	begin(void)
			{
				return (iterator(_data));
			}
			iterator	end(void)
			{
				return (iterator(_data + _size));
			}
			const_iterator	begin(void) const
			{
				return (const_iterator(_data));
			}
			const_iterator	end(void) const
			{
				return (const_iterator(_data + _size));
			}

			reverse_iterator	rbegin(void)
			{
				return (reverse_iterator(_data + _size - 1));
			}
			reverse_iterator	rend(void)
			{
				return(reverse_iterator(_data - 1));
			}

			const_reverse_iterator	rbegin(void) const
			{
				return(const_reverse_iterator(_data + _size - 1));
			}
			const_reverse_iterator	rend(void) const
			{
				return(const_reverse_iterator(_data - 1));
			}

			//Capacity
			size_type	size(void) const
			{
				return (_size);
			}
			size_type	max_size(void) const
			{
				return(_alloc.max_size());
			}
			void	resize(size_type n)
			{
				if (n <= _size)
				{
					_size = n;
				}
				else if (n <= _capacity)
				{
					for (size_type it = _size; it < n; ++it)
					{
						_data[it] = 0;
					}
					_size = n;
				}
				else
				{
					pointer	_new_data = _allocate(ALLOC_CAP(n));
					size_type it = 0;
					for (; it < _size; ++it)
					{
						_new_data[it] = _data[it];
					}
					for(; it < n; ++it)
					{
						_new_data[it] = 0;
					}
					_alloc.deallocate(_data, _capacity);
					_data = _new_data;
					_size = n;
					_capacity = ALLOC_CAP(n);
				}
			}
			void	resize(size_type n, value_type val)
			{
				if (n <= _size)
				{
					_size = n;
				}
				else if (n <= _capacity)
				{
					for (size_type it = _size; it < n; ++it)
					{
						_data[it] = val;
					}
					_size = n;
				}
				else
				{
					pointer	_new_data = _allocate(ALLOC_CAP(n));
					size_type it = 0;
					for (; it < _size; ++it)
					{
						_new_data[it] = _data[it];
					}
					for(; it < n; ++it)
					{
						_new_data[it] = val;
					}
					_alloc.deallocate(_data, _capacity);
					_data = _new_data;
					_size = n;
					_capacity = ALLOC_CAP(n);
				}
			}
			//Element access
			//Modifiers

		protected:
		//exceptions
			class	length_error: public std::exception
			{
				public:
					virtual const char *what(void) const throw()
					{
						return ("length error");
					}
			};
			class	out_of_range: public std::exception
			{
				public:
					virtual const char *what(void) const throw()
					{
						return ("out of range");
					}
			};
		//variables
			pointer		_data;
			size_type	_size;
			size_type	_capacity;
			allocator_type	_alloc;


		private:
			pointer		_allocate(size_type size)
			{
				if (size > this->max_size())
					throw(length_error());
				return (_alloc.allocate(size));
			}
	};
}
//non-member function overloads

#endif