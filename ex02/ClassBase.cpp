/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBase.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:22:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/23 20:22:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassBase.hpp"

Base::Base()
{
    std::cout << "Base class constructor is called." << std::endl;
}

Base::~Base()
{
    std::cout << "Base class destructor is called." << std::endl;
}