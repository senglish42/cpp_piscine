/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:42:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/23 18:42:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassB.hpp"

B::B(): Base(), _type('B')
{
    std::cout << "B class constructor is called" << std::endl;
}

B::~B()
{
    std::cout << "B class destructor is called" << std::endl;
}

const char &B::getType() const
{
    return this->_type;
}