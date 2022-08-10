/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:31:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/25 14:31:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template<typename T>
void print_arr(T& x)
{
    int num = x.size();
    for (int i = 0; i < num; ++i)
    {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
class Array
{
    public:
        Array();
        explicit Array(unsigned int n);
        ~Array();
        Array(const Array<T>& copy);
        Array<T> &operator=(const Array<T>& array);
        unsigned int size() const;
        T& operator[](unsigned int num);
    private:
        T* _data;
        unsigned int _len;
};

#endif