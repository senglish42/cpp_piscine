/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:44:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/25 14:44:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _data(NULL), _len(0)
{
    std::cout << "Constructor of class template is called." << std::endl;
}

template<typename T>
Array<T>::~Array()
{
    delete[] _data;
    std::cout << "Destructor of class template is called." << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _len(n)
{
    std::cout << "Constructor of class template is called." << std::endl;
    if (_len)
        _data = new T[_len];
    else
        _data = NULL;
}

template<typename T>
Array<T>::Array(const Array<T>& copy)
{
    std::cout << "Copy constructor of class template is called." << std::endl;
    _len = copy._len;
    if (_len)
    {
        _data = new T[_len];
        for(unsigned int i = 0; i < _len; ++i)
            _data[i] = copy._data[i];
    }
    else
        _data = NULL;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T>& array)
{
    if (this == &array)
        return *this;
    delete[] _data;
    _len = array._len;
    if (array._len)
    {
        _data = new T[_len];
        for(unsigned int i = 0; i < _len; ++i)
            _data[i] = array._data[i];
    }
    else
        _data = NULL;
    return *this;
}

template<typename T>
unsigned int Array<T>::size() const
{
    return _len;
}

template<typename T>
T& Array<T>::operator[](unsigned int num)
{
    if (num < 0 || num >= _len)
        throw std::exception();
    return _data[num];
}

#endif