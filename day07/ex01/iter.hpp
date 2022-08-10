/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:02:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/25 13:02:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void multiply5(T &num)
{
    num *= 5;
}

template <typename T>
void replace56(T &num)
{
    num = 56;
}

template <typename T>
void uppercase(T &sym)
{
    sym = toupper(static_cast<T &>(sym));
}

template <typename T>
void lowercase(T &sym)
{
    sym = tolower(static_cast<T &>(sym));
}

template <typename T>
void print_data(T & x)
{
    std::cout << x << " ";
}

template <typename T>
void iter(T *arr, unsigned int len, void (*f)(T &))
{
    for (unsigned int i = 0; i < len; ++i)
        f(arr[i]);
}

#endif