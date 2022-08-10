/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:40:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/23 18:40:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassA.hpp"

A::A(): Base(), _type('A')
{
    std::cout << "A class constructor is called" << std::endl;
}

A::~A()
{
    std::cout << "A class destructor is called" << std::endl;
}

const char &A::getType() const
{
    return this->_type;
}