/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassC.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:43:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/23 18:43:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassC.hpp"

C::C(): Base(), _type('C')
{
    std::cout << "C class constructor is called" << std::endl;
}

C::~C()
{
    std::cout << "C class destructor is called" << std::endl;
}

const char &C::getType() const
{
    return this->_type;
}