/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:33:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/23 17:33:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <stdint.h>

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

int main()
{
    Data data;
    data.str = "hello, world";
    data.num = 10;
    Data *ptr = &data;
    std::cout << ptr << " " << ptr->num << " " << ptr->str << std::endl;
    uintptr_t ser = serialize(ptr);
    Data *new_ptr = deserialize(ser);
    std::cout << new_ptr << " " << new_ptr->num << " " << new_ptr->str <<
    std::endl;
    return 0;
}